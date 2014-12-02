#ifndef PRODUCAO_H
#define PRODUCAO_H
#include <QDate>
#include "Maquina.h"
#include "OrdemDeProducao.h"
#include "Usuario.h"
class Producao {
private:
    Maquina * maquina;
    OrdemDeProducao * OP;
    Usuario * usuario;
    QDate dataInicio;
    int horaInicio;
    int contagem;
    QDate dataFim;
    int horaFim;
    int status;
public:
    Producao();
    Producao(Maquina * maquina, OrdemDeProducao * OP, Usuario * usuario, QDate datIni, int horIni, int contagem, QDate datFim, int HorFim, int status);
    Producao(Producao * producao);
    ~Producao();

    // Gets
    Maquina * getMaquina();
    OrdemDeProducao * getOP();
    Usuario * getUsuario();
    QDate getDataInicio();
    int getHoraInicio();
    int getContagem();
    QDate getDataFim();
    int getHoraFim();
    int getStatus();

    // Sets
    void setMaquina(Maquina * maquina);
    void setOP(OrdemDeProducao * op);
    void setUsuario(Usuario * usuario);
    void setDataInicio(QDate datIni);
    void setHoraInicio(int horIni);
    void setContagem(int contagem);
    void setDataFim(QDate datFim);
    void setHoraFim(int horFim);
    void setStatus(int status);
};

#endif // PRODUCAO_H
