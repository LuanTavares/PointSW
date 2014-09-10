#ifndef SETUPDAO_H
#define SETUPDAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Conexao.h"
#include "Setup.h"
#include "Maquina.h"
#include "MaquinaDAO.h"
#include "OrdemDeProducao.h"
#include "OrdemDeProducaoDAO.h"
#include "Usuario.h"
#include "UsuarioDAO.h"
class SetupDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
    Conexao * conn;
public:
    SetupDAO(Conexao * conn);
    QList <Setup> getSetup();
    bool insereSetup(Setup setup);
    bool atualizaSetup(Setup setup);
    bool deletaSetup(Setup setup);
};

#endif // SETUPDAO_H
