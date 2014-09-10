#include <QtWidgets>
#include "Conexao.h"
#include <iostream>
#include "OrdemDeProducao.h"
#include "OrdemDeProducaoDAO.h"
int main(int argc,char* argv[]) {

    QApplication * app = new QApplication(argc,argv);

    Conexao * con = new Conexao();
    QSqlDatabase db = con->getDataBase();
    if (db.open()) {
        std::cout << "Conectou" << std::endl;
        db.close();
        ClienteDAO cliDAO(con);
        Cliente * cli = cliDAO.getCliente(3);
        MaquinaDAO maqDAO(con);
        Maquina * maq = maqDAO.getMaquina(1);
        OrdemDeProducao tmp("op001",cli,maq,1,10000,QDate(2014,9,1));
        OrdemDeProducaoDAO dialogDAO(con);
        if (dialogDAO.insereOP(tmp)){
            std::cout << "Inserido" << std::endl;
            maq = maqDAO.getMaquina(1);
            cli = cliDAO.getCliente(3);
            tmp.setMaquina(maq);
            tmp.setCliente(cli);
            tmp.setQuantidadeProgramada(50000);
            if(dialogDAO.atualizaOP(tmp)) {
                std::cout << "Atualizado" << std::endl;

                /*if(dialogDAO.deletaCliente(tmp)) {
                    std::cout << "Deletado" << std::endl;
                } else {
                    std::cout << "Falha ao Deletar" << std::endl;
                }*/
            }  else {
                std::cout << "Falha ao Atualizar" << std::endl;
            }
        } else {
            std::cout << "Falha ao Inserir" << std::endl;
        }
    } else {
        std::cout << "Não Conectou" << std::endl;
    }

    app->exec();
}

