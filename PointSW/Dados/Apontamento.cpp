#include "Apontamento.h"

Apontamento::Apontamento() {

}

Apontamento::Apontamento(Maquina *maquina, OrdemDeProducao *op, Usuario *usuario, int setup, int tempoProducao, int qtdproduzida, int qtdDeParadas) {
    this->maquina = maquina;
    this->OP = op;
    this->usuario = usuario;
    this->tempoDeSetup = setup;
    this->tempoDeProducao = tempoProducao;
    this->quantidadeProduzida = qtdproduzida;
    this->quantidadeDeParadas = qtdDeParadas;
}

Apontamento::~Apontamento() {
    delete this->maquina;
    delete this->OP;
    delete this->usuario;
}

Maquina * Apontamento::getMaquina() {
    return this->maquina;
}

OrdemDeProducao * Apontamento::getOP() {
    return this->OP;
}

Usuario * Apontamento::getUsuario() {
    return this->usuario;
}

int Apontamento::getTempoDeSetup() {
    return this->tempoDeSetup;
}

int Apontamento::getTempoDeProducao() {
    return this->tempoDeProducao;
}

int Apontamento::getQuantidadeProduzida() {
    return this->quantidadeProduzida;
}

int Apontamento::getQuantidadeDeParadas() {
    return this->quantidadeDeParadas;
}

void Apontamento::setMaquina(Maquina *maquina) {
    this->maquina = maquina;
}

void Apontamento::setOP(OrdemDeProducao *op) {
    this->OP = op;
}

void Apontamento::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

void Apontamento::setTempoDeSetup(int setup) {
    this->tempoDeSetup = setup;
}

void Apontamento::setTempoDeProducao(int tempoProducao) {
    this->tempoDeProducao = tempoProducao;
}

void Apontamento::setQuantidadeProduzida(int qtdProduzida) {
    this->quantidadeProduzida = qtdProduzida;
}

void Apontamento::setQuantidadeDeParadas(int qtdParadas) {
    this->quantidadeDeParadas = qtdParadas;
}
