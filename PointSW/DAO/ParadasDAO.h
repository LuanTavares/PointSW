#ifndef PARADASDAO_H
#define PARADASDAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Dados\Conexao.h"
#include "Dados\Paradas.h"
#include "Dados\Maquina.h"
#include "MaquinaDAO.h"
#include "Dados\OrdemDeProducao.h"
#include "OrdemDeProducaoDAO.h"
#include "Dados\Usuario.h"
#include "UsuarioDAO.h"
#include "Dados\MotivosDeParadas.h"
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
