#include "TelaDeLogin.h"
#include "ui_TelaDeLogin.h"

TelaDeLogin::TelaDeLogin(QWidget *parent) : QWidget(parent), ui(new Ui::TelaDeLogin) {
    ui->setupUi(this);
    QPixmap imagem(":/Imagens/Arquivos/Sopasta - Logotipo JPEG.png");
    ui->labelLogo->setPixmap(imagem);
    ui->lineEditSenha->setEchoMode(QLineEdit::Password);
    conn = new Conexao();
    this->setWindowTitle("PointSW");
    connect(ui->pushButtonLogin, SIGNAL(clicked()), this, SLOT(abreTelaPrincipal()));
}

TelaDeLogin::~TelaDeLogin(){
    delete ui;
}

void TelaDeLogin::abreTelaPrincipal() {
    UsuarioDAO * usuDAO = new UsuarioDAO(conn->getDataBase());
    QString usuario = ui->lineEditUsuario->text();
    QString senha = ui->lineEditSenha->text();

    usuario = usuario.toUpper();
    senha = senha.toUpper();

    QString senhaEmMD5 = QString(QCryptographicHash::hash((senha.toLatin1()),QCryptographicHash::Md5).toHex());
    //std::cout << senhaEmMD5.toStdString() << std::endl;
    if (usuDAO->login(usuario,senhaEmMD5)) {
        usu = new Usuario(usuDAO->getUsuarioPorNome(usuario));
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
