#include "models/enseignant.h"
#include "database/DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Enseignant::Enseignant()
{
    id = 0;
}

/*================ GETTERS =================*/

int Enseignant::getId() const
{
    return id;
}

QString Enseignant::getMatricule() const
{
    return matricule;
}

QString Enseignant::getNom() const
{
    return nom;
}

QString Enseignant::getPrenom() const
{
    return prenom;
}

QString Enseignant::getEmail() const
{
    return email;
}

QString Enseignant::getSpecialite() const
{
    return specialite;
}

/*================ SETTERS =================*/

void Enseignant::setId(int id)
{
    this->id = id;
}

void Enseignant::setMatricule(const QString &matricule)
{
    this->matricule = matricule;
}

void Enseignant::setNom(const QString &nom)
{
    this->nom = nom;
}

void Enseignant::setPrenom(const QString &prenom)
{
    this->prenom = prenom;
}

void Enseignant::setEmail(const QString &email)
{
    this->email = email;
}

void Enseignant::setSpecialite(const QString &specialite)
{
    this->specialite = specialite;
}

/*================ CREATE =================*/

bool Enseignant::create()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        INSERT INTO enseignants
        (matricule, nom, prenom, email, specialite)
        VALUES (?, ?, ?, ?, ?)
    )");

    query.addBindValue(matricule);
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(email);
    query.addBindValue(specialite);

    if(!query.exec())
    {
        qDebug() << "Create Enseignant :" << query.lastError();
        return false;
    }

    return true;
}

/*================ UPDATE =================*/

bool Enseignant::update()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        UPDATE enseignants
        SET
            matricule=?,
            nom=?,
            prenom=?,
            email=?,
            specialite=?
        WHERE id=?
    )");

    query.addBindValue(matricule);
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(email);
    query.addBindValue(specialite);
    query.addBindValue(id);

    if(!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

/*================ DELETE =================*/

bool Enseignant::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("DELETE FROM enseignants WHERE id=?");
    query.addBindValue(id);

    if(!query.exec())
    {
        qDebug() << query.lastError();
        return false;
    }

    return true;
}

/*================ GET BY ID =================*/

Enseignant Enseignant::getById(int id)
{
    Enseignant e;

    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("SELECT * FROM enseignants WHERE id=?");
    query.addBindValue(id);

    if(query.exec() && query.next())
    {
        e.setId(query.value("id").toInt());
        e.setMatricule(query.value("matricule").toString());
        e.setNom(query.value("nom").toString());
        e.setPrenom(query.value("prenom").toString());
        e.setEmail(query.value("email").toString());
        e.setSpecialite(query.value("specialite").toString());
    }

    return e;
}

/*================ GET ALL =================*/

QList<Enseignant> Enseignant::getAll()
{
    QList<Enseignant> liste;

    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("SELECT * FROM enseignants");

    if(query.exec())
    {
        while(query.next())
        {
            Enseignant e;

            e.setId(query.value("id").toInt());
            e.setMatricule(query.value("matricule").toString());
            e.setNom(query.value("nom").toString());
            e.setPrenom(query.value("prenom").toString());
            e.setEmail(query.value("email").toString());
            e.setSpecialite(query.value("specialite").toString());

            liste.append(e);
        }
    }

    return liste;
}
