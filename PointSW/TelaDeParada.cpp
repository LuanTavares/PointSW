#include "TelaDeParada.h"
#include "ui_TelaDeParada.h"

TelaDeParada::TelaDeParada(Parada *parada, QSqlDatabase conn, QWidget *parent) : QDialog(parent), ui(new Ui::TelaDeParada) {
    ui->setupUi(this);
    this->db = conn;
    this->parada = new Parada(parada);
}

TelaDeParada::~TelaDeParada() {
    delete ui;
}

// Slots

void TelaDeParada::gravaMotivoParada() {
    ParadasDAO * dialogDAO = new ParadasDAO(db);

}
