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
    QTimer * atualizaTempoDeSetupTela;
    Setup * setup;
    QSqlDatabase db;
    int qtd;
    QTime dialogTime;

public slots:
    void gravaSetup();
    void finalizaSetup();
    void atualizaTela();
};

#endif // TELASETUP_H
