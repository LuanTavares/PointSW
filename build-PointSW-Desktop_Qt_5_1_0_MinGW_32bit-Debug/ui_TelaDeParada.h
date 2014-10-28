/********************************************************************************
** Form generated from reading UI file 'TelaDeParada.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELADEPARADA_H
#define UI_TELADEPARADA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_TelaDeParada
{
public:
    QLabel *labelTitulo;
    QLabel *labelMaquina;
    QLabel *labelOP;
    QLabel *labelDataInicio;
    QLabel *labelHorainicio;
    QLabel *labelMotivo;
    QLineEdit *lineEditMaquina;
    QLineEdit *lineEditOP;
    QComboBox *comboBoxMotivo;
    QDateEdit *dateEditDataInicio;
    QTimeEdit *timeEditHoraInicio;
    QPushButton *pushButtonSalvar;

    void setupUi(QDialog *TelaDeParada)
    {
        if (TelaDeParada->objectName().isEmpty())
            TelaDeParada->setObjectName(QStringLiteral("TelaDeParada"));
        TelaDeParada->resize(514, 256);
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        TelaDeParada->setFont(font);
        labelTitulo = new QLabel(TelaDeParada);
        labelTitulo->setObjectName(QStringLiteral("labelTitulo"));
        labelTitulo->setGeometry(QRect(190, 10, 141, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Trebuchet MS"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        labelTitulo->setFont(font1);
        labelMaquina = new QLabel(TelaDeParada);
        labelMaquina->setObjectName(QStringLiteral("labelMaquina"));
        labelMaquina->setGeometry(QRect(20, 50, 71, 21));
        labelOP = new QLabel(TelaDeParada);
        labelOP->setObjectName(QStringLiteral("labelOP"));
        labelOP->setGeometry(QRect(20, 80, 151, 21));
        labelDataInicio = new QLabel(TelaDeParada);
        labelDataInicio->setObjectName(QStringLiteral("labelDataInicio"));
        labelDataInicio->setGeometry(QRect(20, 110, 161, 21));
        labelHorainicio = new QLabel(TelaDeParada);
        labelHorainicio->setObjectName(QStringLiteral("labelHorainicio"));
        labelHorainicio->setGeometry(QRect(20, 140, 161, 21));
        labelMotivo = new QLabel(TelaDeParada);
        labelMotivo->setObjectName(QStringLiteral("labelMotivo"));
        labelMotivo->setGeometry(QRect(20, 190, 61, 16));
        lineEditMaquina = new QLineEdit(TelaDeParada);
        lineEditMaquina->setObjectName(QStringLiteral("lineEditMaquina"));
        lineEditMaquina->setGeometry(QRect(90, 50, 401, 20));
        lineEditOP = new QLineEdit(TelaDeParada);
        lineEditOP->setObjectName(QStringLiteral("lineEditOP"));
        lineEditOP->setGeometry(QRect(170, 80, 321, 20));
        comboBoxMotivo = new QComboBox(TelaDeParada);
        comboBoxMotivo->setObjectName(QStringLiteral("comboBoxMotivo"));
        comboBoxMotivo->setGeometry(QRect(80, 180, 211, 41));
        dateEditDataInicio = new QDateEdit(TelaDeParada);
        dateEditDataInicio->setObjectName(QStringLiteral("dateEditDataInicio"));
        dateEditDataInicio->setGeometry(QRect(180, 110, 110, 22));
        timeEditHoraInicio = new QTimeEdit(TelaDeParada);
        timeEditHoraInicio->setObjectName(QStringLiteral("timeEditHoraInicio"));
        timeEditHoraInicio->setGeometry(QRect(180, 140, 111, 22));
        pushButtonSalvar = new QPushButton(TelaDeParada);
        pushButtonSalvar->setObjectName(QStringLiteral("pushButtonSalvar"));
        pushButtonSalvar->setGeometry(QRect(320, 170, 171, 61));

        retranslateUi(TelaDeParada);

        QMetaObject::connectSlotsByName(TelaDeParada);
    } // setupUi

    void retranslateUi(QDialog *TelaDeParada)
    {
        TelaDeParada->setWindowTitle(QApplication::translate("TelaDeParada", "Dialog", 0));
        labelTitulo->setText(QApplication::translate("TelaDeParada", "Parada de M\303\241quina", 0));
        labelMaquina->setText(QApplication::translate("TelaDeParada", "M\303\241quina:", 0));
        labelOP->setText(QApplication::translate("TelaDeParada", "Ordem de Produ\303\247\303\243o:", 0));
        labelDataInicio->setText(QApplication::translate("TelaDeParada", "Data In\303\255cio da Parada:", 0));
        labelHorainicio->setText(QApplication::translate("TelaDeParada", "Hora In\303\255cio da Parada:", 0));
        labelMotivo->setText(QApplication::translate("TelaDeParada", "Motivo:", 0));
        pushButtonSalvar->setText(QApplication::translate("TelaDeParada", "Salvar", 0));
    } // retranslateUi

};

namespace Ui {
    class TelaDeParada: public Ui_TelaDeParada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELADEPARADA_H
