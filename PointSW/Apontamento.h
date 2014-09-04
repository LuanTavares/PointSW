#ifndef APONTAMENTO_H
#define APONTAMENTO_H
#include "Maquina.h"
#include "OrdemDeProducao.h"
#include "Usuario.h"
class Apontamento {
private: 
    Maquina * maquina;
    OrdemDeProducao * OP;
    Usuario * usuario;    
    int tempoDeSetup;
    int tempoDeProducao;
    int quantidadeProduzida;
    int quantidadeDeParadas;
public:
    Apontamento();
    Apontamento(Maquina * maquina, OrdemDeProducao * op, Usuario * usuario, int setup, int tempoProducao, int qtdproduzida, int qtdDeParadas);
    ~Apontamento();
    
    // Gets
    Maquina * getMaquina();
    OrdemDeProducao * getOP();
    Usuario * getUsuario();
    int getTempoDeSetup();
    int getTempoDeProducao();
    int getQuantidadeProduzida();
    int getQuantidadeDeParadas();

    // Sets
    void setMaquina(Maquina * maquina);
    void setOP(OrdemDeProducao * op);
    void setUsuario(Usuario * usuario);
    void setTempoDeSetup(int setup);
    void setTempoDeProducao(int tempoProducao);
    void setQuantidadeProduzida(int qtdProduzida);
    void setQuantidadeDeParadas(int qtdParadas);
    
};

#endif // APONTAMENTO_H
