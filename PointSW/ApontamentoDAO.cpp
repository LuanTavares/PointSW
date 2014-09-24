#include "ApontamentoDAO.h"

ApontamentoDAO::ApontamentoDAO(QSqlDatabase conn) {
    db = conn;
}

QList <Apontamento> ApontamentoDAO::getApontamento() {
    QList <Apontamento> retorno;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoMaquina, OP, CodigoUsuario, TempoDeSetup, TempoDeProducao, QuantidadeProduzida, QuantidadeDeParadas FROM Apontamentos");
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            int i = 0;
            while (query.next()) {

                MaquinaDAO maqDAO(db);
                Maquina * maq = maqDAO.getMaquina(query.value(0).toInt());

                OrdemDeProducaoDAO opDAO(db);
                OrdemDeProducao * op = opDAO.getOP(query.value(1).toString());

                UsuarioDAO usuDAO(db);
                Usuario * usu = usuDAO.getUsuario(query.value(2).toInt());

                Apontamento dialogApontamento(maq,op,usu,query.value(3).toInt(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toInt());
                retorno.insert(i,dialogApontamento);

                i++;
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

bool ApontamentoDAO::insereApontamento(Apontamento apontamento) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("INSERT INTO Apontamentos (CodigoMaquina, op, CodigoUsuario, TempoDeSetup, TempoDeProducao, QuantidadeProduzida, QuantidadeDeParadas) VALUES (?,?,?,?,?,?,?)");
        query.addBindValue(apontamento.getMaquina()->getCodigoMaquina());
        query.addBindValue(apontamento.getOP()->getOP());
        query.addBindValue(apontamento.getUsuario()->getCodigoUsuario());
        query.addBindValue(apontamento.getTempoDeSetup());
        query.addBindValue(apontamento.getTempoDeProducao());
        query.addBindValue(apontamento.getQuantidadeProduzida());
        query.addBindValue(apontamento.getQuantidadeDeParadas());
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

bool ApontamentoDAO::atualizaApontamento(Apontamento apontamento) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("UPDATE Apontamentos SET TempoDeSetup = ?, TempoDeProducao = ?, QuantidadeProduzida = ?, QuantidadeDeParadas = ? WHERE CodigoMaquina = ? AND OP = ? AND CodigoUsuario = ?");
        query.addBindValue(apontamento.getTempoDeSetup());
        query.addBindValue(apontamento.getTempoDeProducao());
        query.addBindValue(apontamento.getQuantidadeProduzida());
        query.addBindValue(apontamento.getQuantidadeDeParadas());
        query.addBindValue(apontamento.getMaquina()->getCodigoMaquina());
        query.addBindValue(apontamento.getOP()->getOP());
        query.addBindValue(apontamento.getUsuario()->getCodigoUsuario());
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

bool ApontamentoDAO::deletaApontamento(Apontamento apontamento) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("DELETE FROM Apontamentos WHERE CodigoMaquina = ? AND OP = ? AND CodigoUsuario = ?");
        query.addBindValue(apontamento.getMaquina()->getCodigoMaquina());
        query.addBindValue(apontamento.getOP()->getOP());
        query.addBindValue(apontamento.getUsuario()->getCodigoUsuario());
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
