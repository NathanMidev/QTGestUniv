/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *navWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnDashboard;
    QPushButton *btnEtudiants;
    QPushButton *btnEnseignants;
    QPushButton *btnMatieres;
    QPushButton *btnNotes;
    QStackedWidget *stackedPages;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        navWidget = new QWidget(centralWidget);
        navWidget->setObjectName("navWidget");
        horizontalLayout = new QHBoxLayout(navWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        btnDashboard = new QPushButton(navWidget);
        btnDashboard->setObjectName("btnDashboard");

        horizontalLayout->addWidget(btnDashboard);

        btnEtudiants = new QPushButton(navWidget);
        btnEtudiants->setObjectName("btnEtudiants");

        horizontalLayout->addWidget(btnEtudiants);

        btnEnseignants = new QPushButton(navWidget);
        btnEnseignants->setObjectName("btnEnseignants");

        horizontalLayout->addWidget(btnEnseignants);

        btnMatieres = new QPushButton(navWidget);
        btnMatieres->setObjectName("btnMatieres");

        horizontalLayout->addWidget(btnMatieres);

        btnNotes = new QPushButton(navWidget);
        btnNotes->setObjectName("btnNotes");

        horizontalLayout->addWidget(btnNotes);


        verticalLayout->addWidget(navWidget);

        stackedPages = new QStackedWidget(centralWidget);
        stackedPages->setObjectName("stackedPages");

        verticalLayout->addWidget(stackedPages);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedPages->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GestUniversit\303\251", nullptr));
        btnDashboard->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        btnEtudiants->setText(QCoreApplication::translate("MainWindow", "\303\211tudiants", nullptr));
        btnEnseignants->setText(QCoreApplication::translate("MainWindow", "Enseignants", nullptr));
        btnMatieres->setText(QCoreApplication::translate("MainWindow", "Mati\303\250res", nullptr));
        btnNotes->setText(QCoreApplication::translate("MainWindow", "Notes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
