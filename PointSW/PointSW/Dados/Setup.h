#ifndef SETUP_H
#define SETUP_H
#include <QDate>
#include "Maquina.h"
#include "OrdemDeProducao.h"
#include "Usuario.h"
class Setup {
private:
    Maquina * maquina;
    OrdemDeProducao * OP;
    Usuario * usuario;
    QDate dataInicio;
    int horaInicio;
    QDate dataFim;
    int horaFim;
public:
    Setup();
    Setup(Maquina * maquina, OrdemDeProducao * op, Usuario * usuario, QDate datIni, int horIni, QDate datFim, int horFim);
    Setup(Setup * setup);
    ~Setup();

    // Gets
    Maquina * getMaquina();
    OrdemDeProducao * getOP();
    Usuario * getUsuario();
    QDate getDataInicio();
    int getHoraInicio();
    QDate getDataFim();
    int getHoraFim();

    // Sets
    void setMaquina(Maquina * maquina);
    void setOP(OrdemDeProducao * op);
    void setUsuario(Usuario * usuario);
    void setDataInicio(QDate datIni);
    void setHoraInicio(int horIni);
    void setDataFim(QDate datFim);
    void setHoraFim(int horFim);

};

#endif // SETUP_H
