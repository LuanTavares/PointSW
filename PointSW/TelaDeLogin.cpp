#include "TelaDeLogin.h"
#include "ui_TelaDeLogin.h"

TelaDeLogin::TelaDeLogin(QWidget *parent) : QWidget(parent), ui(new Ui::TelaDeLogin) {
    ui->setupUi(this);
    QPixmap imagem(":/Imagens/Arquivos/Sopasta - Logotipo JPEG.png");
    ui->labelLogo->setPixmap(imagem);
    conn = new Conexao();
    this->setWindowTitle("PointSW");
    connect(ui->pushButtonLogin, SIGNAL(clicked()), this, SLOT(abreTelaPrincipal()));
}

TelaDeLogin::~TelaDeLogin(){
    delete ui;
}

void TelaDeLogin::abreTelaPrincipal() {
    UsuarioDAO * usuDAO = new UsuarioDAO(conn->getDataBase());
    if (usuDAO->login(ui->lineEditUsuario->text(),ui->lineEditSenha->text())) {
        usu = new Usuario(usuDAO->getUsuarioPorNome(ui->lineEditUsuario->text()));
        telaPrincipal = new TelaPrincipal(usu,conn->getDataBase());
        telaPrincipal->showMaximized();
        this->hide();
    } else {
        QMessageBox erroDeLogin;
        erroDeLogin.setWindowTitle("Erro ao tentar realizar o Login");
        erroDeLogin.setText("Não foi possível realizar o ligin, Usuário ou Senha Incorretos, tente novamente");
        erroDeLogin.setDefaultButton(QMessageBox::Ok);

        if (erroDeLogin.exec() == QMessageBox::Ok) {
            ui->lineEditUsuario->setText("");
            ui->lineEditSenha->setText("");
            erroDeLogin.close();
        }
    }
}
