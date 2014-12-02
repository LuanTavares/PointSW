#include "ParadasDAO.h"

ParadasDAO::ParadasDAO(QSqlDatabase conn) {
    db = conn;
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

                MaquinaDAO maqDAO(db);
                Maquina * maq = maqDAO.getMaquina(query.value(0).toInt());

                OrdemDeProducaoDAO opDAO(db);
                OrdemDeProducao * op = opDAO.getOP(query.value(1).toString());

                UsuarioDAO usuDAO(db);
                Usuario * usu = usuDAO.getUsuario(query.value(2).toInt());

                MotivosDeParadasDAO motDAO(db);
                MotivosDeParadas * mot = motDAO.getMotivoDeParadas(query.value(8).toInt());

                Parada dialogParada(maq,op,usu,query.value(3).toDate(),query.value(4).toInt(),query.value(5).toInt(),query.value(6).toDate(),query.value(7).toInt(),mot);
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

QList <Parada *> ParadasDAO::getParadasSemMotivo() {
    QList <Parada *> retorno;
    if(db.open()) {
        query = QSqlQuery(db);

        query.prepare("SELECT CodigoMaquina, OP, CodigoUsuario, DataInicio, HoraInicio, Sequencia, DataFim, HoraFim, Motivo FROM Paradas WHERE Motivo IS NULL");
        if(query.exec()){
            int i = 0;
            QList < QList <QVariant> > valores;
            while (query.next()) {
                QList <QVariant> dialog;

                QVariant valor0 = query.value(0);
                QVariant valor1 = query.value(1);
                QVariant valor2 = query.value(2);
                QVariant valor3 = query.value(3);
                QVariant valor4 = query.value(4);
                QVariant valor5 = query.value(5);
                QVariant valor6 = query.value(6);
                QVariant valor7 = query.value(7);
                QVariant valor8 = query.value(8);

                dialog.insert(0,valor0);
                dialog.insert(1,valor1);
                dialog.insert(2,valor2);
                dialog.insert(3,valor3);
                dialog.insert(4,valor4);
                dialog.insert(5,valor5);
                dialog.insert(6,valor6);
                dialog.insert(7,valor7);
                dialog.insert(8,valor8);

                valores.insert(i,dialog);
                i++;
            }

            for (int i = 0;i < valores.length(); i++) {
                QList <QVariant> val;
                val = valores.at(i);

                MaquinaDAO maqDAO(db);
                Maquina * maq = maqDAO.getMaquina(val.at(0).toInt());

                OrdemDeProducaoDAO opDAO(db);
                OrdemDeProducao * op = opDAO.getOP(val.at(1).toString());

                UsuarioDAO usuDAO(db);
                Usuario * usu = usuDAO.getUsuario(val.at(2).toInt());

                MotivosDeParadasDAO motDAO(db);
                MotivosDeParadas * mot = motDAO.getMotivoDeParadas(val.at(8).toInt());

                Parada * dialogParada = new Parada(maq, op, usu,val.at(3).toDate(),val.at(4).toInt(),val.at(5).toInt(),val.at(6).toDate(),val.at(7).toInt(),mot);
                retorno.insert(i,dialogParada);

            }

        } else {
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
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
        
        query.prepare("SELECT MAX(sequencia) FROM Paradas WHERE op = ?");
        query.addBindValue(parada.getOP()->getOP());
        
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return false;
        } else {
            if (query.first()) {
                parada.setSequencia(query.value(0).toInt()+1);
            } else {
                parada.setSequencia(1);
            }
            QSqlQuery queryInsert(db);
            queryInsert.prepare("INSERT INTO Paradas (CodigoMaquina, op, CodigoUsuario, DataInicio, HoraInicio, Sequencia, DataFim, HoraFim, Motivo) VALUES (?,?,?,?,?,?,?,?,NULL)");
            queryInsert.addBindValue(parada.getMaquina()->getCodigoMaquina());
            queryInsert.addBindValue(parada.getOP()->getOP());
            queryInsert.addBindValue(parada.getUsuario()->getCodigoUsuario());
            queryInsert.addBindValue(parada.getDataInicio());
            queryInsert.addBindValue(parada.getHoraInicio());
            queryInsert.addBindValue(parada.getSequencia());
            queryInsert.addBindValue(parada.getDataFim());
            queryInsert.addBindValue(parada.getHoraFim());
            if(!queryInsert.exec()){
                std::cout << queryInsert.lastError().text().toStdString() << std::endl;
                db.close();
                return false;
            }
            db.close();
            return true;
        }
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
        query.addBindValue(parada.getMotivo()->getCodigo());
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
