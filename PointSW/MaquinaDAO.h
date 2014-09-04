#ifndef MAQUINADAO_H
#define MAQUINADAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Conexao.h"
#include "Maquina.h"
class MaquinaDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
public:
    MaquinaDAO(Conexao * conn);
    QList <Maquina> getMaquinas();
    Maquina * getMaquina(int codigoMaquina);
    bool insereMaquina(Maquina maq);
    bool atualizaMaquina(Maquina maq);
    bool deletaMaquina(Maquina maq);
};

#endif // MAQUINADAO_H
