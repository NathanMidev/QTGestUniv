/********************************************************************************
** Form generated from reading UI file 'etudiant.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ETUDIANT_H
#define UI_ETUDIANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupFormulaire;
    QGridLayout *gridLayout;
    QLabel *lblMatricule;
    QLineEdit *txtMatricule;
    QLabel *lblFiliereId;
    QSpinBox *spinFiliereId;
    QLabel *lblNom;
    QLineEdit *txtNom;
    QLabel *lblNiveau;
    QLineEdit *txtNiveau;
    QLabel *lblPrenom;
    QLineEdit *txtPrenom;
    QLabel *lblEmail;
    QLineEdit *txtEmail;
    QLabel *lblTelephone;
    QLineEdit *txtTelephone;
    QLabel *lblRecherche;
    QLineEdit *txtRecherche;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnRechercher;
    QPushButton *btnActualiser;
    QTableWidget *tableEtudiants;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1000, 650);
        verticalLayout_2 = new QVBoxLayout(Form);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupFormulaire = new QGroupBox(Form);
        groupFormulaire->setObjectName("groupFormulaire");
        gridLayout = new QGridLayout(groupFormulaire);
        gridLayout->setObjectName("gridLayout");
        lblMatricule = new QLabel(groupFormulaire);
        lblMatricule->setObjectName("lblMatricule");

        gridLayout->addWidget(lblMatricule, 0, 0, 1, 1);

        txtMatricule = new QLineEdit(groupFormulaire);
        txtMatricule->setObjectName("txtMatricule");

        gridLayout->addWidget(txtMatricule, 0, 1, 1, 1);

        lblFiliereId = new QLabel(groupFormulaire);
        lblFiliereId->setObjectName("lblFiliereId");

        gridLayout->addWidget(lblFiliereId, 0, 2, 1, 1);

        spinFiliereId = new QSpinBox(groupFormulaire);
        spinFiliereId->setObjectName("spinFiliereId");
        spinFiliereId->setMinimum(0);
        spinFiliereId->setMaximum(999);

        gridLayout->addWidget(spinFiliereId, 0, 3, 1, 1);

        lblNom = new QLabel(groupFormulaire);
        lblNom->setObjectName("lblNom");

        gridLayout->addWidget(lblNom, 1, 0, 1, 1);

        txtNom = new QLineEdit(groupFormulaire);
        txtNom->setObjectName("txtNom");

        gridLayout->addWidget(txtNom, 1, 1, 1, 1);

        lblNiveau = new QLabel(groupFormulaire);
        lblNiveau->setObjectName("lblNiveau");

        gridLayout->addWidget(lblNiveau, 1, 2, 1, 1);

        txtNiveau = new QLineEdit(groupFormulaire);
        txtNiveau->setObjectName("txtNiveau");

        gridLayout->addWidget(txtNiveau, 1, 3, 1, 1);

        lblPrenom = new QLabel(groupFormulaire);
        lblPrenom->setObjectName("lblPrenom");

        gridLayout->addWidget(lblPrenom, 2, 0, 1, 1);

        txtPrenom = new QLineEdit(groupFormulaire);
        txtPrenom->setObjectName("txtPrenom");

        gridLayout->addWidget(txtPrenom, 2, 1, 1, 1);

        lblEmail = new QLabel(groupFormulaire);
        lblEmail->setObjectName("lblEmail");

        gridLayout->addWidget(lblEmail, 2, 2, 1, 1);

        txtEmail = new QLineEdit(groupFormulaire);
        txtEmail->setObjectName("txtEmail");

        gridLayout->addWidget(txtEmail, 2, 3, 1, 1);

        lblTelephone = new QLabel(groupFormulaire);
        lblTelephone->setObjectName("lblTelephone");

        gridLayout->addWidget(lblTelephone, 3, 0, 1, 1);

        txtTelephone = new QLineEdit(groupFormulaire);
        txtTelephone->setObjectName("txtTelephone");

        gridLayout->addWidget(txtTelephone, 3, 1, 1, 1);

        lblRecherche = new QLabel(groupFormulaire);
        lblRecherche->setObjectName("lblRecherche");

        gridLayout->addWidget(lblRecherche, 3, 2, 1, 1);

        txtRecherche = new QLineEdit(groupFormulaire);
        txtRecherche->setObjectName("txtRecherche");

        gridLayout->addWidget(txtRecherche, 3, 3, 1, 1);


        verticalLayout_2->addWidget(groupFormulaire);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnAjouter = new QPushButton(Form);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayout->addWidget(btnAjouter);

        btnModifier = new QPushButton(Form);
        btnModifier->setObjectName("btnModifier");

        horizontalLayout->addWidget(btnModifier);

        btnSupprimer = new QPushButton(Form);
        btnSupprimer->setObjectName("btnSupprimer");

        horizontalLayout->addWidget(btnSupprimer);

        btnRechercher = new QPushButton(Form);
        btnRechercher->setObjectName("btnRechercher");

        horizontalLayout->addWidget(btnRechercher);

        btnActualiser = new QPushButton(Form);
        btnActualiser->setObjectName("btnActualiser");

        horizontalLayout->addWidget(btnActualiser);


        verticalLayout_2->addLayout(horizontalLayout);

        tableEtudiants = new QTableWidget(Form);
        if (tableEtudiants->columnCount() < 8)
            tableEtudiants->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableEtudiants->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableEtudiants->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableEtudiants->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableEtudiants->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableEtudiants->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableEtudiants->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableEtudiants->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableEtudiants->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableEtudiants->setObjectName("tableEtudiants");
        tableEtudiants->setColumnCount(8);

        verticalLayout_2->addWidget(tableEtudiants);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "\303\211tudiants", nullptr));
        groupFormulaire->setTitle(QCoreApplication::translate("Form", "Informations \303\251tudiant", nullptr));
        lblMatricule->setText(QCoreApplication::translate("Form", "Matricule :", nullptr));
        lblFiliereId->setText(QCoreApplication::translate("Form", "Fili\303\250re ID :", nullptr));
        lblNom->setText(QCoreApplication::translate("Form", "Nom :", nullptr));
        lblNiveau->setText(QCoreApplication::translate("Form", "Niveau :", nullptr));
        lblPrenom->setText(QCoreApplication::translate("Form", "Pr\303\251nom :", nullptr));
        lblEmail->setText(QCoreApplication::translate("Form", "Email :", nullptr));
        lblTelephone->setText(QCoreApplication::translate("Form", "T\303\251l\303\251phone :", nullptr));
        lblRecherche->setText(QCoreApplication::translate("Form", "Recherche :", nullptr));
        btnAjouter->setText(QCoreApplication::translate("Form", "Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("Form", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("Form", "Supprimer", nullptr));
        btnRechercher->setText(QCoreApplication::translate("Form", "Rechercher", nullptr));
        btnActualiser->setText(QCoreApplication::translate("Form", "Actualiser", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableEtudiants->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Form", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableEtudiants->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Form", "Matricule", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableEtudiants->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Form", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableEtudiants->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Form", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableEtudiants->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Form", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableEtudiants->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Form", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableEtudiants->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Form", "Niveau", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableEtudiants->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Form", "Fili\303\250re", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ETUDIANT_H
