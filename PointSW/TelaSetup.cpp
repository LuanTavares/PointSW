#include "TelaSetup.h"
#include "ui_TelaSetup.h"

TelaSetup::TelaSetup(Setup *setup, QSqlDatabase conn, QWidget *parent) : QWidget(parent), ui(new Ui::TelaSetup) {
    db = conn;
    ui->setupUi(this);
    tempoDeSetup = new QTimer();
    tempoDeSetup->start(60000);
    this->setup = new Setup(setup);

    connect(tempoDeSetup, SIGNAL(timeout()), this, SLOT(gravaSetup()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(finalizaSetup()));
}

TelaSetup::~TelaSetup() {
    delete ui;
}

// Slots

void TelaSetup::gravaSetup() {
    SetupDAO * setDAO = new SetupDAO(db);
    QDate DatIni;
    this->setup->setDataInicio(DatIni.currentDate());
    QTime horIni;
    int qtdMin = (horIni.currentTime().hour() * 60) + horIni.currentTime().minute();
    this->setup->setHoraInicio(qtdMin);
    setDAO->insereSetup(new Setup(this->setup));
    OrdemDeProducao * op = new OrdemDeProducao(this->setup->getOP());
    ui->lineEditOP->setText(op->getOP());
    this->update();
    QTime qtdHorAtu;
    qtd++;
    qtdHorAtu.setHMS(0,qtd,0);
    ui->timeEditTempo->setTime(qtdHorAtu);
}

void TelaSetup::finalizaSetup() {
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
