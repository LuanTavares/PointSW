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
    explicit TelaDeParada(Parada * padara, QWidget *parent = 0);
    ~TelaDeParada();
    
private:
    Ui::TelaDeParada *ui;
};

#endif // TELADEPARADA_H
