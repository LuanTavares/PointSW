#ifndef ORDEMDEPRODUCAODAO_H
#define ORDEMDEPRODUCAODAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Conexao.h"
#include "OrdemDeProducao.h"
#include "Cliente.h"
#include "ClienteDAO.h"
#include "Maquina.h"
#include "MaquinaDAO.h"
class OrdemDeProducaoDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
    Conexao * conn;
public:
    OrdemDeProducaoDAO(Conexao * conn);
    QList <OrdemDeProducao> getOPs();
    bool insereOP(OrdemDeProducao op);
    bool atualizaOP(OrdemDeProducao op);
    bool deletaOP(OrdemDeProducao op);
};

#endif // ORDEMDEPRODUCAODAO_H
