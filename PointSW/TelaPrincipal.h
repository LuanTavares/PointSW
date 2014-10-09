#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include <QPushButton>
#include "OrdemDeProducaoDAO.h"
#include "TelaDeSetup.h"
#include "Usuario.h"
#include "Serial.h"

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
    TelaDeSetup * tempoDeSetup;
    Setup * setup;
    Usuario * usuAtu;
    QList <OrdemDeProducao *> ops;
    Serial * portaDeComunicacao;

public slots:
    void startaTempoDeSetup();
    void carrgaFilaDeProducao();
    void atualizaTempoDeSetup(QTime tempo);
    void selecionaPortaSerial();
};

#endif // TELAPRINCIPAL_H
