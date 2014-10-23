#ifndef TELADESETUP_H
#define TELADESETUP_H
#include <QWidget>
#include <QTimer>
#include "SetupDAO.h"
class TelaDeSetup : public QWidget  {

    Q_OBJECT

public:
    TelaDeSetup(Setup * setup, QSqlDatabase conn);
    ~TelaDeSetup();
private:
    QTimer * gravaTempoSetup;
    QTimer * atualizaTempoDeSetupTela;
    Setup * setup;
    QSqlDatabase db;
    int qtd;
    QTime tempoDeStup;

public slots:
    void gravaSetup();
    void atualizaTela();
    void acabouSetup();

signals:
    void atualizaTelaPrincipal(QTime tempo);

};

#endif // TELADESETUP_H
