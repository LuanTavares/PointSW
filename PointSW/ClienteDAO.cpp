#include "ClienteDAO.h"

ClienteDAO::ClienteDAO(Conexao *conn) {
    db = conn->getDataBase();
}

QList <Cliente> ClienteDAO::getClientes() {
    QList <Cliente> retorno;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoCliente, NomeCliente FROM Clientes");
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            int i = 0;
            while (query.next()) {
                Cliente dialogCliente(query.value(0).toInt(), query.value(1).toString());
                retorno.insert(i,dialogCliente);
                i++;
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

Cliente *ClienteDAO::getCliente(int codigoCliente) {
    Cliente * retorno = NULL;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoCliente, NomeCliente FROM Clientes WHERE CodigoCliente = ?");
        query.addBindValue(codigoCliente);
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            retorno = new Cliente(query.value(0).toInt(), query.value(1).toString());
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

bool ClienteDAO::insereCliente(Cliente cli) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("INSERT INTO Clientes (CodigoCliente, NomeCliente) VALUES (?,?)");
        query.addBindValue(cli.getCodigoCliente());
        query.addBindValue(cli.getNomeCliente());
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

bool ClienteDAO::atualizaCliente(Cliente cli) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("UPDATE Clientes SET NomeCliente = ? WHERE CodigoCliente = ?");
        query.addBindValue(cli.getNomeCliente());
        query.addBindValue(cli.getCodigoCliente());
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

bool ClienteDAO::deletaCliente(Cliente cli) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("DELETE FROM Clientes WHERE CodigoCliente = ?");
        query.addBindValue(cli.getCodigoCliente());
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
