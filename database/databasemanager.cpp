#include "database/databasemanager.h"

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QSqlError>
#include <QStandardPaths>
#include <QDebug>

namespace
{
QString resolveDatabasePath()
{
    QString appDataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (appDataDir.isEmpty())
        appDataDir = QDir::homePath() + QDir::separator() + ".GestUniversite";

    QDir dir(appDataDir);
    if (!dir.exists())
        dir.mkpath(appDataDir);

    const QString dbDirPath = appDataDir + QDir::separator() + "database";
    QDir dbDir(dbDirPath);
    if (!dbDir.exists())
        dbDir.mkpath(dbDirPath);

    return dbDirPath + QDir::separator() + "universite.db";
}
}

DatabaseManager::DatabaseManager()
{

}

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager manager;
    return manager;
}

bool DatabaseManager::connectDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    const QString databasePath = resolveDatabasePath();
    m_db.setDatabaseName(databasePath);

    if(!m_db.open())
    {
        qDebug() << "Erreur ouverture SQLite :" << m_db.lastError();
        qDebug() << "Chemin cible :" << databasePath;
        return false;
    }

    qDebug() << "Connexion SQLite réussie :" << databasePath;

    return true;
}

void DatabaseManager::closeDatabase()
{
    if(m_db.isOpen())
        m_db.close();
}

QSqlDatabase DatabaseManager::database()
{
    return m_db;
}
