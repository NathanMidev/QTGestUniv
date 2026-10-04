#ifndef ENSEIGNANTCONTROLLER_H
#define ENSEIGNANTCONTROLLER_H

#include "models/enseignant.h"

#include <QList>
#include <QString>

class EnseignantController
{
public:
    static QList<Enseignant> getAll()
    {
        return Enseignant::getAll();
    }

    static bool ajouter(Enseignant &enseignant)
    {
        if (enseignant.getMatricule().trimmed().isEmpty()
            || enseignant.getNom().trimmed().isEmpty()
            || enseignant.getPrenom().trimmed().isEmpty())
            return false;

        return enseignant.create();
    }

    static bool modifier(Enseignant &enseignant)
    {
        return enseignant.getId() > 0 && enseignant.update();
    }

    static bool supprimer(int id)
    {
        return id > 0 && Enseignant().remove(id);
    }

    static QList<Enseignant> rechercher(const QString &terme)
    {
        QList<Enseignant> resultat;
        const QString filtre = terme.trimmed();
        const QList<Enseignant> enseignants = getAll();
        if (filtre.isEmpty())
            return enseignants;

        for (const Enseignant &enseignant : enseignants)
        {
            if (enseignant.getMatricule().contains(filtre, Qt::CaseInsensitive)
                || enseignant.getNom().contains(filtre, Qt::CaseInsensitive)
                || enseignant.getPrenom().contains(filtre, Qt::CaseInsensitive)
                || enseignant.getEmail().contains(filtre, Qt::CaseInsensitive)
                || enseignant.getGrade().contains(filtre, Qt::CaseInsensitive)
                || enseignant.getTelephone().contains(filtre, Qt::CaseInsensitive)
                || enseignant.getSpecialite().contains(filtre, Qt::CaseInsensitive))
                resultat.append(enseignant);
        }

        return resultat;
    }
};

#endif // ENSEIGNANTCONTROLLER_H