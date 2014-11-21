#ifndef MAQUINAS_H
#define MAQUINAS_H

#include <QString>

class Maquina {
private:
    int codigoMaquina;
    QString nomeMaquina;
    int status;
public:
    Maquina();
    Maquina(int codigo, QString nome, int status);
    Maquina(Maquina * maq);
    ~Maquina();

    // Gets
    int getCodigoMaquina();
    QString getNomemaquina();
    int getStatus();

    // Sets
    void setCodigoMaquina(int codigo);
    void setNomeMaquina(QString nome);
    void setStatus(int status);
};

#endif // MAQUINAS_H
