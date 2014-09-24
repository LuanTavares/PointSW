#ifndef APONTAMENTODAO_H
#define APONTAMENTODAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Conexao.h"
#include "Apontamento.h"
#include "Maquina.h"
#include "MaquinaDAO.h"
#include "OrdemDeProducao.h"
#include "OrdemDeProducaoDAO.h"
#include "Usuario.h"
#include "UsuarioDAO.h"
class ApontamentoDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
    Conexao * conn;
public:
    ApontamentoDAO(QSqlDatabase conn);
    QList <Apontamento> getApontamento();
    bool insereApontamento(Apontamento apontamento);
    bool atualizaApontamento(Apontamento apontamento);
    bool deletaApontamento(Apontamento apontamento);
};

#endif // APONTAMENTODAO_H
