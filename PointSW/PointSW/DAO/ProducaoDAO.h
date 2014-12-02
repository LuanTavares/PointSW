#ifndef PRODUCAODAO_H
#define PRODUCAODAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Dados\Conexao.h"
#include "Dados\Producao.h"
#include "Dados\Maquina.h"
#include "MaquinaDAO.h"
#include "Dados\OrdemDeProducao.h"
#include "OrdemDeProducaoDAO.h"
#include "Dados\Usuario.h"
#include "UsuarioDAO.h"
class ProducaoDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
    Conexao * conn;
public:
    ProducaoDAO(QSqlDatabase conn);
    QList <Producao> getProducao();
    bool insereProducao(Producao producao);
    bool atualizaProducao(Producao producao);
    bool deletaProducao(Producao producao);
    bool existeEstaProducao(Producao * pro);
};

#endif // PRODUCAODAO_H
