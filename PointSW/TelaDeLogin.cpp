#include "TelaDeLogin.h"
#include "ui_TelaDeLogin.h"

TelaDeLogin::TelaDeLogin(QWidget *parent) : QWidget(parent), ui(new Ui::TelaDeLogin) {
    ui->setupUi(this);
    QPixmap imagem(":/Imagens/Arquivos/Sopasta - Logotipo JPEG.png");
    ui->labelLogo->setPixmap(imagem);
    conn = new Conexao();
    connect(ui->pushButtonLogin, SIGNAL(clicked()), this, SLOT(abreTelaPrincipal()));
}

TelaDeLogin::~TelaDeLogin(){
    delete ui;
}

void TelaDeLogin::abreTelaPrincipal() {
    UsuarioDAO * usuDAO = new UsuarioDAO(conn->getDataBase());
    usu = new Usuario(usuDAO->getUsuario(1));
    telaPrincipal = new TelaPrincipal(usu,conn->getDataBase());
    telaPrincipal->showMaximized();
    this->hide();
}
