#ifndef BOTAO_H
#define BOTAO_H
#include <QtWidgets/QPushButton>

class Botao : public QPushButton{

    Q_OBJECT

private:
    int linha;

public:
    Botao(int linha);
    ~Botao();

public slots:
    void emiteDados();

signals:
    void sClick(int linha);
};

#endif // BOTAO_H
