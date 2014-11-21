#include "Usuario.h"

Usuario::Usuario() {

}

Usuario::Usuario(int codigo, QString nome, QString grupo) {
    this->codigoUsuario = codigo;
    this->nomeUsuario = nome;
    this->grupo = grupo;
}

Usuario::Usuario(Usuario *usu) {
    this->codigoUsuario = usu->codigoUsuario;
    this->nomeUsuario = usu->getNomeUsuario();
    this->grupo = usu->getGrupo();
}

Usuario::~Usuario() {

}

int Usuario::getCodigoUsuario() {
    return this->codigoUsuario;
}

QString Usuario::getNomeUsuario() {
    return this->nomeUsuario;
}

QString Usuario::getGrupo() {
    return this->grupo;
}

void Usuario::setCodigoUsuario(int codigo) {
    this->codigoUsuario = codigo;
}

void Usuario::setNomeUsuaio(QString nome) {
    this->nomeUsuario = nome;
}

void Usuario::setGrupo(QString grupo) {
    this->grupo = grupo;
}
