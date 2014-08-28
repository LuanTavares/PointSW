#include "Cliente.h"

Cliente::Cliente() {

}

Cliente::Cliente(int codigo, QString nome) {
    this->codigoCliente = codigo;
    this->nomeCliente = nome;
}

Cliente::~Cliente() {

}

int Cliente::getCodigoCliente() {
    return this->codigoCliente;
}

QString Cliente::getNomeCliente() {
    return this->nomeCliente;
}

void Cliente::setCodigoCliente(int codigo) {
    this->codigoCliente = codigo;
}

void Cliente::setNomeCliente(QString nome) {
    this->nomeCliente = nome;
}
