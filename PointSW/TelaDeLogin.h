#ifndef TELADELOGIN_H
#define TELADELOGIN_H

#include <QWidget>
#include "TelaPrincipal.h"
#include "UsuarioDAO.h"
namespace Ui {
    class TelaDeLogin;
}

class TelaDeLogin : public QWidget {
    Q_OBJECT
    
public:
    explicit TelaDeLogin(QWidget *parent = 0);
    ~TelaDeLogin();
    
private:
    Ui::TelaDeLogin *ui;
    TelaPrincipal * telaPrincipal;
    Usuario * usu;
    Conexao * conn;

public slots:
    void abreTelaPrincipal();
};

#endif // TELADELOGIN_H
