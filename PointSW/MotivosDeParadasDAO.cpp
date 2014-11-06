#include "MotivosDeParadasDAO.h"

MotivosDeParadasDAO::MotivosDeParadasDAO(QSqlDatabase conn) {
    db = conn;
}

QList <MotivosDeParadas *> MotivosDeParadasDAO::getMotivos() {
    QList <MotivosDeParadas *> retorno;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoParada, Descricao FROM MotivosParada");
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            int i = 0;
            while (query.next()) {
                MotivosDeParadas * dialogMotivo = new MotivosDeParadas(query.value(0).toInt(),query.value(1).toString());
                retorno.insert(i,dialogMotivo);
                i++;
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}

MotivosDeParadas * MotivosDeParadasDAO::getMotivoDeParadas(int mot) {
    MotivosDeParadas * retorno = NULL;
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT CodigoParada, Descricao FROM MotivosParada WHERE CodigoParada = ?");
        query.addBindValue(mot);
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            if(query.first())
                retorno = new MotivosDeParadas(query.value(0).toInt(), query.value(1).toString());
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;
}
