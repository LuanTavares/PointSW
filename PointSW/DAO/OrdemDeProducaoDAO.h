#ifndef ORDEMDEPRODUCAODAO_H
#define ORDEMDEPRODUCAODAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Dados\Conexao.h"
#include "Dados\OrdemDeProducao.h"
#include "Dados\Cliente.h"
#include "ClienteDAO.h"
#include "Dados\Maquina.h"
#include "MaquinaDAO.h"
class OrdemDeProducaoDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
public:
    OrdemDeProducaoDAO(QSqlDatabase conn);
    QList<OrdemDeProducao *> getOPs();
    OrdemDeProducao * getOP(QString op);
    bool insereOP(OrdemDeProducao op);
    bool atualizaOP(OrdemDeProducao op);
    bool deletaOP(OrdemDeProducao op);
};

#endif // ORDEMDEPRODUCAODAO_H
