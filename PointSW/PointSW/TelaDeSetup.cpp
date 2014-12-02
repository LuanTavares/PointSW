#include "TelaDeSetup.h"

TelaDeSetup::TelaDeSetup(Setup *setup, QSqlDatabase conn, bool insere) {
    db = conn;
    gravaTempoSetup = new QTimer();
    atualizaTempoDeSetupTela = new QTimer();
    gravaTempoSetup->start(10000);
    atualizaTempoDeSetupTela->start(1000);
    tempoDeStup = QTime();
    tempoDeStup.setHMS(0,0,0,0);
    this->setup = new Setup(setup);

    SetupDAO * setDAO = new SetupDAO(db);
    QDate DatIni;
    QTime horIni;
    int qtdMin = (horIni.currentTime().hour() * 60 * 60) + (horIni.currentTime().minute() * 60) + horIni.currentTime().second();

    this->setup->setDataInicio(DatIni.currentDate());
    this->setup->setHoraInicio(qtdMin);

    Setup * dialog = new Setup(this->setup);
    if (insere) {
        setDAO->insereSetup(dialog);
    }
    delete dialog;
    delete setDAO;

    connect(gravaTempoSetup, SIGNAL(timeout()), this, SLOT(gravaSetup()));
    connect(atualizaTempoDeSetupTela, SIGNAL(timeout()), this, SLOT(atualizaTela()));
}

TelaDeSetup::~TelaDeSetup() {
    delete gravaTempoSetup;
    delete atualizaTempoDeSetupTela;
    delete setup;
}

// Slots

void TelaDeSetup::gravaSetup() {
    SetupDAO * setDAO = new SetupDAO(db);
    QDate DatFim;
    QTime horFim;
    int qtdMin = (horFim.currentTime().hour() * 60 * 60) + (horFim.currentTime().minute() * 60) + horFim.currentTime().second();

    this->setup->setDataFim(DatFim.currentDate());
    this->setup->setHoraFim(qtdMin);

    Setup * dialog = new Setup(this->setup);

    setDAO->atualizaSetup(dialog);

    delete dialog;
    delete setDAO;
}

void TelaDeSetup::atualizaTela() {
    tempoDeStup = tempoDeStup.addSecs(1);
    emit atualizaTelaPrincipal(tempoDeStup);
}

void TelaDeSetup::acabouSetup() {
    this->gravaTempoSetup->stop();
    this->atualizaTempoDeSetupTela->stop();
}
