#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include <QPushButton>
#include "OrdemDeProducaoDAO.h"
#include "TelaDeSetup.h"
#include "TelaDeProducao.h"
#include "Usuario.h"
#include "Serial.h"
#include "ParadasDAO.h"
#include "SerialDAO.h"

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
    TelaDeProducao * tempoDeProducao;
    Setup * setup;
    Producao * producao;
    Usuario * usuAtu;
    QList <OrdemDeProducao *> ops;
    QList <QPushButton *> botoes;
    Serial * portaDeComunicacao;
    QTimer * leDadosImpressora;
    QList <Parada> paradas;

    QList <Parada> retornaParadasSemMotivo();

public slots:
    void startaTempoDeSetup();
    void startaTempoDeProducao();
    void carrgaFilaDeProducao();
    void atualizaTempoDeSetup(QTime tempo);
    void atualizaTempoDeProducao(QTime tempo);
    void selecionaPortaSerial();
    void leDados();
};

#endif // TELAPRINCIPAL_H
