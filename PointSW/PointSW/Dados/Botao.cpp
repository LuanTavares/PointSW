#include "Botao.h"

Botao::Botao(int linha) {
    this->linha = linha;
    connect(this,SIGNAL(clicked()),this,SLOT(emiteDados()));
}

Botao::~Botao(){

}

void Botao::emiteDados(){
    sClick(this->linha);
}

