#include "mainwindow.h"
#include "controllers/logincontroller.h"
#include "database/databasemanager.h"
#include "database/databaseinitializer.h"
#include "models/utilisateur.h"
#include "ui_login.h"

#include <QApplication>
#include <QDialog>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!DatabaseManager::instance().connectDatabase())
    {
        QMessageBox::critical(
            nullptr,
            "Erreur",
            "Impossible de se connecter à la base de données SQLite."
        );

        return -1;
    }

    if (!DatabaseInitializer::initialize())
    {
        QMessageBox::critical(
            nullptr,
            "Erreur",
            "Erreur lors de l'initialisation de la base de données."
        );

        return -1;
    }

    QDialog loginDialog;
    Ui::Dialog loginUi;
    loginUi.setupUi(&loginDialog);

    QObject::connect(loginUi.btnConnexion, &QPushButton::clicked, [&]() {
        const QString username = loginUi.txtUsername->text().trimmed();
        const QString password = loginUi.txtPassword->text();
        Utilisateur user;

        if (!LoginController::login(username, password, user))
        {
            QMessageBox::warning(
                &loginDialog,
                "Erreur",
                "Nom d'utilisateur ou mot de passe incorrect."
            );
            loginUi.txtPassword->clear();
            loginUi.txtUsername->setFocus();
            return;
        }

        loginDialog.accept();
    });

    QObject::connect(loginUi.btnQuitter, &QPushButton::clicked, &loginDialog, &QDialog::reject);

    if (loginDialog.exec() != QDialog::Accepted)
    {
        return 0;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
