/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *lblUsername;
    QLineEdit *txtUsername;
    QLabel *lblPassword;
    QLineEdit *txtPassword;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnConnexion;
    QPushButton *btnQuitter;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(420, 260);
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        lblUsername = new QLabel(groupBox);
        lblUsername->setObjectName("lblUsername");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, lblUsername);

        txtUsername = new QLineEdit(groupBox);
        txtUsername->setObjectName("txtUsername");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, txtUsername);

        lblPassword = new QLabel(groupBox);
        lblPassword->setObjectName("lblPassword");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, lblPassword);

        txtPassword = new QLineEdit(groupBox);
        txtPassword->setObjectName("txtPassword");
        txtPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, txtPassword);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnConnexion = new QPushButton(Dialog);
        btnConnexion->setObjectName("btnConnexion");

        horizontalLayout->addWidget(btnConnexion);

        btnQuitter = new QPushButton(Dialog);
        btnQuitter->setObjectName("btnQuitter");

        horizontalLayout->addWidget(btnQuitter);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Connexion", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "Authentification", nullptr));
        lblUsername->setText(QCoreApplication::translate("Dialog", "Utilisateur :", nullptr));
        txtUsername->setPlaceholderText(QCoreApplication::translate("Dialog", "Nom d'utilisateur", nullptr));
        lblPassword->setText(QCoreApplication::translate("Dialog", "Mot de passe :", nullptr));
        txtPassword->setPlaceholderText(QCoreApplication::translate("Dialog", "Mot de passe", nullptr));
        btnConnexion->setText(QCoreApplication::translate("Dialog", "Connexion", nullptr));
        btnQuitter->setText(QCoreApplication::translate("Dialog", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
