#include "OrdemDeProducaoDAO.h"

OrdemDeProducaoDAO::OrdemDeProducaoDAO(Conexao *conn) {
    db = conn->getDataBase();
    this->conn = conn;
}

QList <OrdemDeProducao> OrdemDeProducaoDAO::getOPs() {
    QList <OrdemDeProducao> retorno;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT op, CodigoCliente, CodigoMaquina, ordem, QuantidadeProgramada, dataentrega FROM OrdemdeProducao");
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            int i = 0;
            while (query.next()) {

                ClienteDAO cliDAO(conn);
                Cliente * cli = cliDAO.getCliente(query.value(1).toInt());

                MaquinaDAO maqDAO(conn);
                Maquina * maq = maqDAO.getMaquina(query.value(2).toInt());

                OrdemDeProducao dialogOP(query.value(0).toString(), cli, maq, query.value(3).toInt(), query.value(4).toInt(), query.value(5).toDate());
                retorno.insert(i,dialogOP);
                i++;
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

bool OrdemDeProducaoDAO::insereOP(OrdemDeProducao op) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("INSERT INTO OrdemdeProducao (op, CodigoCliente, CodigoMaquina, ordem, QuantidadeProgramada, dataentrega) VALUES (?,?,?,?,?,?)");
        query.addBindValue(op.getOP());
        query.addBindValue(op.getCliente()->getCodigoCliente());
        query.addBindValue(op.getMaquina()->getCodigoMaquina());
        query.addBindValue(op.getOrdem());
        query.addBindValue(op.getQuantidadeProgramada());
        query.addBindValue(op.getDataDeEntrega());
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

bool OrdemDeProducaoDAO::atualizaOP(OrdemDeProducao op) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("UPDATE OrdemdeProducao SET CodigoCliente = ?, CodigoMaquina = ?, ordem = ?, QuantidadeProgramada = ?, dataentrega = ? WHERE op = ?");
        query.addBindValue(op.getCliente()->getCodigoCliente());
        query.addBindValue(op.getMaquina()->getCodigoMaquina());
        query.addBindValue(op.getOrdem());
        query.addBindValue(op.getQuantidadeProgramada());
        query.addBindValue(op.getDataDeEntrega());
        query.addBindValue(op.getOP());
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

bool OrdemDeProducaoDAO::deletaOP(OrdemDeProducao op) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("DELETE FROM OrdemdeProducao WHERE op = ?");
        query.addBindValue(op.getOP());
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
