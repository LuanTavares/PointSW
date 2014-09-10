#include "ParadasDAO.h"

ParadasDAO::ParadasDAO(Conexao *conn) {
    db = conn->getDataBase();
    this->conn = conn;
}

QList <Parada> ParadasDAO::getParada() {
    QList <Parada> retorno;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoMaquina, OP, CodigoUsuario, DataInicio, HoraInicio, Sequencia, DataFim, HoraFim, Motivo FROM Paradas");
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

                Parada dialogParada(maq,op,usu,query.value(3).toDate(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toDate(),query.value(7).toInt(),query.value(8).toInt());
                retorno.insert(i,dialogParada);

                i++;
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

bool ParadasDAO::insereParada(Parada parada) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("INSERT INTO Paradas (CodigoMaquina, op, CodigoUsuario, DataInicio, HoraInicio, Sequencia, DataFim, HoraFim, Motivo) VALUES (?,?,?,?,?,?,?,?,?)");
        query.addBindValue(parada.getMaquina()->getCodigoMaquina());
        query.addBindValue(parada.getOP()->getOP());
        query.addBindValue(parada.getUsuario()->getCodigoUsuario());
        query.addBindValue(parada.getDataInicio());
        query.addBindValue(parada.getHoraInicio());
        query.addBindValue(parada.getSequencia());
        query.addBindValue(parada.getDataFim());
        query.addBindValue(parada.getHoraFim());
        query.addBindValue(parada.getMotivo());
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

bool ParadasDAO::atualizaParada(Parada parada) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("UPDATE Paradas SET DataFim = ?, HoraFim = ?, Motivo = ? WHERE CodigoMaquina = ? AND OP = ? AND CodigoUsuario = ? AND DataInicio = ? AND HoraInicio = ? AND Sequencia = ? ");
        query.addBindValue(parada.getDataFim());
        query.addBindValue(parada.getHoraFim());
        query.addBindValue(parada.getMotivo());
        query.addBindValue(parada.getMaquina()->getCodigoMaquina());
        query.addBindValue(parada.getOP()->getOP());
        query.addBindValue(parada.getUsuario()->getCodigoUsuario());
        query.addBindValue(parada.getDataInicio());
        query.addBindValue(parada.getHoraInicio());
        query.addBindValue(parada.getSequencia());
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

bool ParadasDAO::deletaParada(Parada parada) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("DELETE FROM Paradas WHERE CodigoMaquina = ? AND OP = ? AND CodigoUsuario = ? AND DataInicio = ? AND HoraInicio = ? AND Sequencia = ?");
        query.addBindValue(parada.getMaquina()->getCodigoMaquina());
        query.addBindValue(parada.getOP()->getOP());
        query.addBindValue(parada.getUsuario()->getCodigoUsuario());
        query.addBindValue(parada.getDataInicio());
        query.addBindValue(parada.getHoraInicio());
        query.addBindValue(parada.getSequencia());
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
