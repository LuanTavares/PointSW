#include "MaquinaDAO.h"

MaquinaDAO::MaquinaDAO(QSqlDatabase conn) {
    db = QSqlDatabase(conn);
}

QList <Maquina> MaquinaDAO::getMaquinas() {
    QList <Maquina> retorno;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoMaquina, NomeMaquina, StatusMaquina FROM Maquina");
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            int i = 0;
            while (query.next()) {
                Maquina dialogMaquina(query.value(0).toInt(), query.value(1).toString(), query.value(2).toInt());
                retorno.insert(i,dialogMaquina);
                i++;
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

Maquina *MaquinaDAO::getMaquina(int codigoMaquina) {
    Maquina * retorno = NULL;
    if(db.isOpen())
        db.close();

    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoMaquina, NomeMaquina, StatusMaquina FROM Maquina WHERE CodigoMaquina = ?");
        query.addBindValue(codigoMaquina);
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            if (query.first())
                retorno = new Maquina(query.value(0).toInt(), query.value(1).toString(), query.value(2).toInt());
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

bool MaquinaDAO::insereMaquina(Maquina maq) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("INSERT INTO Maquina (NomeMaquina, StatusMaquina) VALUES (?,?)");
        query.addBindValue(maq.getNomemaquina());
        query.addBindValue(maq.getStatus());
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

bool MaquinaDAO::atualizaMaquina(Maquina maq) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("UPDATE Maquina SET NomeMaquina = ?, StatusMaquina = ? WHERE CodigoMaquina = ?");
        query.addBindValue(maq.getNomemaquina());
        query.addBindValue(maq.getStatus());
        query.addBindValue(maq.getCodigoMaquina());
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

bool MaquinaDAO::deletaMaquina(Maquina maq) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("DELETE FROM Maquina WHERE CodigoMaquina = ?");
        query.addBindValue(maq.getCodigoMaquina());
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

