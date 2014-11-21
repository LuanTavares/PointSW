#include "Maquina.h"

Maquina::Maquina() {

}

Maquina::Maquina(int codigo, QString nome, int status) {
    this->codigoMaquina = codigo;
    this->nomeMaquina = nome;
    this->status = status;
}

Maquina::Maquina(Maquina *maq) {
    this->codigoMaquina = maq->getCodigoMaquina();
    this->nomeMaquina = maq->getNomemaquina();
    this->status = maq->getStatus();
}

Maquina::~Maquina() {

}

int Maquina::getCodigoMaquina() {
    return this->codigoMaquina;
}

QString Maquina::getNomemaquina() {
    return this->nomeMaquina;
}

int Maquina::getStatus() {
    return this->status;
}

void Maquina::setCodigoMaquina(int codigo) {
    this->codigoMaquina = codigo;
}

void Maquina::setNomeMaquina(QString nome) {
    this->nomeMaquina = nome;
}

void Maquina::setStatus(int status) {
    this->status = status;
}
