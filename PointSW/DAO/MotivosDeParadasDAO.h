#ifndef MOTIVOSDEPARADASDAO_H
#define MOTIVOSDEPARADASDAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Dados\Conexao.h"
#include "Dados\MotivosDeParadas.h"
class MotivosDeParadasDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
public:
    MotivosDeParadasDAO(QSqlDatabase conn);
    QList <MotivosDeParadas *> getMotivos();
    MotivosDeParadas * getMotivoDeParadas(int mot);
};

#endif // MOTIVOSDEPARADASDAO_H
