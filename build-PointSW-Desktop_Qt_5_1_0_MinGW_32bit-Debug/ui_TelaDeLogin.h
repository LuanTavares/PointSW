/********************************************************************************
** Form generated from reading UI file 'TelaDeLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELADELOGIN_H
#define UI_TELADELOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaDeLogin
{
public:
    QPushButton *pushButtonLogin;

    void setupUi(QWidget *TelaDeLogin)
    {
        if (TelaDeLogin->objectName().isEmpty())
            TelaDeLogin->setObjectName(QStringLiteral("TelaDeLogin"));
        TelaDeLogin->resize(320, 240);
        pushButtonLogin = new QPushButton(TelaDeLogin);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(70, 70, 161, 101));
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(16);
        pushButtonLogin->setFont(font);

        retranslateUi(TelaDeLogin);

        QMetaObject::connectSlotsByName(TelaDeLogin);
    } // setupUi

    void retranslateUi(QWidget *TelaDeLogin)
    {
        TelaDeLogin->setWindowTitle(QApplication::translate("TelaDeLogin", "Form", 0));
        pushButtonLogin->setText(QApplication::translate("TelaDeLogin", "Entrar", 0));
    } // retranslateUi

};

namespace Ui {
    class TelaDeLogin: public Ui_TelaDeLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELADELOGIN_H
