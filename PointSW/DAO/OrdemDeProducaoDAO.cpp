#include "OrdemDeProducaoDAO.h"

OrdemDeProducaoDAO::OrdemDeProducaoDAO(QSqlDatabase conn) {
    db = conn;
}

QList <OrdemDeProducao *> OrdemDeProducaoDAO::getOPs() {
    QList <OrdemDeProducao *> retorno;
    int i = 0;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT * FROM OrdemdeProducao WHERE op not in (select op from producao where status = 3) ORDER BY ordem");
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            QList < QList <QVariant> > valores;
            while (query.next()) {
                QList <QVariant> dialog;

                QVariant valor0 = query.value(0);
                QVariant valor1 = query.value(1);
                QVariant valor2 = query.value(2);
                QVariant valor3 = query.value(3);
                QVariant valor4 = query.value(4);
                QVariant valor5 = query.value(5);

                dialog.insert(0,valor0);
                dialog.insert(1,valor1);
                dialog.insert(2,valor2);
                dialog.insert(3,valor3);
                dialog.insert(4,valor4);
                dialog.insert(5,valor5);

                valores.insert(i,dialog);
                i++;
            }

            for (int i = 0;i < valores.length(); i++) {
                QList <QVariant> val;
                val = valores.at(i);
                ClienteDAO * cliDAO = new ClienteDAO(db);
                Cliente * cli = cliDAO->getCliente(val.at(1).toInt());
                MaquinaDAO * maqDAO = new MaquinaDAO(db);
                Maquina * maq = maqDAO->getMaquina(val.at(2).toInt());
                OrdemDeProducao * dialog = new OrdemDeProducao(val.at(0).toString(),cli,maq,val.at(3).toInt(),val.at(4).toInt(),val.at(5).toDate());
                retorno.insert(i,dialog);
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

OrdemDeProducao *OrdemDeProducaoDAO::getOP(QString op) {
    OrdemDeProducao * retorno = NULL;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT OP, CodigoCliente, Maquina, Ordem, QuantidadeProgramada, DataDeEntrega FROM OrdemDeProducao WHERE OP = ?");
        query.addBindValue(op);
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            if (query.first()) {

                QVariant valor0 = query.value(0);
                QVariant valor1 = query.value(1);
                QVariant valor2 = query.value(2);
                QVariant valor3 = query.value(3);
                QVariant valor4 = query.value(4);
                QVariant valor5 = query.value(5);


                ClienteDAO cliDAO(db);
                Cliente * cli = cliDAO.getCliente(valor1.toInt());

                MaquinaDAO maqDAO(db);
                Maquina * maq = maqDAO.getMaquina(valor2.toInt());

                retorno = new OrdemDeProducao(valor0.toString(), cli, maq, valor3.toInt(), valor4.toInt(), valor5.toDate());
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
        query.prepare("INSERT INTO OrdemdeProducao (op, CodigoCliente, Maquina, ordem, QuantidadeProgramada, datadeentrega) VALUES (?,?,?,?,?,?)");
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
        query.prepare("UPDATE OrdemdeProducao SET CodigoCliente = ?, Maquina = ?, ordem = ?, QuantidadeProgramada = ?, datadeentrega = ? WHERE op = ?");
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
