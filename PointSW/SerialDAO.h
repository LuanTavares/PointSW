#ifndef SERIALDAO_H
#define SERIALDAO_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Conexao.h"

class SerialDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
    Conexao * conn;
    QString hostName;
public:
    SerialDAO(QSqlDatabase conn);
    QString getPortaSerial();
    bool setPortaSerial(QString porta);
};

#endif // SERIALDAO_H
