#include "DatabaseManager.h"

#include <QSqlError>
#include <QDebug>

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

    m_db.setDatabaseName("database/universite.db");

    if(!m_db.open())
    {
        qDebug()<<m_db.lastError();
        return false;
    }

    qDebug()<<"Connexion SQLite réussie";

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
