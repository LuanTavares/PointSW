#ifndef PRODUCAODAO_H
#define PRODUCAODAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Conexao.h"
#include "Producao.h"
#include "Maquina.h"
#include "MaquinaDAO.h"
#include "OrdemDeProducao.h"
#include "OrdemDeProducaoDAO.h"
#include "Usuario.h"
#include "UsuarioDAO.h"
class ProducaoDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
    Conexao * conn;
public:
    ProducaoDAO(Conexao * conn);
    QList <Producao> getProducao();
    bool insereProducao(Producao producao);
    bool atualizaProducao(Producao producao);
    bool deletaProducao(Producao producao);
};

#endif // PRODUCAODAO_H
