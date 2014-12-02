#include "SerialDAO.h"

SerialDAO::SerialDAO(QSqlDatabase conn) {
    this->db = conn;
    this->hostName = QHostInfo::localHostName();
}

QString SerialDAO::getPortaSerial() {
    QString retorno = "";
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("SELECT PortaCom FROM Configuracao WHERE HostMaquina = ?");
        query.addBindValue(this->hostName);
        if(!query.exec()){
            std::cout << query.lastError().text().toStdString() << std::endl;
            db.close();
            return retorno;
        } else {
            if (query.first()) {
                retorno = query.value(0).toString();
            }
        }
        db.close();
    } else {
        std::cout << db.lastError().text().toStdString() << std::endl;
    }
    return retorno;

}

bool SerialDAO::setPortaSerial(QString porta) {
    if(db.open()) {
        query = QSqlQuery(db);
        query.prepare("INSERT INTO Configuracao (HostMaquina, IpMaquina, PortaCom) VALUES (?,?,?)");
        query.addBindValue(this->hostName);
        query.addBindValue("");
        query.addBindValue(porta);
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
