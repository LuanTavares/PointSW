#include "Producao.h"

Producao::Producao() {
}

Producao::Producao(Maquina *maquina, OrdemDeProducao *OP, Usuario *usuario, QDate datIni, int horIni, int contagem, QDate datFim, int HorFim, int status) {
    this->maquina = maquina;
    this->OP = OP;
    this->usuario = usuario;
    this->dataInicio = datIni;
    this->horaInicio = horIni;
    this->contagem = contagem;
    this->dataFim = datFim;
    this->horaFim = HorFim;
    this->status = status;
}

Producao::~Producao() {
    delete this->maquina;
    delete this->OP;
    delete this->usuario;
}

Maquina * Producao::getMaquina() {
    return this->maquina;
}

OrdemDeProducao * Producao::getOP() {
    return this->OP;
}

Usuario * Producao::getUsuario() {
    return this->usuario;
}

QDate Producao::getDataInicio() {
    return this->dataInicio;
}

int Producao::getHoraInicio() {
    return this->horaInicio;
}

int Producao::getContagem() {
    return this->contagem;
}

QDate Producao::getDataFim() {
    return this->dataFim;
}

int Producao::getHoraFim() {
    return this->horaFim;
}

int Producao::getStatus() {
    return this->status;
}

void Producao::setMaquina(Maquina *maquina) {
    this->maquina = maquina;
}

void Producao::setOP(OrdemDeProducao *op) {
    this->OP = op;
}

void Producao::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

void Producao::setDataInicio(QDate datIni) {
    this->dataInicio = datIni;
}

void Producao::setHoraInicio(int horIni) {
    this->horaInicio = horIni;
}

void Producao::setConagem(int contagem) {
    this->contagem= contagem;
}

void Producao::setDataFim(QDate datFim) {
    this->dataFim = datFim;
}

void Producao::setHoraFim(int horFim) {
    this->horaFim = horFim;
}

void Producao::setStatus(int status) {
    this->status = status;
}
