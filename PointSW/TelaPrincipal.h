#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>
#include <QPushButton>
#include "DAO/OrdemDeProducaoDAO.h"
#include "TelaDeSetup.h"
#include "TelaDeProducao.h"
#include "TelaDeParada.h"
#include "Dados/Usuario.h"
#include "Serial.h"
#include "DAO/ParadasDAO.h"
#include "DAO/SerialDAO.h"

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
    QList <Parada *> paradas;
    bool estaNoSetup;
    bool estaNaProducao;

public slots:
    void startaTempoDeSetup();
    void startaTempoDeProducao();
    void carrgaFilaDeProducao();
    void atualizaTempoDeSetup(QTime tempo);
    void atualizaTempoDeProducao(QTime tempo);
    void selecionaPortaSerial();
    void leDados();
    void procuraParadasSemMotivos();
};

#endif // TELAPRINCIPAL_H
