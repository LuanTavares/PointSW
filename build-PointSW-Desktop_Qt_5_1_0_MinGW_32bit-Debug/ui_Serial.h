/********************************************************************************
** Form generated from reading UI file 'Serial.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_H
#define UI_SERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Serial
{
public:
    QPushButton *pushButtonSalvar;
    QLabel *labelPortaSeriais;
    QComboBox *comboBoxPortasSeriais;

    void setupUi(QDialog *Serial)
    {
        if (Serial->objectName().isEmpty())
            Serial->setObjectName(QStringLiteral("Serial"));
        Serial->resize(399, 153);
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(12);
        Serial->setFont(font);
        pushButtonSalvar = new QPushButton(Serial);
        pushButtonSalvar->setObjectName(QStringLiteral("pushButtonSalvar"));
        pushButtonSalvar->setGeometry(QRect(260, 70, 121, 41));
        labelPortaSeriais = new QLabel(Serial);
        labelPortaSeriais->setObjectName(QStringLiteral("labelPortaSeriais"));
        labelPortaSeriais->setGeometry(QRect(112, 15, 171, 31));
        comboBoxPortasSeriais = new QComboBox(Serial);
        comboBoxPortasSeriais->setObjectName(QStringLiteral("comboBoxPortasSeriais"));
        comboBoxPortasSeriais->setGeometry(QRect(30, 70, 221, 41));

        retranslateUi(Serial);

        QMetaObject::connectSlotsByName(Serial);
    } // setupUi

    void retranslateUi(QDialog *Serial)
    {
        Serial->setWindowTitle(QApplication::translate("Serial", "Dialog", 0));
        pushButtonSalvar->setText(QApplication::translate("Serial", "Salvar", 0));
        labelPortaSeriais->setText(QApplication::translate("Serial", "Selecione a Porta Serial", 0));
    } // retranslateUi

};

namespace Ui {
    class Serial: public Ui_Serial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_H
