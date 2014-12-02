#ifndef CLIENTEDAO_H
#define CLIENTEDAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Dados\Conexao.h"
#include "Dados\Cliente.h"
class ClienteDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
public:
    ClienteDAO(QSqlDatabase conn);
    QList <Cliente> getClientes();
    Cliente * getCliente(int codigoCliente);
    bool insereCliente(Cliente cli);
    bool atualizaCliente(Cliente cli);
    bool deletaCliente(Cliente cli);
};

#endif // CLIENTEDAO_H
