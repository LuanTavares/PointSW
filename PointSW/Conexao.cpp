#include "Conexao.h"

Conexao::Conexao() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("PointSw");
    db.setUserName("sa");
    db.setPassword("simulasql");
    //db.setUserName("pointswuser");
    //db.setPassword("@point_sw123");
}

QSqlDatabase Conexao::getDataBase(){
    return db;
}
