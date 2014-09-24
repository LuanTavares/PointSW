#ifndef USUARIO_H
#define USUARIO_H
#include <QString>
class Usuario {
private:
    int codigoUsuario;
    QString nomeUsuario;
    QString grupo;

public:
    Usuario();
    Usuario(int codigo, QString nome, QString grupo);
    Usuario(Usuario * usu);
    ~Usuario();

    // Gets
    int getCodigoUsuario();
    QString getNomeUsuario();
    QString getGrupo();

    // Sets
    void setCodigoUsuario(int codigo);
    void setNomeUsuaio(QString nome);
    void setGrupo(QString grupo);
};

#endif // USUARIO_H
