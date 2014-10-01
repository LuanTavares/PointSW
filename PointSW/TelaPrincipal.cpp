#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"


TelaPrincipal::TelaPrincipal(Usuario *usuAtu, QSqlDatabase conn, QWidget *parent) : QMainWindow(parent), ui(new Ui::TelaPrincipal) {
    ui->setupUi(this);    
    this->setWindowTitle("Fila de Produção");
    db = conn;
    opDAO = new OrdemDeProducaoDAO(db);
    this->usuAtu = new Usuario(usuAtu);
    carrgaFilaDeProducao();
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


    QWidget * a = ui->filaDeProducao->indexWidget(ui->filaDeProducao->model()->index(0,5));
    QPushButton * b = new QPushButton(a);
    b->setEnabled(false);
    this->update();

}
 void TelaPrincipal::carrgaFilaDeProducao() {

     ops = opDAO->getOPs();
     ui->filaDeProducao->setRowCount(ops.size());

     for(int i = 0;i <ops.size(); i++) {
         OrdemDeProducao * opDialog = ops.at(i);

         QLineEdit * lineOrdem = new QLineEdit(QString::number(opDialog->getOrdem()));
         lineOrdem->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,0),lineOrdem);

         QLineEdit * lineOp = new QLineEdit(opDialog->getOP());
         lineOp->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,1),lineOp);

         QString tmp = opDialog->getCliente()->getNomeCliente();
         QLineEdit * lineCliente = new QLineEdit(tmp);
         lineCliente->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,2), lineCliente);

         QLineEdit * lineQuantidade = new QLineEdit(QString::number(opDialog->getQuantidadeProgramada()));
         lineQuantidade->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,3),lineQuantidade);

         QLineEdit * lineDataEntrega = new QLineEdit(opDialog->getDataDeEntrega().toString("dd/MM/yyyy"));
         lineDataEntrega->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,4),lineDataEntrega);

         QPushButton * dialogButton = new QPushButton("Iniciar Setup");
         if(i!=0) {
             dialogButton->setEnabled(false);
         }
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,5),dialogButton);

         ui->filaDeProducao->setRowHeight(i,70);
         connect(dialogButton, SIGNAL(clicked()), this, SLOT(startaTempoDeSetup()));
     }

     ui->filaDeProducao->setColumnWidth(0,60);
     ui->filaDeProducao->setColumnWidth(1,300);
     ui->filaDeProducao->setColumnWidth(2,300);
     ui->filaDeProducao->setColumnWidth(3,100);
     ui->filaDeProducao->setColumnWidth(4,100);
     ui->filaDeProducao->setColumnWidth(5,140);


     update();
 }
