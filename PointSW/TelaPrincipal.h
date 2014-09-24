#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include "OrdemDeProducaoDAO.h"
#include "TelaSetup.h"
#include "Usuario.h"
namespace Ui {
    class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow {
    Q_OBJECT
    
public:
    explicit TelaPrincipal(Usuario * usuAtu, QSqlDatabase conn, QWidget *parent = 0);
    ~TelaPrincipal();
    
private:
    Ui::TelaPrincipal *ui;
    OrdemDeProducaoDAO *opDAO;
    QSqlDatabase db;
    TelaSetup * tempoDeSetup;
    Setup * setup;
    Usuario * usuAtu;
    QList <OrdemDeProducao *> ops;

public slots:
    void startaTempoDeSetup();
};

#endif // TELAPRINCIPAL_H
