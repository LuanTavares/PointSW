#ifndef PARADAS_H
#define PARADAS_H
#include <QDate>
#include "Maquina.h"
#include "OrdemDeProducao.h"
#include "Usuario.h"
class Parada {
private:
    Maquina * maquina;
    OrdemDeProducao * OP;
    Usuario * usuario;
    QDate dataInicio;
    int horaInicio;
    int sequencia;
    QDate dataFim;
    int horaFim;
public:
    Parada();
    Parada(Maquina * maquina, OrdemDeProducao * OP, Usuario * usuario, QDate datIni, int horIni, int sequencia, QDate datFim, int HorFim);
    ~Parada();

    // Gets
    Maquina * getMaquina();
    OrdemDeProducao * getOP();
    Usuario * getUsuario();
    QDate getDataInicio();
    int getHoraInicio();
    int getSequencia();
    QDate getDataFim();
    int getHoraFim();

    // Sets
    void setMaquina(Maquina * maquina);
    void setOP(OrdemDeProducao * op);
    void setUsuario(Usuario * usuario);
    void setDataInicio(QDate datIni);
    void setHoraInicio(int horIni);
    void setSequencia(int Sequencia);
    void setDataFim(QDate datFim);
    void setHoraFim(int horFim);

};

#endif // PARADAS_H
