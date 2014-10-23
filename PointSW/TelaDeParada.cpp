#include "TelaDeParada.h"
#include "ui_TelaDeParada.h"

TelaDeParada::TelaDeParada(Parada *padara, QWidget *parent) : QDialog(parent), ui(new Ui::TelaDeParada) {
    ui->setupUi(this);
}

TelaDeParada::~TelaDeParada() {
    delete ui;
}
