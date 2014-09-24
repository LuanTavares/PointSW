#include "Setup.h"

Setup::Setup() {

}

Setup::Setup(Maquina *maquina, OrdemDeProducao *op, Usuario *usuario, QDate datIni, int horIni, QDate datFim, int horFim) {
    this->maquina = maquina;
    this->OP = op;
    this->usuario = usuario;
    this->dataInicio = datIni;
    this->horaInicio = horIni;
    this->dataFim = datFim;
    this->horaFim = horFim;
}

Setup::Setup(Setup *setup) {
    this->maquina = new Maquina(setup->getMaquina());
    this->OP = new OrdemDeProducao(setup->getOP());
    this->usuario = new Usuario(setup->getUsuario());
    this->dataInicio = setup->getDataInicio();
    this->horaInicio = setup->getHoraInicio();
    this->dataFim = setup->getDataFim();
    this->horaFim = setup->getHoraFim();
}

Setup::~Setup() {
    delete this->maquina;
    delete this->OP;
    delete this->usuario;
}

Maquina * Setup::getMaquina() {
    return this->maquina;
}

OrdemDeProducao * Setup::getOP() {
    return this->OP;
}

Usuario * Setup::getUsuario() {
    return this->usuario;
}

QDate Setup::getDataInicio() {
    return this->dataInicio;
}

int Setup::getHoraInicio() {
    return this->horaInicio;
}

QDate Setup::getDataFim() {
    return this->dataFim;
}

int Setup::getHoraFim() {
    return this->horaFim;
}

void Setup::setMaquina(Maquina *maquina) {
    this->maquina = maquina;
}

void Setup::setOP(OrdemDeProducao *op) {
    this->OP = op;
}

void Setup::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

void Setup::setDataInicio(QDate datIni) {
    this->dataInicio = datIni;
}

void Setup::setHoraInicio(int horIni) {
    this->horaInicio = horIni;
}

void Setup::setDataFim(QDate datFim) {
    this->dataFim = datFim;
}

void Setup::setHoraFim(int horFim) {
    this->horaFim = horFim;
}
