#ifndef APONTAMENTODAO_H
#define APONTAMENTODAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Dados\Conexao.h"
#include "Dados\Apontamento.h"
#include "Dados\Maquina.h"
#include "MaquinaDAO.h"
#include "Dados\OrdemDeProducao.h"
#include "OrdemDeProducaoDAO.h"
#include "Dados\Usuario.h"
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
