#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager
{
public:
    static DatabaseManager& instance();

    bool connectDatabase();
    void closeDatabase();

    QSqlDatabase database();

private:
    DatabaseManager();
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
