#ifndef SERIALL_H
#define SERIALL_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>
#include <iostream>

namespace Ui {
    class Serial;
}

class Serial : public QDialog {
    Q_OBJECT
    
public:
    explicit Serial(QString porta, QWidget *parent = 0);
    ~Serial();
    void listaPortas();
    QByteArray solicitaleitura(int endereco, int funcao, int registroInicial, int qtdRegistros);

public slots:
    void selecionaPorta(int porta);
    void gravaPortaSerial();
    
private:
    Ui::Serial *ui;
    QSerialPort portaSelecionada;
    QList <QString> listaDePortas;
    QList <QSerialPortInfo> listaDePortasSeriais;
};

#endif // SERIALL_H
