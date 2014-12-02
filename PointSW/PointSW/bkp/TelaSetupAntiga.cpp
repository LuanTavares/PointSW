#include "TelaSetupAntiga.h"
#include "ui_TelaSetup.h"

TelaSetupAntiga::TelaSetupAntiga(Setup *setup, QSqlDatabase conn, QWidget *parent) : QWidget(parent), ui(new Ui::TelaSetup) {
    db = conn;
    tempoDeSetup = new QTimer();
    atualizaTempoDeSetupTela = new QTimer();
    tempoDeSetup->start(60000);
    atualizaTempoDeSetupTela->start(1000);
    dialogTime = QTime();
    dialogTime.setHMS(0,0,0,0);
    this->setup = new Setup(setup);

    gravaSetup();

    connect(tempoDeSetup, SIGNAL(timeout()), this, SLOT(gravaSetup()));
    connect(atualizaTempoDeSetupTela, SIGNAL(timeout()), this, SLOT(atualizaTela()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(finalizaSetup()));
}

TelaSetupAntiga::~TelaSetupAntiga() {
    delete ui;
    delete atualizaTempoDeSetupTela;
    delete tempoDeSetup;
    delete setup;
}

// Slots

void TelaSetupAntiga::gravaSetup() {
    SetupDAO * setDAO = new SetupDAO(db);
    QDate DatIni;
    QTime horIni;
    int qtdMin = (horIni.currentTime().hour() * 60 * 60) + (horIni.currentTime().minute() * 60) + horIni.currentTime().second();

    this->setup->setDataInicio(DatIni.currentDate());
    this->setup->setHoraInicio(qtdMin);

    Setup * dialog = new Setup(this->setup);
    OrdemDeProducao * op = new OrdemDeProducao(dialog->getOP());

    setDAO->insereSetup(dialog);
    ui->lineEditOP->setText(op->getOP());

    this->update();
}

void TelaSetupAntiga::finalizaSetup() {
    SetupDAO * setDAO = new SetupDAO(db);

    QDate datIni;
    this->setup->setDataInicio(datIni.currentDate());
    QTime horIni;
    int qtdMinIni = (horIni.currentTime().hour() * 60) + horIni.currentTime().minute();
    this->setup->setHoraInicio(qtdMinIni);
    QDate datFim;
    this->setup->setDataFim(datFim.currentDate());
    QTime horFim;
    int qtdMinFim = (horFim.currentTime().hour() * 60) + horFim.currentTime().minute();
    this->setup->setHoraFim(qtdMinFim);
    setDAO->insereSetup(this->setup);
}

void TelaSetupAntiga::atualizaTela() {
    dialogTime = dialogTime.addSecs(1);
    ui->timeEditTempo->setTime(dialogTime);
    this->update();
}
