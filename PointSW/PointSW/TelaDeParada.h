#ifndef TELADEPARADA_H
#define TELADEPARADA_H
#include <QDialog>
#include <QList>
#include "DAO/ParadasDAO.h"
#include "DAO/MotivosDeParadasDAO.h"
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
    QList <MotivosDeParadas *> motivos;

public slots:
    void gravaMotivoParada();
};

#endif // TELADEPARADA_H
