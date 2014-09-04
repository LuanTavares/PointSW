#include <QtWidgets>
#include "Conexao.h"
#include <iostream>
#include "Usuario.h"
#include "UsuarioDAO.h"
int main(int argc,char* argv[]) {

    QApplication * app = new QApplication(argc,argv);

    Conexao * con = new Conexao();
    QSqlDatabase db = con->getDataBase();
    if (db.open()) {
        std::cout << "Conectou" << std::endl;
        db.close();
        Usuario tmp(1,"Luan","TI");
        UsuarioDAO dialogDAO(con);
        if (dialogDAO.insereUsuario(tmp)){
            std::cout << "Inserido" << std::endl;
            tmp.setGrupo("Sopasta-TI");
            if(dialogDAO.atualizaUsuario(tmp)) {
                std::cout << "Atualizado" << std::endl;
                if(dialogDAO.deletaUsuario(tmp)) {
                    std::cout << "Deletado" << std::endl;
                } else {
                    std::cout << "Falha ao Deletar" << std::endl;
                }
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

