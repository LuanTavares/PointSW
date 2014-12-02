#ifndef ORDEMDEPRODUCAO_H
#define ORDEMDEPRODUCAO_H
#include <QString>
#include <QDate>
#include "Cliente.h"
#include "Maquina.h"
class OrdemDeProducao {
private:
    QString OP;
    Cliente * cliente;
    Maquina * maquina;
    int ordem;
    int quantidadeProgramada;
    QDate dataDeEntrada;

public:
    OrdemDeProducao();
    OrdemDeProducao(OrdemDeProducao * op);
    OrdemDeProducao(QString OP, Cliente * cliente, Maquina * maquina, int ordem, int qtdProgramada, QDate entrega);
    ~OrdemDeProducao();

    // Gets
    QString getOP();
    Cliente* getCliente();
    Maquina* getMaquina();
    int getOrdem();
    int getQuantidadeProgramada();
    QDate getDataDeEntrega();

    // Sets
    void setOP(QString op);
    void setCliente(Cliente * cliente);
    void setMaquina(Maquina * maquina);
    void setOrdem(int ordem);
    void setQuantidadeProgramada(int qtdProgramada);
    void setDataDeEntrega(QDate entrega);

};

#endif // ORDEMDEPRODUCAO_H
