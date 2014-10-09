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
        portaSelecionada.setBaudRate(QSerialPort::Baud115200);
        portaSelecionada.setDataBits(QSerialPort::Data8);
        portaSelecionada.setParity(QSerialPort::NoParity);
        portaSelecionada.setStopBits(QSerialPort::OneStop);
        if (portaSelecionada.open(QIODevice::ReadWrite)) {
            portaSelecionada.close();
        }
    }

    connect(ui->comboBoxPortasSeriais, SIGNAL(currentIndexChanged(int)),this,SLOT(selecionaPorta(int)));

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
    portaSelecionada.setBaudRate(QSerialPort::Baud115200);
    portaSelecionada.setDataBits(QSerialPort::Data8);
    portaSelecionada.setParity(QSerialPort::NoParity);
    portaSelecionada.setStopBits(QSerialPort::OneStop);
    if (portaSelecionada.open(QIODevice::ReadWrite)) {
        portaSelecionada.close();
    }
}

QByteArray Serial::solicitaleitura(int endereco, int qtdRegistros) {
    QByteArray retorno;
    retorno.clear();

    if (portaSelecionada.open(QIODevice::ReadWrite)) {

        QString enderecoASerLido;
        enderecoASerLido.setNum(endereco,16);

        QString qtdRegistrosASeremLidos;
        qtdRegistrosASeremLidos.setNum(qtdRegistros,16);

        QByteArray solicitacao;
        solicitacao = "TX:0103"+enderecoASerLido.toLatin1()+qtdRegistrosASeremLidos.toLatin1()+"CRCCRC";
        portaSelecionada.write(solicitacao);
        //qDebug() << solicitacao;

        retorno = portaSelecionada.readAll();
        //qDebug() << retorno;

        ui->labelPortaSeriais->setText(QString(retorno));
    }
    return retorno;
}

