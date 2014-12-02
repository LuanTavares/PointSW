#ifndef CLIENTE_H
#define CLIENTE_H
#include <QString>
class Cliente {

private:
    int codigoCliente;
    QString nomeCliente;

public:
    Cliente();
    Cliente(int codigo, QString nome);
    Cliente(Cliente * cli);
    ~Cliente();

    // Gets
    int getCodigoCliente();
    QString getNomeCliente();

    // Sets
    void setCodigoCliente(int codigo);
    void setNomeCliente(QString nome);

};

#endif // CLIENTE_H
