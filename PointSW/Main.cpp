#include <QtWidgets>
#include <iostream>
#include "TelaDeLogin.h"

int main(int argc,char* argv[]) {

    QApplication * app = new QApplication(argc,argv);

    TelaDeLogin * teste = new TelaDeLogin();

    teste->show();


    app->exec();
}

