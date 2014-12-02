#ifndef SERIALL_H
#define SERIALL_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>
#include <iostream>
#include "DAO/SerialDAO.h"
#include "Dados/Conexao.h"
#include <LibModBus/modbus-rtu.h>

namespace Ui {
    class Serial;
}

class Serial : public QDialog {
    Q_OBJECT
    
public:
    explicit Serial(QString porta, QWidget *parent = 0);
    explicit Serial(QSqlDatabase conn, QWidget *parent = 0);
    ~Serial();
    void listaPortas();
    bool terminouSetup();
    bool terminouProducao(int quantidadePedida);
    bool setaQuanidadePedida(int quantidadePedida);
    QByteArray solicitaLeituraQtdTotal();
    modbus_t *mbRTU;
    uint16_t tab_reg_32[32];
    uint8_t tab_reg_16[16];


public slots:
    void selecionaPorta(int porta);
    void gravaPortaSerial();
    
private:
    Ui::Serial *ui;
    QSqlDatabase db;
    QSerialPort portaSelecionada;
    QList <QString> listaDePortas;
    QList <QSerialPortInfo> listaDePortasSeriais;
};

#endif // SERIALL_H
