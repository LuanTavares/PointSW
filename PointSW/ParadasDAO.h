#ifndef PARADASDAO_H
#define PARADASDAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Conexao.h"
#include "Paradas.h"
#include "Maquina.h"
#include "MaquinaDAO.h"
#include "OrdemDeProducao.h"
#include "OrdemDeProducaoDAO.h"
#include "Usuario.h"
#include "UsuarioDAO.h"
#include "MotivosDeParadas.h"
#include "MotivosDeParadasDAO.h"
class ParadasDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
    Conexao * conn;
public:
    ParadasDAO(QSqlDatabase conn);
    QList <Parada> getParada();
    QList<Parada *> getParadasSemMotivo();
    bool insereParada(Parada parada);
    bool atualizaParada(Parada parada);
    bool deletaParada(Parada parada);
};

#endif // PARADASDAO_H
