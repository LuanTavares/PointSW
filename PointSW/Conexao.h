#ifndef CONEXAO_H
#define CONEXAO_H
#include <QtWidgets>
#include <QtSql>

class Conexao {
public:
    Conexao();
    ~Conexao();
    QSqlDatabase getDataBase();
private:
    QSqlDatabase db;
};

#endif // CONEXAO_H
