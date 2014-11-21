#ifndef SETUPDAO_H
#define SETUPDAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Dados\Conexao.h"
#include "Dados\Setup.h"
#include "Dados\Maquina.h"
#include "MaquinaDAO.h"
#include "Dados\OrdemDeProducao.h"
#include "OrdemDeProducaoDAO.h"
#include "Dados\Usuario.h"
#include "UsuarioDAO.h"
class SetupDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
    Conexao * conn;
public:
    SetupDAO(QSqlDatabase conn);
    QList <Setup> getSetups();
    Setup *getSetup(Maquina * maq, OrdemDeProducao * op, Usuario * usu);
    bool existeEsteSetup(Setup * set);
    bool insereSetup(Setup setup);
    bool atualizaSetup(Setup setup);
    bool deletaSetup(Setup setup);
};

#endif // SETUPDAO_H
