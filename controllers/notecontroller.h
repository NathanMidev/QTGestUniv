#ifndef NOTECONTROLLER_H
#define NOTECONTROLLER_H

#include "models/note.h"

#include <QList>
#include <QString>

class NoteController
{
public:
    static QList<Note> getAll()
    {
        return Note::getAll();
    }

    static bool ajouter(Note &note)
    {
        if (note.getEtudiantId() <= 0 || note.getMatiereId() <= 0 || note.getSemestre() <= 0)
            return false;

        return note.create();
    }

    static bool modifier(Note &note)
    {
        return note.getId() > 0 && note.update();
    }

    static bool supprimer(int id)
    {
        return id > 0 && Note().remove(id);
    }

    static QList<Note> rechercher(const QString &terme)
    {
        QList<Note> resultat;
        const QString filtre = terme.trimmed();
        const QList<Note> notes = getAll();
        if (filtre.isEmpty())
            return notes;

        for (const Note &note : notes)
        {
            if (QString::number(note.getEtudiantId()).contains(filtre)
                || QString::number(note.getMatiereId()).contains(filtre)
                || QString::number(note.getSemestre()).contains(filtre)
                || QString::number(note.getNoteCC()).contains(filtre)
                || QString::number(note.getNoteExamen()).contains(filtre)
                || QString::number(note.getNoteFinale()).contains(filtre))
                resultat.append(note);
        }

        return resultat;
    }
};

#endif // NOTECONTROLLER_H