#include "OrdemDeProducao.h"

OrdemDeProducao::OrdemDeProducao() {

}

OrdemDeProducao::OrdemDeProducao(QString OP, Cliente *cliente, Maquina *maquina, int ordem, int qtdProgramada, QDate entrega) {
    this->OP = OP;
    this->cliente = cliente;
    this->maquina = maquina;
    this->ordem = ordem;
    this->quantidadeProgramada = qtdProgramada;
    this->dataDeEntrada = entrega;
}

OrdemDeProducao::~OrdemDeProducao() {
    delete this->cliente;
    delete this->maquina;
}

QString OrdemDeProducao::getOP() {
    return this->OP;
}

Cliente * OrdemDeProducao::getCliente() {
    return this->cliente;
}

Maquina * OrdemDeProducao::getMaquina() {
    return this->maquina;
}

int OrdemDeProducao::getOrdem() {
    return this->ordem;
}

int OrdemDeProducao::getQuantidadeProgramada() {
    return this->quantidadeProgramada;
}
QDate OrdemDeProducao::getDataDeEntrega() {
     return this->dataDeEntrada;
}

void OrdemDeProducao::setOP(QString op) {
    this->OP = op;
}

void OrdemDeProducao::setCliente(Cliente *cliente) {
    this->cliente = cliente;
}

void OrdemDeProducao::setMaquina(Maquina *maquina) {
    this->maquina = maquina;
}

void OrdemDeProducao::setOrdem(int ordem) {
    this->ordem = ordem;
}

void OrdemDeProducao::setQuantidadeProgramada(int qtdProgramada) {
    this->quantidadeProgramada = qtdProgramada;
}

void OrdemDeProducao::setDataDeEntrega(QDate entrega) {
    this->dataDeEntrada = entrega;
}
