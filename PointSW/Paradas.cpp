#include "Paradas.h"

Parada::Parada() {

}

Parada::Parada(Maquina *maquina, OrdemDeProducao *op, Usuario *usuario, QDate datIni, int horIni, int sequencia, QDate datFim, int horFim) {
    this->maquina = maquina;
    this->OP = op;
    this->usuario = usuario;
    this->dataInicio = datIni;
    this->horaInicio = horIni;
    this->sequencia = sequencia;
    this->dataFim = datFim;
    this->horaFim = horFim;
}

Parada::~Parada() {
    delete this->maquina;
    delete this->OP;
    delete this->usuario;
}

Maquina * Parada::getMaquina() {
    return this->maquina;
}

OrdemDeProducao * Parada::getOP() {
    return this->OP;
}

Usuario * Parada::getUsuario() {
    return this->usuario;
}

QDate Parada::getDataInicio() {
    return this->dataInicio;
}

int Parada::getHoraInicio() {
    return this->horaInicio;
}

int Parada::getSequencia() {
    return this->sequencia;
}

QDate Parada::getDataFim() {
    return this->dataFim;
}

int Parada::getHoraFim() {
    return this->horaFim;
}

void Parada::setMaquina(Maquina *maquina) {
    this->maquina = maquina;
}

void Parada::setOP(OrdemDeProducao *op) {
    this->OP = op;
}

void Parada::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

void Parada::setDataInicio(QDate datIni) {
    this->dataInicio = datIni;
}

void Parada::setHoraInicio(int horIni) {
    this->horaInicio = horIni;
}

void Parada::setSequencia(int Sequencia) {
    this->sequencia = Sequencia;
}

void Parada::setDataFim(QDate datFim) {
    this->dataFim = datFim;
}

void Parada::setHoraFim(int horFim) {
    this->horaFim = horFim;
}
