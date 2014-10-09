#include "SetupDAO.h"

SetupDAO::SetupDAO(QSqlDatabase conn) {
    db = conn;
}

QList <Setup> SetupDAO::getSetups() {
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

                MaquinaDAO maqDAO(db);
                Maquina * maq = maqDAO.getMaquina(query.value(0).toInt());

                OrdemDeProducaoDAO opDAO(db);
                OrdemDeProducao * op = opDAO.getOP(query.value(1).toString());

                UsuarioDAO usuDAO(db);
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

Setup SetupDAO::getSetup(Maquina *maq, OrdemDeProducao *op, Usuario *usu, QDate datIni, int HorIni) {
    Maquina * maquina = new Maquina(maq);
    OrdemDeProducao * ordemDeProducao = new OrdemDeProducao(op);
    Usuario * usuario = new Usuario(usu);

    Setup * retorno;
    if(db.isOpen())
        db.close();

    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT DataFim, HoraFim FROM Setup WHERE CodigoMaquina = ? AND op = ? AND CodigoUsuario = ? AND DataInicio = ? AND HoraInicio = ?");
        query.addBindValue(maquina->getCodigoMaquina());
        query.addBindValue(ordemDeProducao->getOP());
        query.addBindValue(usuario->getCodigoUsuario());
        query.addBindValue(datIni);
        query.addBindValue(HorIni);
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            if (query.first()) {

                retorno = new Setup(maquina,ordemDeProducao,usuario,datIni,HorIni,query.value(0).toDate(),query.value(1).toInt());
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;

}

bool SetupDAO::existeEsteSetup(Setup * set) {
    Setup * setup = new Setup(set);
    bool retorno = false;
    if(db.isOpen())
        db.close();

    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT op FROM Setup WHERE CodigoMaquina = ? AND op = ? AND CodigoUsuario = ? AND DataInicio = ? AND HoraInicio = ?");
        query.addBindValue(setup->getMaquina()->getCodigoMaquina());
        query.addBindValue(setup->getOP()->getOP());
        query.addBindValue(setup->getUsuario()->getCodigoUsuario());
        query.addBindValue(setup->getDataInicio());
        query.addBindValue(setup->getHoraInicio());
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            retorno = false;
            return retorno;
        } else {
            if (query.first()) {
                retorno = true;
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
        query = QSqlQuery(db);/*
        query.prepare("UPDATE Setup SET DataFim = ?, HoraFim = ? WHERE CodigoMaquina = ? AND OP = ? AND CodigoUsuario = ? AND DataInicio = ? AND HoraInicio = ?");
        query.addBindValue(setup.getDataFim().toString("dd/MM/yyyy"));
        query.addBindValue(setup.getHoraFim());
        query.addBindValue(setup.getMaquina()->getCodigoMaquina());
        query.addBindValue(setup.getOP()->getOP());
        query.addBindValue(setup.getUsuario()->getCodigoUsuario());
        query.addBindValue(setup.getDataInicio().toString("dd/MM/yyyy"));
        query.addBindValue(setup.getHoraInicio());

        if (query.isValid()) {
            std::cout << "OK" << std::endl;
        } else {
            std::cout << "Not OK" << std::endl;
        }
*/
        QString sql = "UPDATE Setup SET DataFim = '"+ setup.getDataFim().toString("dd/MM/yyyy");
        sql += "', HoraFim = "+ QString::number(setup.getHoraFim())+ "WHERE CodigoMaquina = "+QString::number(setup.getMaquina()->getCodigoMaquina());
        sql += " AND OP = '" + setup.getOP()->getOP() + "' AND CodigoUsuario = " + QString::number(setup.getUsuario()->getCodigoUsuario());
        sql += " AND DataInicio = '"+ setup.getDataInicio().toString("dd/MM/yyyy");
        sql += "' AND HoraInicio = " +QString::number(setup.getHoraInicio());

        std::cout << sql.toStdString() << std::endl;

        if(!query.exec(sql)){
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
