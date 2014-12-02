#include "TelaDeProducao.h"

TelaDeProducao::TelaDeProducao(Producao *producao, QSqlDatabase conn) {
    db = conn;
    gravaTempoProducao = new QTimer();
    atualizaTempoDeProducaoTela = new QTimer();
    gravaTempoProducao->start(10000);
    atualizaTempoDeProducaoTela->start(1000);
    tempoDeProducao = QTime();
    tempoDeProducao.setHMS(0,0,0,0);
    this->producao = new Producao(producao);

    ProducaoDAO * proDAO = new ProducaoDAO(db);
    QDate DatIni;
    QTime horIni;
    int qtdMin = (horIni.currentTime().hour() * 60 * 60) + (horIni.currentTime().minute() * 60) + horIni.currentTime().second();

    this->producao->setDataInicio(DatIni.currentDate());
    this->producao->setHoraInicio(qtdMin);

    Producao * dialog = new Producao(this->producao);
    proDAO->insereProducao(dialog);
    delete dialog;
    delete proDAO;

    connect(gravaTempoProducao, SIGNAL(timeout()), this, SLOT(gravaProducao()));
    connect(atualizaTempoDeProducaoTela, SIGNAL(timeout()), this, SLOT(atualizaTela()));
}

TelaDeProducao::~TelaDeProducao() {
    delete gravaTempoProducao;
    delete atualizaTempoDeProducaoTela;
    delete producao;
}

void TelaDeProducao::setaStatus(int statusProducao) {
    producao->setStatus(statusProducao);
}

// Slots

void TelaDeProducao::gravaProducao() {
    ProducaoDAO * proDAO = new ProducaoDAO(db);
    QDate DatFim;
    QTime horFim;
    int qtdMin = (horFim.currentTime().hour() * 60 * 60) + (horFim.currentTime().minute() * 60) + horFim.currentTime().second();

    this->producao->setDataFim(DatFim.currentDate());
    this->producao->setHoraFim(qtdMin);

    Producao * dialog = new Producao(this->producao);

    proDAO->atualizaProducao(dialog);

    delete dialog;
    delete proDAO;
}

void TelaDeProducao::atualizaTela() {
    tempoDeProducao = tempoDeProducao.addSecs(1);
    emit atualizaTelaPrincipal(tempoDeProducao);
}

void TelaDeProducao::acabouProducao() {
    this->gravaTempoProducao->stop();
    this->atualizaTempoDeProducaoTela->stop();
}
