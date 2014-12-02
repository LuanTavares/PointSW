#include "Serial.h"
#include "ui_Serial.h"
#include <QDebug>

Serial::Serial(QString porta, QWidget *parent) : QDialog(parent), ui(new Ui::Serial) {
    ui->setupUi(this);
    portaSelecionada.setPortName(porta);
    portaSelecionada.setBaudRate(QSerialPort::Baud19200);
    portaSelecionada.setDataBits(QSerialPort::Data8);
    portaSelecionada.setParity(QSerialPort::NoParity);
    portaSelecionada.setStopBits(QSerialPort::TwoStop);
    if (portaSelecionada.open(QIODevice::ReadWrite)) {
        portaSelecionada.close();
    }

    connect(ui->comboBoxPortasSeriais, SIGNAL(currentIndexChanged(int)),this,SLOT(selecionaPorta(int)));
    connect(ui->pushButtonSalvar, SIGNAL(clicked()), SLOT(gravaPortaSerial()));

}

Serial::Serial(QSqlDatabase conn, QWidget *parent) : QDialog(parent), ui(new Ui::Serial) {
    ui->setupUi(this);
    this->db = conn;    
    listaPortas();
    ui->comboBoxPortasSeriais->addItem(" ");
    for (int i=0;i < listaDePortas.size(); i++) {
        ui->comboBoxPortasSeriais->addItem(listaDePortas.at(i));
    }

    connect(ui->comboBoxPortasSeriais, SIGNAL(currentIndexChanged(int)),this,SLOT(selecionaPorta(int)));
    connect(ui->pushButtonSalvar, SIGNAL(clicked()), SLOT(gravaPortaSerial()));


}

Serial::~Serial() {
    delete ui;
}

void Serial::listaPortas() {
    int i = 0;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QString dialogStr = info.portName();
        listaDePortasSeriais.insert(i,info);
        listaDePortas.insert(i,dialogStr);
        i++;
    }
}

void Serial::selecionaPorta(int porta) {
    portaSelecionada.setPort(listaDePortasSeriais.at(porta-1));
    portaSelecionada.setBaudRate(QSerialPort::Baud9600);
    portaSelecionada.setDataBits(QSerialPort::Data8);
    portaSelecionada.setParity(QSerialPort::NoParity);
    portaSelecionada.setStopBits(QSerialPort::OneStop);
    if (portaSelecionada.open(QIODevice::ReadWrite)) {
        portaSelecionada.close();
    }
}

void Serial::gravaPortaSerial() {
    SerialDAO * dialogDAO = new SerialDAO(db);
    dialogDAO->setPortaSerial(portaSelecionada.portName());
    this->close();
}

QByteArray Serial::solicitaLeituraQtdTotal() {
    mbRTU = modbus_new_rtu(portaSelecionada.portName().toStdString().c_str(),9600,'N',8,1);
    modbus_set_debug(mbRTU, TRUE);
    modbus_rtu_set_serial_mode(mbRTU, MODBUS_RTU_RS232);
    modbus_set_slave(mbRTU, 1);

    QByteArray retorno;
    modbus_connect(mbRTU);
    // Le o registro na posição 40005, 4 por que 400 é automático e 4 por que é o 5 registro, 0,1,2,3,4
    modbus_read_registers(mbRTU, 4, 1, tab_reg_32);
    retorno.insert(0,tab_reg_32[0]);

    modbus_close(mbRTU);
    modbus_free(mbRTU);
}

bool Serial::terminouSetup() {
    mbRTU = modbus_new_rtu(portaSelecionada.portName().toStdString().c_str(),9600,'N',8,1);
    modbus_set_debug(mbRTU, FALSE);
    modbus_rtu_set_serial_mode(mbRTU, MODBUS_RTU_RS232);
    modbus_set_slave(mbRTU, 1);

    bool retorno = false;

    modbus_connect(mbRTU);

    modbus_read_bits(mbRTU, 2, 1, tab_reg_16);
    //std::cout << "Valor: " << tab_reg_16[0] << std::endl;
    if (tab_reg_16[0] == 1) {
        retorno = true;
    } else {
        retorno = false;
    }

    modbus_close(mbRTU);
    modbus_free(mbRTU);

    return retorno;
}

bool Serial::terminouProducao(int quantidadePedida) {
    mbRTU = modbus_new_rtu(portaSelecionada.portName().toStdString().c_str(),9600,'N',8,1);
    modbus_set_debug(mbRTU, FALSE);
    modbus_rtu_set_serial_mode(mbRTU, MODBUS_RTU_RS232);
    modbus_set_slave(mbRTU, 1);

    bool retorno = false;
    tab_reg_16[0] = 0;

    modbus_connect(mbRTU);

    // Busca se a introdução ainda está ativa
    modbus_read_bits(mbRTU, 2, 1, tab_reg_16);
    //std::cout << "Valor: " << tab_reg_16[0] << std::endl;

    // Busca a quantidade Produzida
    modbus_read_registers(mbRTU,4,1,tab_reg_32);

    if (tab_reg_16[0] == 0) {
        retorno = false;
        int quantidadeProduzida = tab_reg_32[0];
        std::cout << "Quantidade Produzida: " << tab_reg_32[0] << " Quantidade Pedida " << quantidadePedida << std::endl;
        if (quantidadeProduzida >= quantidadePedida) {
            retorno = true;
        }
    } else {
        retorno = false;
    }

    modbus_close(mbRTU);
    modbus_free(mbRTU);

    return retorno;
}

bool Serial::setaQuanidadePedida(int quantidadePedida) {
    mbRTU = modbus_new_rtu(portaSelecionada.portName().toStdString().c_str(),9600,'N',8,1);
    modbus_set_debug(mbRTU, TRUE);
    modbus_rtu_set_serial_mode(mbRTU, MODBUS_RTU_RS232);
    modbus_set_slave(mbRTU, 1);

    modbus_connect(mbRTU);

    modbus_write_register(mbRTU,4,0);
    modbus_write_register(mbRTU,6,quantidadePedida);
    modbus_write_register(mbRTU,8,0);
    modbus_close(mbRTU);
    modbus_free(mbRTU);


    return true;
}

