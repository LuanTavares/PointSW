#include "UsuarioDAO.h"

UsuarioDAO::UsuarioDAO(QSqlDatabase conn) {
    db = conn;
}

QList <Usuario> UsuarioDAO::getUsuarios() {
    QList <Usuario> retorno;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT codigousuario, nomeusuario, grupo FROM usuario");
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            int i = 0;
            while (query.next()) {
                Usuario dialogUsuario(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString());
                retorno.insert(i,dialogUsuario);
                i++;
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

Usuario *UsuarioDAO::getUsuario(int usu) {
    Usuario * retorno = NULL;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoUsuario, NomeUsuario, Grupo FROM Usuario WHERE CodigoUsuario = ?");
        query.addBindValue(usu);
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            if(query.first())
                retorno = new Usuario(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString());
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

bool UsuarioDAO::insereUsuario(Usuario usu) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("INSERT INTO usuario (codigousuario, nomeusuario, grupo) VALUES (?,?,?)");
        query.addBindValue(usu.getCodigoUsuario());
        query.addBindValue(usu.getNomeUsuario());
        query.addBindValue(usu.getGrupo());
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return false;
        }
        db.close();
        return true;
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
        return false;
    }
}

bool UsuarioDAO::atualizaUsuario(Usuario usu) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("UPDATE usuario SET nomeusuario = ?, grupo = ? WHERE codigousuario = ?");
        query.addBindValue(usu.getNomeUsuario());
        query.addBindValue(usu.getGrupo());
        query.addBindValue(usu.getCodigoUsuario());
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return false;
        }
        db.close();
        return true;
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
        return false;
    }
}

bool UsuarioDAO::deletaUsuario(Usuario usu) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("DELETE FROM usuario WHERE codigousuario = ?");
        query.addBindValue(usu.getCodigoUsuario());
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return false;
        }
        db.close();
        return true;
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
        return false;
    }
}
