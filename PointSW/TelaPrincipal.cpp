#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"


TelaPrincipal::TelaPrincipal(Usuario *usuAtu, QSqlDatabase conn, QWidget *parent) : QMainWindow(parent), ui(new Ui::TelaPrincipal) {
    ui->setupUi(this);
    db = conn;
    this->usuAtu = new Usuario(usuAtu);

    opDAO = new OrdemDeProducaoDAO(db);

    ops = opDAO->getOPs();
    ui->filaDeProducao->setRowCount(ops.size());

    for(int i = 0;i <ops.size(); i++) {
        OrdemDeProducao * opDialog = ops.at(i);
        ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,0),new QLineEdit(QString::number(opDialog->getOrdem())));
        ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,1),new QLineEdit(opDialog->getOP()));
        QString tmp = opDialog->getCliente()->getNomeCliente();
        ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,2),new QLineEdit(tmp));
        ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,3),new QLineEdit(QString::number(opDialog->getQuantidadeProgramada())));
        ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,4),new QLineEdit(opDialog->getDataDeEntrega().toString("DD/MM/YYYY")));
        QPushButton * dialogButton = new QPushButton("Iniciar Setup");
        if(i!=0) {
            dialogButton->setEnabled(false);
        }
        ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,5),dialogButton);
        connect(dialogButton, SIGNAL(clicked()), this, SLOT(startaTempoDeSetup()));
    }

}

TelaPrincipal::~TelaPrincipal() {
    delete ui;
}

// Signals
void TelaPrincipal::startaTempoDeSetup() {
    OrdemDeProducao * op = ops.at(0);
    QDate datIni;
    QTime horIni;
    QDate datFim;
    Maquina * maq = new Maquina(op->getMaquina());
    setup = new Setup(maq,op,usuAtu,datIni.currentDate(),horIni.currentTime().minute(),datFim,0);
    tempoDeSetup = new TelaSetup(setup,db);
    tempoDeSetup->show();
}
