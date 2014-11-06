#include "Paradas.h"

Parada::Parada() {

}

Parada::Parada(Maquina *maquina, OrdemDeProducao *OP, Usuario *usuario, QDate datIni, int horIni, int sequencia, QDate datFim, int HorFim, MotivosDeParadas *motivo) {
    this->maquina = maquina;
    this->OP = OP;
    this->usuario = usuario;
    this->dataInicio = datIni;
    this->horaInicio = horIni;
    this->sequencia = sequencia;
    this->dataFim = datFim;
    this->horaFim = HorFim;
    this->motivo = motivo;
}

Parada::Parada(Parada *parada) {
    this->maquina = new Maquina(parada->getMaquina());
    this->OP = new OrdemDeProducao(parada->getOP());
    this->usuario = new Usuario(parada->getUsuario());
    this->dataInicio = parada->getDataInicio();
    this->horaInicio = parada->getHoraInicio();
    this->sequencia = parada->getSequencia();
    this->dataFim = parada->getDataFim();
    this->horaFim = parada->getHoraFim();
    this->motivo = parada->getMotivo();
}

Parada::~Parada() {
    delete this->maquina;
    delete this->OP;
    delete this->usuario;
    delete this->motivo;
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

MotivosDeParadas * Parada::getMotivo() {
    return this->motivo;
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

void Parada::setMotivo(MotivosDeParadas *motivo) {
    this->motivo = motivo;
}
