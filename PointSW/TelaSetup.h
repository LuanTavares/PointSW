#ifndef TELASETUP_H
#define TELASETUP_H

#include <QWidget>
#include <QTimer>
#include "SetupDAO.h"
namespace Ui {
    class TelaSetup;
}

class TelaSetup : public QWidget {
    Q_OBJECT
    
public:
    explicit TelaSetup(Setup * setup, QSqlDatabase conn, QWidget *parent = 0);
    ~TelaSetup();
    
private:
    Ui::TelaSetup *ui;
    QTimer * tempoDeSetup;
    Setup * setup;
    QSqlDatabase db;
    int qtd;

public slots:
    void gravaSetup();
    void finalizaSetup();
};

#endif // TELASETUP_H
