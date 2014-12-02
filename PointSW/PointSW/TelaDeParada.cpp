#include "TelaDeParada.h"
#include "ui_TelaDeParada.h"

TelaDeParada::TelaDeParada(Parada *parada, QSqlDatabase conn, QWidget *parent) : QDialog(parent), ui(new Ui::TelaDeParada) {
    ui->setupUi(this);
    this->db = conn;
    this->parada = new Parada(parada);
    ui->lineEditMaquina->setText(this->parada->getMaquina()->getNomemaquina());
    ui->lineEditOP->setText(this->parada->getOP()->getOP());
    ui->dateEditDataInicio->setDate(this->parada->getDataInicio());
    int qtdHor = (this->parada->getHoraInicio() / 60) / 60;
    int qtdMin = (this->parada->getHoraInicio() / 60 ) - (qtdHor * 60);
    QTime horIni = QTime(qtdHor,qtdMin);
    ui->timeEditHoraInicio->setTime(horIni);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowTitle("Apontamento da Parada "+QString::number(this->parada->getSequencia())+" da OP "+this->parada->getOP()->getOP());
    MotivosDeParadasDAO motDAO(db);
    this->motivos = motDAO.getMotivos();
    for(int i=0; i<motivos.size(); i++) {
        MotivosDeParadas dialogMot = motivos.at(i);
        ui->comboBoxMotivo->addItem(dialogMot.getDescricao());
    }
    connect(ui->pushButtonSalvar, SIGNAL(clicked()), this, SLOT(gravaMotivoParada()));
}

TelaDeParada::~TelaDeParada() {
    delete ui;
}

// Slots

void TelaDeParada::gravaMotivoParada() {
    ParadasDAO * dialogDAO = new ParadasDAO(db);
    MotivosDeParadas * mot = motivos.at(ui->comboBoxMotivo->currentIndex());
    this->parada->setMotivo(mot);
    dialogDAO->atualizaParada(this->parada);
    this->destroyed();
    this->close();
}
