#include "SetupDAO.h"

SetupDAO::SetupDAO(Conexao *conn) {
    db = conn->getDataBase();
    this->conn = conn;
}

QList <Setup> SetupDAO::getSetup() {
    QList <Setup> retorno;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoMaquina, OP, CodigoUsuario, DataInicio, HoraInicio, DataFim, HoraFim FROM Setup");
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            int i = 0;
            while (query.next()) {

                MaquinaDAO maqDAO(conn);
                Maquina * maq = maqDAO.getMaquina(query.value(0).toInt());

                OrdemDeProducaoDAO opDAO(conn);
                OrdemDeProducao * op = opDAO.getOP(query.value(1).toInt());

                UsuarioDAO usuDAO(conn);
                Usuario * usu = usuDAO.getUsuario(query.value(2).toInt());

                Setup dialogSetup(maq,op,usu,query.value(3).toDate(),query.value(4).toInt(),query.value(5).toDate(),query.value(6).toInt());
                retorno.insert(i,dialogSetup);

                i++;
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

bool SetupDAO::insereSetup(Setup setup) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("INSERT INTO Setup (CodigoMaquina, op, CodigoUsuario, DataInicio, HoraInicio, DataFim, HoraFim) VALUES (?,?,?,?,?,?,?)");
        query.addBindValue(setup.getMaquina()->getCodigoMaquina());
        query.addBindValue(setup.getOP()->getOP());
        query.addBindValue(setup.getUsuario()->getCodigoUsuario());
        query.addBindValue(setup.getDataInicio());
        query.addBindValue(setup.getHoraInicio());
        query.addBindValue(setup.getDataFim());
        query.addBindValue(setup.getHoraFim());
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

bool SetupDAO::atualizaSetup(Setup setup) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("UPDATE Setup SET DataFim = ?, HoraFim = ? WHERE CodigoMaquina = ? AND OP = ? AND CodigoUsuario = ? AND DataInicio = ? AND HoraInicio = ?");
        query.addBindValue(setup.getDataFim());
        query.addBindValue(setup.getHoraFim());
        query.addBindValue(setup.getMaquina()->getCodigoMaquina());
        query.addBindValue(setup.getOP()->getOP());
        query.addBindValue(setup.getUsuario()->getCodigoUsuario());
        query.addBindValue(setup.getDataInicio());
        query.addBindValue(setup.getHoraInicio());
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

bool SetupDAO::deletaSetup(Setup setup) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("DELETE FROM Setup WHERE CodigoMaquina = ? AND OP = ? AND CodigoUsuario = ? AND DataInicio = ? AND HoraInicio = ?");
        query.addBindValue(setup.getMaquina()->getCodigoMaquina());
        query.addBindValue(setup.getOP()->getOP());
        query.addBindValue(setup.getUsuario()->getCodigoUsuario());
        query.addBindValue(setup.getDataInicio());
        query.addBindValue(setup.getHoraInicio());
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
