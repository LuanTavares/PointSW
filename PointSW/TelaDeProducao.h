#ifndef TELADEPRODUCAO_H
#define TELADEPRODUCAO_H
#include <QWidget>
#include <QTimer>
#include "ProducaoDAO.h"
class TelaDeProducao : public QWidget  {

    Q_OBJECT

public:
    TelaDeProducao(Producao * producao, QSqlDatabase conn);
    ~TelaDeProducao();
private:
    QTimer * gravaTempoProducao;
    QTimer * atualizaTempoDeProducaoTela;
    Producao * producao;
    QSqlDatabase db;
    int qtd;
    QTime tempoDeProducao;

public slots:
    void gravaProducao();
    void atualizaTela();
    void acabouProducao();

signals:
    void atualizaTelaPrincipal(QTime tempo);
};

#endif // TELADEPRODUCAO_H