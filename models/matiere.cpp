#include "models/matiere.h"
#include "database/databasemanager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>

Matiere::Matiere()
{
    id = 0;
    coefficient = 0;
    credits = 0;
    enseignantId = 0;
}

/*================ GETTERS =================*/

int Matiere::getId() const
{
    return id;
}

QString Matiere::getCode() const
{
    return code;
}

QString Matiere::getIntitule() const
{
    return intitule;
}

int Matiere::getCoefficient() const
{
    return coefficient;
}

int Matiere::getCredits() const
{
    return credits;
}

int Matiere::getEnseignantId() const
{
    return enseignantId;
}

/*================ SETTERS =================*/

void Matiere::setId(int id)
{
    this->id = id;
}

void Matiere::setCode(const QString &code)
{
    this->code = code;
}

void Matiere::setIntitule(const QString &intitule)
{
    this->intitule = intitule;
}

void Matiere::setCoefficient(int coefficient)
{
    this->coefficient = coefficient;
}

void Matiere::setCredits(int credits)
{
    this->credits = credits;
}

void Matiere::setEnseignantId(int enseignantId)
{
    this->enseignantId = enseignantId;
}

/*================ CREATE =================*/

bool Matiere::create()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        INSERT INTO matieres
        (code,intitule,coefficient,credits,enseignant_id)
        VALUES(?,?,?,?,?)
    )");

    query.addBindValue(code);
    query.addBindValue(intitule);
    query.addBindValue(coefficient);
    query.addBindValue(credits);
    query.addBindValue(enseignantId > 0 ? QVariant(enseignantId) : QVariant());

    if(!query.exec())
    {
        qDebug() << "Erreur création matière :" << query.lastError();
        return false;
    }

    return true;
}

/*================ UPDATE =================*/

bool Matiere::update()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        UPDATE matieres
        SET
            code=?,
            intitule=?,
            coefficient=?,
            credits=?,
            enseignant_id=?
        WHERE id=?
    )");

    query.addBindValue(code);
    query.addBindValue(intitule);
    query.addBindValue(coefficient);
    query.addBindValue(credits);
    query.addBindValue(enseignantId > 0 ? QVariant(enseignantId) : QVariant());
    query.addBindValue(id);

    if(!query.exec())
    {
        qDebug() << "Erreur modification matière :" << query.lastError();
        return false;
    }

    return true;
}

/*================ DELETE =================*/

bool Matiere::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("DELETE FROM matieres WHERE id=?");
    query.addBindValue(id);

    if(!query.exec())
    {
        qDebug() << "Erreur suppression matière :" << query.lastError();
        return false;
    }

    return true;
}

/*================ GET BY ID =================*/

Matiere Matiere::getById(int id)
{
    Matiere m;

    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("SELECT * FROM matieres WHERE id=?");
    query.addBindValue(id);

    if(query.exec() && query.next())
    {
        m.setId(query.value("id").toInt());
        m.setCode(query.value("code").toString());
        m.setIntitule(query.value("intitule").toString());
        m.setCoefficient(query.value("coefficient").toInt());
        m.setCredits(query.value("credits").toInt());
        m.setEnseignantId(query.value("enseignant_id").toInt());
    }

    return m;
}

/*================ GET ALL =================*/

QList<Matiere> Matiere::getAll()
{
    QList<Matiere> liste;

    QSqlQuery query(DatabaseManager::instance().database());

    if(query.exec("SELECT * FROM matieres"))
    {
        while(query.next())
        {
            Matiere m;

            m.setId(query.value("id").toInt());
            m.setCode(query.value("code").toString());
            m.setIntitule(query.value("intitule").toString());
            m.setCoefficient(query.value("coefficient").toInt());
            m.setCredits(query.value("credits").toInt());
            m.setEnseignantId(query.value("enseignant_id").toInt());

            liste.append(m);
        }
    }

    return liste;
}
