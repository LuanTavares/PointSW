#include "MotivosDeParadas.h"

MotivosDeParadas::MotivosDeParadas() {

}

MotivosDeParadas::MotivosDeParadas(int codigo, QString descricao) {
    this->codigoParada = codigo;
    this->descricaoParada = descricao;
}

MotivosDeParadas::MotivosDeParadas(MotivosDeParadas *motivo) {
    this->codigoParada = motivo->getCodigo();
    this->descricaoParada = motivo->getDescricao();
}

MotivosDeParadas::~MotivosDeParadas() {

}

int MotivosDeParadas::getCodigo() {
    return this->codigoParada;
}

QString MotivosDeParadas::getDescricao() {
    return this->descricaoParada;
}

void MotivosDeParadas::setCodigo(int codigo) {
    this->codigoParada = codigo;
}

void MotivosDeParadas::setDescricao(QString Descricao) {
    this->descricaoParada = Descricao;
}
