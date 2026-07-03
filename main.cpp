#include "MainWindow.h"
#include "database/DatabaseManager.h"
#include "database/DatabaseInitializer.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Connexion à la base de données
    if (!DatabaseManager::instance().connectDatabase())
    {
        QMessageBox::critical(
            nullptr,
            "Erreur",
            "Impossible de se connecter à la base de données SQLite."
        );

        return -1;
    }

    // Initialisation de la base (sera complétée plus tard)
    if (!DatabaseInitializer::initialize())
    {
        QMessageBox::critical(
            nullptr,
            "Erreur",
            "Erreur lors de l'initialisation de la base de données."
        );

        return -1;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
