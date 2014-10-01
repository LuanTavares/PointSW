/********************************************************************************
** Form generated from reading UI file 'TelaSetup.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELASETUP_H
#define UI_TELASETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaSetup
{
public:
    QLabel *labelOP;
    QLineEdit *lineEditOP;
    QLabel *label;
    QTimeEdit *timeEditTempo;
    QPushButton *pushButton;

    void setupUi(QWidget *TelaSetup)
    {
        if (TelaSetup->objectName().isEmpty())
            TelaSetup->setObjectName(QStringLiteral("TelaSetup"));
        TelaSetup->resize(408, 167);
        labelOP = new QLabel(TelaSetup);
        labelOP->setObjectName(QStringLiteral("labelOP"));
        labelOP->setGeometry(QRect(40, 35, 40, 16));
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(16);
        labelOP->setFont(font);
        lineEditOP = new QLineEdit(TelaSetup);
        lineEditOP->setObjectName(QStringLiteral("lineEditOP"));
        lineEditOP->setEnabled(false);
        lineEditOP->setGeometry(QRect(80, 28, 291, 31));
        lineEditOP->setFont(font);
        label = new QLabel(TelaSetup);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(6, 81, 70, 21));
        label->setFont(font);
        timeEditTempo = new QTimeEdit(TelaSetup);
        timeEditTempo->setObjectName(QStringLiteral("timeEditTempo"));
        timeEditTempo->setEnabled(false);
        timeEditTempo->setGeometry(QRect(77, 80, 110, 30));
        timeEditTempo->setFont(font);
        pushButton = new QPushButton(TelaSetup);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 80, 191, 51));
        pushButton->setFont(font);

        retranslateUi(TelaSetup);

        QMetaObject::connectSlotsByName(TelaSetup);
    } // setupUi

    void retranslateUi(QWidget *TelaSetup)
    {
        TelaSetup->setWindowTitle(QApplication::translate("TelaSetup", "Form", 0));
        labelOP->setText(QApplication::translate("TelaSetup", "OP:", 0));
        label->setText(QApplication::translate("TelaSetup", "Tempo:", 0));
        timeEditTempo->setDisplayFormat(QApplication::translate("TelaSetup", "HH:mm:ss", 0));
        pushButton->setText(QApplication::translate("TelaSetup", "Iniciar Produ\303\247\303\243o", 0));
    } // retranslateUi

};

namespace Ui {
    class TelaSetup: public Ui_TelaSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELASETUP_H
