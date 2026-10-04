#include "database/databaseinitializer.h"
#include "database/databasemanager.h"

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextStream>

namespace
{
QStringList splitSqlStatements(const QString &sql)
{
    QStringList statements;
    QString current;
    bool inSingleQuote = false;

    for (const QChar &ch : sql)
    {
        if (ch == '\'')
        {
            inSingleQuote = !inSingleQuote;
            current += ch;
            continue;
        }

        if (ch == ';' && !inSingleQuote)
        {
            const QString statement = current.trimmed();
            if (!statement.isEmpty())
                statements << statement;
            current.clear();
            continue;
        }

        current += ch;
    }

    const QString tail = current.trimmed();
    if (!tail.isEmpty())
        statements << tail;

    return statements;
}

QString resolveProjectPath(const QString &relativePath)
{
    const QStringList roots = {
        QDir::currentPath(),
        QCoreApplication::applicationDirPath()
    };

    for (const QString &root : roots)
    {
        QDir dir(root);
        QString candidate = dir.absoluteFilePath(relativePath);
        if (QFileInfo(candidate).exists())
            return candidate;

        while (dir.cdUp())
        {
            candidate = dir.absoluteFilePath(relativePath);
            if (QFileInfo(candidate).exists())
                return candidate;
        }
    }

    return relativePath;
}
}

bool DatabaseInitializer::initialize()
{
    QSqlDatabase db = DatabaseManager::instance().database();

    if (!db.isValid() || !db.isOpen())
    {
        if (!DatabaseManager::instance().connectDatabase())
            return false;

        db = DatabaseManager::instance().database();
    }

    if (db.tables().contains("utilisateurs") && db.tables().contains("etudiants"))
        return true;

    const QStringList scripts = {
        "database/create_database.sql",
        "database/views.sql",
        "database/insert_demo_data.sql",
        "database/indexes.sql",
        "database/triggers.sql"
    };

    for (const QString &scriptPath : scripts)
    {
        const QString resolvedPath = resolveProjectPath(scriptPath);
        QFile file(resolvedPath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Impossible d'ouvrir le script SQL :" << resolvedPath;
            return false;
        }

        QString sql = QTextStream(&file).readAll();
        file.close();

        if (scriptPath.endsWith("triggers.sql"))
        {
            QSqlQuery query(db);
            if (!query.exec(sql))
            {
                qDebug() << "Erreur lors de l'execution du trigger :" << query.lastError().text();
                return false;
            }
            continue;
        }

        const QStringList statements = splitSqlStatements(sql);
        for (const QString &statement : statements)
        {
            if (statement.trimmed().isEmpty())
                continue;

            QSqlQuery query(db);
            if (!query.exec(statement))
            {
                qDebug() << "Erreur SQL :" << query.lastError().text();
                qDebug() << "Requête :" << statement;
                return false;
            }
        }
    }

    return true;
}
