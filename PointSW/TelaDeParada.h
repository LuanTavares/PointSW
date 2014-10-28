#ifndef TELADEPARADA_H
#define TELADEPARADA_H

#include <QDialog>
#include "ParadasDAO.h"
namespace Ui {
    class TelaDeParada;
}

class TelaDeParada : public QDialog {
    Q_OBJECT
    
public:
    explicit TelaDeParada(Parada * parada, QSqlDatabase conn, QWidget *parent = 0);
    ~TelaDeParada();
    
private:
    Ui::TelaDeParada *ui;
    QSqlDatabase db;
    Parada * parada;

public slots:
    void gravaMotivoParada();
};

#endif // TELADEPARADA_H
