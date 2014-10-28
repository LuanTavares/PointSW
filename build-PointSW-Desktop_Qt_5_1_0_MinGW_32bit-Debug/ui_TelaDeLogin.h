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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaDeLogin
{
public:
    QPushButton *pushButtonLogin;
    QLabel *labelUsuario;
    QLabel *labelSenha;
    QLineEdit *lineEditUsuario;
    QLineEdit *lineEditSenha;
    QLabel *labelLogo;

    void setupUi(QWidget *TelaDeLogin)
    {
        if (TelaDeLogin->objectName().isEmpty())
            TelaDeLogin->setObjectName(QStringLiteral("TelaDeLogin"));
        TelaDeLogin->resize(492, 274);
        pushButtonLogin = new QPushButton(TelaDeLogin);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(196, 201, 160, 50));
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(16);
        pushButtonLogin->setFont(font);
        labelUsuario = new QLabel(TelaDeLogin);
        labelUsuario->setObjectName(QStringLiteral("labelUsuario"));
        labelUsuario->setGeometry(QRect(44, 129, 81, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Trebuchet MS"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        labelUsuario->setFont(font1);
        labelSenha = new QLabel(TelaDeLogin);
        labelSenha->setObjectName(QStringLiteral("labelSenha"));
        labelSenha->setGeometry(QRect(59, 159, 71, 16));
        labelSenha->setFont(font1);
        lineEditUsuario = new QLineEdit(TelaDeLogin);
        lineEditUsuario->setObjectName(QStringLiteral("lineEditUsuario"));
        lineEditUsuario->setGeometry(QRect(140, 122, 270, 30));
        lineEditSenha = new QLineEdit(TelaDeLogin);
        lineEditSenha->setObjectName(QStringLiteral("lineEditSenha"));
        lineEditSenha->setGeometry(QRect(141, 158, 270, 30));
        labelLogo = new QLabel(TelaDeLogin);
        labelLogo->setObjectName(QStringLiteral("labelLogo"));
        labelLogo->setGeometry(QRect(157, 45, 231, 71));
        labelLogo->setFrameShape(QFrame::NoFrame);

        retranslateUi(TelaDeLogin);

        QMetaObject::connectSlotsByName(TelaDeLogin);
    } // setupUi

    void retranslateUi(QWidget *TelaDeLogin)
    {
        TelaDeLogin->setWindowTitle(QApplication::translate("TelaDeLogin", "Form", 0));
        pushButtonLogin->setText(QApplication::translate("TelaDeLogin", "Entrar", 0));
        labelUsuario->setText(QApplication::translate("TelaDeLogin", "Usu\303\241rio:", 0));
        labelSenha->setText(QApplication::translate("TelaDeLogin", "Senha:", 0));
        labelLogo->setText(QApplication::translate("TelaDeLogin", "Logo", 0));
    } // retranslateUi

};

namespace Ui {
    class TelaDeLogin: public Ui_TelaDeLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELADELOGIN_H
