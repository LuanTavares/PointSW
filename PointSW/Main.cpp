#include <QtWidgets>
#include "Conexao.h"
#include <iostream>

int main(int argc,char* argv[]) {

    QApplication * app = new QApplication(argc,argv);

    Conexao * con = new Conexao();
    QSqlDatabase db = con->getDataBase();
    if (db.open()) {
        std::cout << "Conectou" << std::endl;
        db.close();
    } else {
        std::cout << "Não Conectou" << std::endl;
    }

    app->exec();
}

