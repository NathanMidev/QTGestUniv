#include "models/utilisateur.h"
#include "database/databasemanager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Utilisateur::Utilisateur()
{
    id = 0;
    roleId = 0;
}

/*================ GETTERS =================*/

int Utilisateur::getId() const
{
    return id;
}

QString Utilisateur::getUsername() const
{
    return username;
}

QString Utilisateur::getPassword() const
{
    return password;
}

QString Utilisateur::getEmail() const
{
    return email;
}

int Utilisateur::getRoleId() const
{
    return roleId;
}

/*================ SETTERS =================*/

void Utilisateur::setId(int id)
{
    this->id = id;
}

void Utilisateur::setUsername(const QString &username)
{
    this->username = username;
}

void Utilisateur::setPassword(const QString &password)
{
    this->password = password;
}

void Utilisateur::setEmail(const QString &email)
{
    this->email = email;
}

void Utilisateur::setRoleId(int roleId)
{
    this->roleId = roleId;
}

/*================ CREATE =================*/

bool Utilisateur::create()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        INSERT INTO utilisateurs
        (username,password,email,role_id)
        VALUES(?,?,?,?)
    )");

    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(email);
    query.addBindValue(roleId);

    if(!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

/*================ UPDATE =================*/

bool Utilisateur::update()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        UPDATE utilisateurs
        SET
            username=?,
            password=?,
            email=?,
            role_id=?
        WHERE id=?
    )");

    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(email);
    query.addBindValue(roleId);
    query.addBindValue(id);

    if(!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

/*================ DELETE =================*/

bool Utilisateur::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("DELETE FROM utilisateurs WHERE id=?");
    query.addBindValue(id);

    if(!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

/*================ GET BY ID =================*/

Utilisateur Utilisateur::getById(int id)
{
    Utilisateur u;

    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("SELECT * FROM utilisateurs WHERE id=?");
    query.addBindValue(id);

    if(query.exec() && query.next())
    {
        u.setId(query.value("id").toInt());
        u.setUsername(query.value("username").toString());
        u.setPassword(query.value("password").toString());
        u.setEmail(query.value("email").toString());
        u.setRoleId(query.value("role_id").toInt());
    }

    return u;
}

/*================ GET ALL =================*/

QList<Utilisateur> Utilisateur::getAll()
{
    QList<Utilisateur> liste;

    QSqlQuery query(DatabaseManager::instance().database());

    if(query.exec("SELECT * FROM utilisateurs"))
    {
        while(query.next())
        {
            Utilisateur u;

            u.setId(query.value("id").toInt());
            u.setUsername(query.value("username").toString());
            u.setPassword(query.value("password").toString());
            u.setEmail(query.value("email").toString());
            u.setRoleId(query.value("role_id").toInt());

            liste.append(u);
        }
    }

    return liste;
}

/*================ LOGIN =================*/

bool Utilisateur::login(const QString &username,
                        const QString &password,
                        Utilisateur &user)
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        SELECT *
        FROM utilisateurs
        WHERE username=?
        AND password=?
    )");

    query.addBindValue(username);
    query.addBindValue(password);

    if(!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }

    if(query.next())
    {
        user.setId(query.value("id").toInt());
        user.setUsername(query.value("username").toString());
        user.setPassword(query.value("password").toString());
        user.setEmail(query.value("email").toString());
        user.setRoleId(query.value("role_id").toInt());

        return true;
    }

    return false;
}
