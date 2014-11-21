#include "ProducaoDAO.h"

ProducaoDAO::ProducaoDAO(QSqlDatabase conn) {
    db = conn;
}

QList <Producao> ProducaoDAO::getProducao() {
    QList <Producao> retorno;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoMaquina, OP, CodigoUsuario, DataInicio, HoraInicio, Contagem, DataFim, HoraFim, Status FROM Producao");
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

                Producao dialogProducao(maq,op,usu,query.value(3).toDate(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toDate(),query.value(7).toInt(),query.value(8).toInt());
                retorno.insert(i,dialogProducao);

                i++;
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

bool ProducaoDAO::insereProducao(Producao producao) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("INSERT INTO Producao (CodigoMaquina, op, CodigoUsuario, DataInicio, HoraInicio, Contagem, DataFim, HoraFim, Status) VALUES (?,?,?,?,?,?,?,?,?)");
        query.addBindValue(producao.getMaquina()->getCodigoMaquina());
        query.addBindValue(producao.getOP()->getOP());
        query.addBindValue(producao.getUsuario()->getCodigoUsuario());
        query.addBindValue(producao.getDataInicio());
        query.addBindValue(producao.getHoraInicio());
        query.addBindValue(producao.getContagem());
        query.addBindValue(producao.getDataFim());
        query.addBindValue(producao.getHoraFim());
        query.addBindValue(producao.getStatus());
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

bool ProducaoDAO::atualizaProducao(Producao producao) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("UPDATE Producao SET Contagem = ?, DataFim = ?, HoraFim = ?, Status = ? WHERE CodigoMaquina = ? AND OP = ? AND CodigoUsuario = ? AND DataInicio = ? AND HoraInicio = ?");
        query.addBindValue(producao.getContagem());
        query.addBindValue(producao.getDataFim());
        query.addBindValue(producao.getHoraFim());
        query.addBindValue(producao.getStatus());
        query.addBindValue(producao.getMaquina()->getCodigoMaquina());
        query.addBindValue(producao.getOP()->getOP());
        query.addBindValue(producao.getUsuario()->getCodigoUsuario());
        query.addBindValue(producao.getDataInicio());
        query.addBindValue(producao.getHoraInicio());
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

bool ProducaoDAO::deletaProducao(Producao producao) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("DELETE FROM Producao WHERE CodigoMaquina = ? AND OP = ? AND CodigoUsuario = ? AND DataInicio = ? AND HoraInicio = ?");
        query.addBindValue(producao.getMaquina()->getCodigoMaquina());
        query.addBindValue(producao.getOP()->getOP());
        query.addBindValue(producao.getUsuario()->getCodigoUsuario());
        query.addBindValue(producao.getDataInicio());
        query.addBindValue(producao.getHoraInicio());
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
