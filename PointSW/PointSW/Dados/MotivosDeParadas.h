#ifndef MOTIVOSDEPARADAS_H
#define MOTIVOSDEPARADAS_H
#include <Qstring>

class MotivosDeParadas {
private:
    int codigoParada;
    QString descricaoParada;

public:
    MotivosDeParadas();
    MotivosDeParadas(int codigo, QString descricao);
    MotivosDeParadas(MotivosDeParadas * motivo);
    ~MotivosDeParadas();

    // Gets
    int getCodigo();
    QString getDescricao();

    // Sets
    void setCodigo(int codigo);
    void setDescricao(QString Descricao);
};

#endif // MOTIVOSDEPARADAS_H
