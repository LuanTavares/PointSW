#ifndef PARADAS_H
#define PARADAS_H
#include <QDate>
#include "Maquina.h"
#include "OrdemDeProducao.h"
#include "Usuario.h"
#include "MotivosDeParadas.h"
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
    MotivosDeParadas * motivo;
public:
    Parada();
    Parada(Maquina * maquina, OrdemDeProducao * OP, Usuario * usuario, QDate datIni, int horIni, int sequencia, QDate datFim, int HorFim, MotivosDeParadas * motivo);
    Parada(Parada * parada);
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
    MotivosDeParadas * getMotivo();

    // Sets
    void setMaquina(Maquina * maquina);
    void setOP(OrdemDeProducao * op);
    void setUsuario(Usuario * usuario);
    void setDataInicio(QDate datIni);
    void setHoraInicio(int horIni);
    void setSequencia(int Sequencia);
    void setDataFim(QDate datFim);
    void setHoraFim(int horFim);
    void setMotivo(MotivosDeParadas * motivo);
};

#endif // PARADAS_H
