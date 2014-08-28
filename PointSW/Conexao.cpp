#include "Conexao.h"

Conexao::Conexao() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("PointSw");
    db.setUserName("sopasta_ti");
    db.setPassword("0@e38+aem/ti");
}

QSqlDatabase Conexao::getDataBase(){
    return db;
}
