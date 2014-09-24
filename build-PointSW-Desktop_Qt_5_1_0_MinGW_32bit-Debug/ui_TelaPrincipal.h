/********************************************************************************
** Form generated from reading UI file 'TelaPrincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAPRINCIPAL_H
#define UI_TELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaPrincipal
{
public:
    QAction *actionSelecionar_Porta_Serial;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Maquina1;
    QTableWidget *filaDeProducao;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TelaPrincipal)
    {
        if (TelaPrincipal->objectName().isEmpty())
            TelaPrincipal->setObjectName(QStringLiteral("TelaPrincipal"));
        TelaPrincipal->resize(800, 599);
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(12);
        TelaPrincipal->setFont(font);
        actionSelecionar_Porta_Serial = new QAction(TelaPrincipal);
        actionSelecionar_Porta_Serial->setObjectName(QStringLiteral("actionSelecionar_Porta_Serial"));
        centralwidget = new QWidget(TelaPrincipal);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 781, 551));
        tabWidget->setFont(font);
        Maquina1 = new QWidget();
        Maquina1->setObjectName(QStringLiteral("Maquina1"));
        filaDeProducao = new QTableWidget(Maquina1);
        if (filaDeProducao->columnCount() < 6)
            filaDeProducao->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        filaDeProducao->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        filaDeProducao->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        filaDeProducao->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        filaDeProducao->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        filaDeProducao->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        filaDeProducao->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        filaDeProducao->setObjectName(QStringLiteral("filaDeProducao"));
        filaDeProducao->setGeometry(QRect(10, -1, 770, 530));
        filaDeProducao->setRowCount(0);
        filaDeProducao->setColumnCount(6);
        filaDeProducao->horizontalHeader()->setCascadingSectionResizes(true);
        filaDeProducao->horizontalHeader()->setDefaultSectionSize(70);
        filaDeProducao->horizontalHeader()->setHighlightSections(true);
        filaDeProducao->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tabWidget->addTab(Maquina1, QString());
        TelaPrincipal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TelaPrincipal);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        TelaPrincipal->setMenuBar(menubar);
        statusbar = new QStatusBar(TelaPrincipal);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TelaPrincipal->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionSelecionar_Porta_Serial);

        retranslateUi(TelaPrincipal);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TelaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *TelaPrincipal)
    {
        TelaPrincipal->setWindowTitle(QApplication::translate("TelaPrincipal", "MainWindow", 0));
        actionSelecionar_Porta_Serial->setText(QApplication::translate("TelaPrincipal", "Selecionar Porta Serial", 0));
        QTableWidgetItem *___qtablewidgetitem = filaDeProducao->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TelaPrincipal", "Ordem", 0));
        QTableWidgetItem *___qtablewidgetitem1 = filaDeProducao->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TelaPrincipal", "OP", 0));
        QTableWidgetItem *___qtablewidgetitem2 = filaDeProducao->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TelaPrincipal", "Cliente", 0));
        QTableWidgetItem *___qtablewidgetitem3 = filaDeProducao->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TelaPrincipal", "Quantidade", 0));
        QTableWidgetItem *___qtablewidgetitem4 = filaDeProducao->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("TelaPrincipal", "Data", 0));
        tabWidget->setTabText(tabWidget->indexOf(Maquina1), QApplication::translate("TelaPrincipal", "Nome da Maquina", 0));
        menuMenu->setTitle(QApplication::translate("TelaPrincipal", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class TelaPrincipal: public Ui_TelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAPRINCIPAL_H
