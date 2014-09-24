#ifndef USUARIODAO_H
#define USUARIODAO_H
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "Conexao.h"
#include "Usuario.h"
class UsuarioDAO {
private:
    QSqlDatabase db;
    QSqlQuery query;
public:
    UsuarioDAO(QSqlDatabase conn);
    QList <Usuario> getUsuarios();
    Usuario * getUsuario(int usu);
    bool insereUsuario(Usuario usu);
    bool atualizaUsuario(Usuario usu);
    bool deletaUsuario(Usuario usu);
};

#endif // USUARIODAO_H
