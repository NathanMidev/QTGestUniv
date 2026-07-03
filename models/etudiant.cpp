#include "models/Etudiant.h"
#include "database/DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Etudiant::Etudiant()
{
    id = 0;
    filiereId = 0;
}

/* ================= GETTERS / SETTERS ================= */

int Etudiant::getId() const { return id; }
QString Etudiant::getMatricule() const { return matricule; }
QString Etudiant::getNom() const { return nom; }
QString Etudiant::getPrenom() const { return prenom; }
QString Etudiant::getEmail() const { return email; }
QString Etudiant::getTelephone() const { return telephone; }
QString Etudiant::getNiveau() const { return niveau; }
int Etudiant::getFiliereId() const { return filiereId; }

void Etudiant::setId(int id) { this->id = id; }
void Etudiant::setMatricule(const QString &matricule) { this->matricule = matricule; }
void Etudiant::setNom(const QString &nom) { this->nom = nom; }
void Etudiant::setPrenom(const QString &prenom) { this->prenom = prenom; }
void Etudiant::setEmail(const QString &email) { this->email = email; }
void Etudiant::setTelephone(const QString &telephone) { this->telephone = telephone; }
void Etudiant::setNiveau(const QString &niveau) { this->niveau = niveau; }
void Etudiant::setFiliereId(int filiereId) { this->filiereId = filiereId; }

/* ================= CREATE ================= */
bool Etudiant::create()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        INSERT INTO etudiants
        (matricule, nom, prenom, email, telephone, niveau, filiere_id)
        VALUES (?, ?, ?, ?, ?, ?, ?)
    )");

    query.addBindValue(matricule);
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(email);
    query.addBindValue(telephone);
    query.addBindValue(niveau);
    query.addBindValue(filiereId);

    if(!query.exec())
    {
        qDebug() << "Create Etudiant error:" << query.lastError();
        return false;
    }

    return true;
}

/* ================= UPDATE ================= */
bool Etudiant::update()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        UPDATE etudiants SET
        matricule=?, nom=?, prenom=?, email=?, telephone=?, niveau=?, filiere_id=?
        WHERE id=?
    )");

    query.addBindValue(matricule);
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(email);
    query.addBindValue(telephone);
    query.addBindValue(niveau);
    query.addBindValue(filiereId);
    query.addBindValue(id);

    return query.exec();
}

/* ================= DELETE ================= */
bool Etudiant::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("DELETE FROM etudiants WHERE id=?");
    query.addBindValue(id);

    return query.exec();
}

/* ================= GET BY ID ================= */
Etudiant Etudiant::getById(int id)
{
    Etudiant e;

    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM etudiants WHERE id=?");
    query.addBindValue(id);

    if(query.exec() && query.next())
    {
        e.setId(query.value("id").toInt());
        e.setMatricule(query.value("matricule").toString());
        e.setNom(query.value("nom").toString());
        e.setPrenom(query.value("prenom").toString());
        e.setEmail(query.value("email").toString());
        e.setTelephone(query.value("telephone").toString());
        e.setNiveau(query.value("niveau").toString());
        e.setFiliereId(query.value("filiere_id").toInt());
    }

    return e;
}

/* ================= GET ALL ================= */
QList<Etudiant> Etudiant::getAll()
{
    QList<Etudiant> list;

    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM etudiants");

    if(query.exec())
    {
        while(query.next())
        {
            Etudiant e;

            e.setId(query.value("id").toInt());
            e.setMatricule(query.value("matricule").toString());
            e.setNom(query.value("nom").toString());
            e.setPrenom(query.value("prenom").toString());
            e.setEmail(query.value("email").toString());
            e.setTelephone(query.value("telephone").toString());
            e.setNiveau(query.value("niveau").toString());
            e.setFiliereId(query.value("filiere_id").toInt());

            list.append(e);
        }
    }

    return list;
}
