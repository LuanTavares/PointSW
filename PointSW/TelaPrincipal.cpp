#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"


TelaPrincipal::TelaPrincipal(Usuario *usuAtu, QSqlDatabase conn, QWidget *parent) : QMainWindow(parent), ui(new Ui::TelaPrincipal) {
    ui->setupUi(this);    
    this->setWindowTitle("Fila de Produção");
    db = conn;
    opDAO = new OrdemDeProducaoDAO(db);
    this->usuAtu = new Usuario(usuAtu);
    connect(ui->actionSelecionar_Porta_Serial,SIGNAL(triggered()),this,SLOT(selecionaPortaSerial()));
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
    tempoDeSetup = new TelaDeSetup(setup,db);

    connect(tempoDeSetup, SIGNAL(atualizaTelaPrincipal(QTime)), this, SLOT(atualizaTempoDeSetup(QTime)));

    QWidget * a = ui->filaDeProducao->indexWidget(ui->filaDeProducao->model()->index(0,5));
    QPushButton * b = new QPushButton(a);
    b->setEnabled(false);
    ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(0,5),b);
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

         QTime * dialogTime = new QTime(0,0,0);
         QLineEdit * lineTempoDeSetup = new QLineEdit(dialogTime->toString("HH:mm:ss"));
         lineTempoDeSetup->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,6),lineTempoDeSetup);

         QLineEdit * lineTempoDeProducao = new QLineEdit(dialogTime->toString("HH:mm:ss"));
         lineTempoDeProducao->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,7),lineTempoDeProducao);

         QLineEdit * lineParadas = new QLineEdit(QString::number(0));
         lineParadas->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,8),lineParadas);

         ui->filaDeProducao->setRowHeight(i,70);
         connect(dialogButton, SIGNAL(clicked()), this, SLOT(startaTempoDeSetup()));
     }

     ui->filaDeProducao->setColumnWidth(0,60);      // Ordem
     ui->filaDeProducao->setColumnWidth(1,150);     // OP
     ui->filaDeProducao->setColumnWidth(2,300);     // Cliente
     ui->filaDeProducao->setColumnWidth(3,100);     // Quantidade
     ui->filaDeProducao->setColumnWidth(4,80);      // Data de Entrega
     ui->filaDeProducao->setColumnWidth(5,120);     // Botão
     ui->filaDeProducao->setColumnWidth(6,130);     // Tempo de Setup
     ui->filaDeProducao->setColumnWidth(7,150);     // Tempo de Produção
     ui->filaDeProducao->setColumnWidth(8,70);      // Quantidade de Paradas

     update();
 }

 void TelaPrincipal::atualizaTempoDeSetup(QTime tempo) {
     QLineEdit * lineTempoDeSetup = new QLineEdit(tempo.toString("HH:mm:ss"));
     lineTempoDeSetup->setEnabled(false);
     ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(0,6),lineTempoDeSetup);
     this->update();
 }

 void TelaPrincipal::selecionaPortaSerial() {

     portaDeComunicacao = new Serial("");

     portaDeComunicacao->show();

     portaDeComunicacao->solicitaleitura(300001,1);


 }
