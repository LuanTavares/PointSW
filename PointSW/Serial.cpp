#include "Serial.h"
#include "ui_Serial.h"
#include <QDebug>

Serial::Serial(QString porta, QWidget *parent) : QDialog(parent), ui(new Ui::Serial) {
    ui->setupUi(this);
    if (!porta.size() > 0) {
        listaPortas();
        listaDePortas.push_front(" ");
        for (int i=0;i < listaDePortas.size(); i++) {
            ui->comboBoxPortasSeriais->addItem(listaDePortas.at(i));
        }
    } else {
        portaSelecionada.setPortName(porta);
        portaSelecionada.setBaudRate(QSerialPort::Baud19200);
        portaSelecionada.setDataBits(QSerialPort::Data8);
        portaSelecionada.setParity(QSerialPort::NoParity);
        portaSelecionada.setStopBits(QSerialPort::TwoStop);
        if (portaSelecionada.open(QIODevice::ReadWrite)) {
            portaSelecionada.close();
        }
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
    portaSelecionada.setBaudRate(QSerialPort::Baud19200);
    portaSelecionada.setDataBits(QSerialPort::Data8);
    portaSelecionada.setParity(QSerialPort::NoParity);
    portaSelecionada.setStopBits(QSerialPort::TwoStop);
    if (portaSelecionada.open(QIODevice::ReadWrite)) {
        portaSelecionada.close();
    }
}

void Serial::gravaPortaSerial() {
    // Implementar gravação no banco de dados.
    this->close();
}

QByteArray Serial::solicitaleitura(int endereco, int funcao, int registroInicial, int qtdRegistros) {
    QByteArray retorno;
    retorno.clear();


    if (portaSelecionada.open(QIODevice::ReadWrite)) {

        QDataStream dialogDataStream(&retorno, QIODevice::WriteOnly);
        dialogDataStream.setByteOrder(QDataStream::LittleEndian);
        dialogDataStream << quint8(endereco) << quint8(funcao) << quint16(registroInicial) << quint16(qtdRegistros);
        dialogDataStream << quint16(qChecksum(retorno.constData(),retorno.size()));

        portaSelecionada.write(retorno);
        qDebug() << retorno;

        retorno = portaSelecionada.readAll();
        qDebug() << retorno;

        //ui->labelPortaSeriais->setText(QString(retorno));
    }
    return retorno;
}
