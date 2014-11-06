#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"


TelaPrincipal::TelaPrincipal(Usuario *usuAtu, QSqlDatabase conn, QWidget *parent) : QMainWindow(parent), ui(new Ui::TelaPrincipal) {
    ui->setupUi(this);
    this->setWindowTitle("Fila de Produção");
    db = conn;
    opDAO = new OrdemDeProducaoDAO(db);
    this->usuAtu = new Usuario(usuAtu);
    if (usuAtu->getGrupo() != "TI")
        ui->menubar->setVisible(false);

    SerialDAO dialogDAO = SerialDAO(db);

    if (dialogDAO.getPortaSerial().size() == 0) {
        std::cout << "Não achou a porta Serial para este Computador." << std::endl;
    } else {
        portaDeComunicacao = new Serial(dialogDAO.getPortaSerial());
    }

    leDadosImpressora = new QTimer();
    connect(ui->actionSelecionar_Porta_Serial,SIGNAL(triggered()),this,SLOT(selecionaPortaSerial()));
    connect(this->leDadosImpressora, SIGNAL(timeout()), this, SLOT(leDados()));

    procuraParadasSemMotivos();
}

TelaPrincipal::~TelaPrincipal() {
    delete ui;
}

// Slots
void TelaPrincipal::startaTempoDeSetup() {
    OrdemDeProducao * op = ops.at(0);
    QDate datIni;
    QTime horIni;
    QDate datFim;
    Maquina * maq = new Maquina(op->getMaquina());
    setup = new Setup(maq,op,usuAtu,datIni.currentDate(),horIni.currentTime().minute(),datFim,0);
    tempoDeSetup = new TelaDeSetup(setup,db);

    connect(tempoDeSetup, SIGNAL(atualizaTelaPrincipal(QTime)), this, SLOT(atualizaTempoDeSetup(QTime)));

    botoes.at(0)->setEnabled(false);

    leDadosImpressora->start(60000);
    this->update();

}

void TelaPrincipal::startaTempoDeProducao() {
    OrdemDeProducao * op = ops.at(0);
    QDate datIni;
    QTime horIni;
    QDate datFim;
    Maquina * maq = new Maquina(op->getMaquina());
    producao = new Producao(maq,op,usuAtu,datIni.currentDate(),horIni.currentTime().minute(),0,datFim,0,0);
    tempoDeProducao = new TelaDeProducao(producao,db);

    connect(tempoDeProducao, SIGNAL(atualizaTelaPrincipal(QTime)), this, SLOT(atualizaTempoDeProducao(QTime)));

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

         QTime * dialogTime = new QTime(0,0,0);
         QLineEdit * lineTempoDeSetup = new QLineEdit(dialogTime->toString("HH:mm:ss"));
         lineTempoDeSetup->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,5),lineTempoDeSetup);

         QLineEdit * lineTempoDeProducao = new QLineEdit(dialogTime->toString("HH:mm:ss"));
         lineTempoDeProducao->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,6),lineTempoDeProducao);

         QLineEdit * lineParadas = new QLineEdit(QString::number(0));
         lineParadas->setEnabled(false);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,7),lineParadas);

         QPushButton * dialogButton = new QPushButton("Iniciar Setup");
         if(i!=0) {
             dialogButton->setEnabled(false);
         }
         botoes.insert(i,dialogButton);
         ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(i,8),dialogButton);

         ui->filaDeProducao->setRowHeight(i,70);
         connect(dialogButton, SIGNAL(clicked()), this, SLOT(startaTempoDeSetup()));
     }

     ui->filaDeProducao->setColumnWidth(0,60);      // Ordem
     ui->filaDeProducao->setColumnWidth(1,150);     // OP
     ui->filaDeProducao->setColumnWidth(2,300);     // Cliente
     ui->filaDeProducao->setColumnWidth(3,100);     // Quantidade
     ui->filaDeProducao->setColumnWidth(4,80);      // Data de Entrega
     ui->filaDeProducao->setColumnWidth(5,130);     // Tempo de Setup
     ui->filaDeProducao->setColumnWidth(6,150);     // Tempo de Produção
     ui->filaDeProducao->setColumnWidth(7,70);      // Quantidade de Paradas
     ui->filaDeProducao->setColumnWidth(8,120);     // Botão

     update();
 }

 void TelaPrincipal::atualizaTempoDeSetup(QTime tempo) {
     QLineEdit * lineTempoDeSetup = new QLineEdit(tempo.toString("HH:mm:ss"));
     lineTempoDeSetup->setEnabled(false);
     ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(0,5),lineTempoDeSetup);
     this->update();
 }

 void TelaPrincipal::atualizaTempoDeProducao(QTime tempo) {
     QLineEdit * lineTempoDeProducao = new QLineEdit(tempo.toString("HH:mm:ss"));
     lineTempoDeProducao->setEnabled(false);
     ui->filaDeProducao->setIndexWidget(ui->filaDeProducao->model()->index(0,6),lineTempoDeProducao);
     this->update();
 }

 void TelaPrincipal::selecionaPortaSerial() {
     portaDeComunicacao = new Serial(db);
     portaDeComunicacao->show();
 }

 void TelaPrincipal::leDados() {
     // Le dados da porta serial
     if (true/* Implementar para saber se já saiu do setup */) {
         tempoDeSetup->acabouSetup();
         delete tempoDeSetup;
         // Starta tempo de produção
         startaTempoDeProducao();
     } else {

     }
 }

 void TelaPrincipal::procuraParadasSemMotivos() {
     ParadasDAO * parDAO = new ParadasDAO(db);
     paradas.clear();
     paradas = parDAO->getParadasSemMotivo();

     if(!paradas.isEmpty()) {
         Parada * dialogParada = paradas.at(0);
         TelaDeParada * dialogTelaDeParada = new TelaDeParada(dialogParada,db);
         connect(dialogTelaDeParada, SIGNAL(destroyed()), this, SLOT(procuraParadasSemMotivos()));
         dialogTelaDeParada->show();
     } else {
         carrgaFilaDeProducao();
     }
 }
