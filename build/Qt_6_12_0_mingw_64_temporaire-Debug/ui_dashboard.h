/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *lblTitreDashboard;
    QGridLayout *gridLayout;
    QGroupBox *groupEtudiants;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblEtudiants;
    QGroupBox *groupEnseignants;
    QVBoxLayout *verticalLayout_4;
    QLabel *lblEnseignants;
    QGroupBox *groupMatieres;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblMatieres;
    QGroupBox *groupNotes;
    QVBoxLayout *verticalLayout_6;
    QLabel *lblNotes;
    QGroupBox *groupMoyenne;
    QVBoxLayout *verticalLayout_7;
    QLabel *lblMoyenneGenerale;

    void setupUi(QWidget *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(900, 600);
        verticalLayout_2 = new QVBoxLayout(Dashboard);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lblTitreDashboard = new QLabel(Dashboard);
        lblTitreDashboard->setObjectName("lblTitreDashboard");
        lblTitreDashboard->setAlignment(Qt::AlignCenter);
        lblTitreDashboard->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold;"));

        verticalLayout_2->addWidget(lblTitreDashboard);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        groupEtudiants = new QGroupBox(Dashboard);
        groupEtudiants->setObjectName("groupEtudiants");
        verticalLayout_3 = new QVBoxLayout(groupEtudiants);
        verticalLayout_3->setObjectName("verticalLayout_3");
        lblEtudiants = new QLabel(groupEtudiants);
        lblEtudiants->setObjectName("lblEtudiants");
        lblEtudiants->setAlignment(Qt::AlignCenter);
        lblEtudiants->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_3->addWidget(lblEtudiants);


        gridLayout->addWidget(groupEtudiants, 0, 0, 1, 1);

        groupEnseignants = new QGroupBox(Dashboard);
        groupEnseignants->setObjectName("groupEnseignants");
        verticalLayout_4 = new QVBoxLayout(groupEnseignants);
        verticalLayout_4->setObjectName("verticalLayout_4");
        lblEnseignants = new QLabel(groupEnseignants);
        lblEnseignants->setObjectName("lblEnseignants");
        lblEnseignants->setAlignment(Qt::AlignCenter);
        lblEnseignants->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_4->addWidget(lblEnseignants);


        gridLayout->addWidget(groupEnseignants, 0, 1, 1, 1);

        groupMatieres = new QGroupBox(Dashboard);
        groupMatieres->setObjectName("groupMatieres");
        verticalLayout_5 = new QVBoxLayout(groupMatieres);
        verticalLayout_5->setObjectName("verticalLayout_5");
        lblMatieres = new QLabel(groupMatieres);
        lblMatieres->setObjectName("lblMatieres");
        lblMatieres->setAlignment(Qt::AlignCenter);
        lblMatieres->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_5->addWidget(lblMatieres);


        gridLayout->addWidget(groupMatieres, 1, 0, 1, 1);

        groupNotes = new QGroupBox(Dashboard);
        groupNotes->setObjectName("groupNotes");
        verticalLayout_6 = new QVBoxLayout(groupNotes);
        verticalLayout_6->setObjectName("verticalLayout_6");
        lblNotes = new QLabel(groupNotes);
        lblNotes->setObjectName("lblNotes");
        lblNotes->setAlignment(Qt::AlignCenter);
        lblNotes->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold;"));

        verticalLayout_6->addWidget(lblNotes);


        gridLayout->addWidget(groupNotes, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        groupMoyenne = new QGroupBox(Dashboard);
        groupMoyenne->setObjectName("groupMoyenne");
        verticalLayout_7 = new QVBoxLayout(groupMoyenne);
        verticalLayout_7->setObjectName("verticalLayout_7");
        lblMoyenneGenerale = new QLabel(groupMoyenne);
        lblMoyenneGenerale->setObjectName("lblMoyenneGenerale");
        lblMoyenneGenerale->setAlignment(Qt::AlignCenter);
        lblMoyenneGenerale->setStyleSheet(QString::fromUtf8("font-size: 30px; font-weight: bold; color: darkgreen;"));

        verticalLayout_7->addWidget(lblMoyenneGenerale);


        verticalLayout_2->addWidget(groupMoyenne);


        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QWidget *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Dashboard", nullptr));
        lblTitreDashboard->setText(QCoreApplication::translate("Dashboard", "Tableau de bord", nullptr));
        groupEtudiants->setTitle(QCoreApplication::translate("Dashboard", "\303\211tudiants", nullptr));
        lblEtudiants->setText(QCoreApplication::translate("Dashboard", "0", nullptr));
        groupEnseignants->setTitle(QCoreApplication::translate("Dashboard", "Enseignants", nullptr));
        lblEnseignants->setText(QCoreApplication::translate("Dashboard", "0", nullptr));
        groupMatieres->setTitle(QCoreApplication::translate("Dashboard", "Mati\303\250res", nullptr));
        lblMatieres->setText(QCoreApplication::translate("Dashboard", "0", nullptr));
        groupNotes->setTitle(QCoreApplication::translate("Dashboard", "Notes", nullptr));
        lblNotes->setText(QCoreApplication::translate("Dashboard", "0", nullptr));
        groupMoyenne->setTitle(QCoreApplication::translate("Dashboard", "Moyenne g\303\251n\303\251rale", nullptr));
        lblMoyenneGenerale->setText(QCoreApplication::translate("Dashboard", "0.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
