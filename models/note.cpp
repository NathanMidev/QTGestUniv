#include "models/Note.h"
#include "database/DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Note::Note()
{
    id = 0;
    etudiantId = 0;
    matiereId = 0;
    noteCC = 0;
    noteExamen = 0;
    noteFinale = 0;
}

/* ================= GETTERS ================= */

int Note::getId() const { return id; }
int Note::getEtudiantId() const { return etudiantId; }
int Note::getMatiereId() const { return matiereId; }
float Note::getNoteCC() const { return noteCC; }
float Note::getNoteExamen() const { return noteExamen; }
float Note::getNoteFinale() const { return noteFinale; }

/* ================= SETTERS ================= */

void Note::setId(int id) { this->id = id; }
void Note::setEtudiantId(int id) { this->etudiantId = id; }
void Note::setMatiereId(int id) { this->matiereId = id; }
void Note::setNoteCC(float note) { this->noteCC = note; }
void Note::setNoteExamen(float note) { this->noteExamen = note; }
void Note::setNoteFinale(float note) { this->noteFinale = note; }

/* ================= CREATE ================= */

bool Note::create()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        INSERT INTO notes
        (etudiant_id, matiere_id, semestre, note_cc, note_exam, note_finale)
        VALUES (?, ?, ?, ?, ?, ?)
    )");

    query.addBindValue(etudiantId);
    query.addBindValue(matiereId);
    query.addBindValue(noteCC);
    query.addBindValue(noteExamen);
    query.addBindValue(noteFinale);

    if(!query.exec())
    {
        qDebug() << "Create Note error :" << query.lastError();
        return false;
    }

    return true;
}

/* ================= UPDATE ================= */

bool Note::update()
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare(R"(
        UPDATE notes SET
            etudiant_id=?,
            matiere_id=?,
            note_cc=?,
            note_exam=?,
            note_finale=?
        WHERE id=?
    )");

    query.addBindValue(etudiantId);
    query.addBindValue(matiereId);
    query.addBindValue(noteCC);
    query.addBindValue(noteExamen);
    query.addBindValue(noteFinale);
    query.addBindValue(id);

    if(!query.exec())
    {
        qDebug() << "Update Note error :" << query.lastError();
        return false;
    }

    return true;
}

/* ================= DELETE ================= */

bool Note::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("DELETE FROM notes WHERE id=?");
    query.addBindValue(id);

    if(!query.exec())
    {
        qDebug() << "Delete Note error :" << query.lastError();
        return false;
    }

    return true;
}

/* ================= GET BY ID ================= */

Note Note::getById(int id)
{
    Note n;

    QSqlQuery query(DatabaseManager::instance().database());

    query.prepare("SELECT * FROM notes WHERE id=?");
    query.addBindValue(id);

    if(query.exec() && query.next())
    {
        n.setId(query.value("id").toInt());
        n.setEtudiantId(query.value("etudiant_id").toInt());
        n.setMatiereId(query.value("matiere_id").toInt());
        n.setNoteCC(query.value("note_cc").toFloat());
        n.setNoteExamen(query.value("note_exam").toFloat());
        n.setNoteFinale(query.value("note_finale").toFloat());
    }

    return n;
}

/* ================= GET ALL ================= */

QList<Note> Note::getAll()
{
    QList<Note> liste;

    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM notes");

    if(query.exec())
    {
        while(query.next())
        {
            Note n;

            n.setId(query.value("id").toInt());
            n.setEtudiantId(query.value("etudiant_id").toInt());
            n.setMatiereId(query.value("matiere_id").toInt());
            n.setNoteCC(query.value("note_cc").toFloat());
            n.setNoteExamen(query.value("note_exam").toFloat());
            n.setNoteFinale(query.value("note_finale").toFloat());

            liste.append(n);
        }
    }

    return liste;
}
