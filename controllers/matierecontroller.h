#ifndef MATIERECONTROLLER_H
#define MATIERECONTROLLER_H

#include "models/matiere.h"

#include <QList>
#include <QString>

class MatiereController
{
public:
    static QList<Matiere> getAll()
    {
        return Matiere::getAll();
    }

    static bool ajouter(Matiere &matiere)
    {
        if (matiere.getCode().trimmed().isEmpty()
            || matiere.getIntitule().trimmed().isEmpty())
            return false;

        return matiere.create();
    }

    static bool modifier(Matiere &matiere)
    {
        return matiere.getId() > 0 && matiere.update();
    }

    static bool supprimer(int id)
    {
        return id > 0 && Matiere().remove(id);
    }

    static QList<Matiere> rechercher(const QString &terme)
    {
        QList<Matiere> resultat;
        const QString filtre = terme.trimmed();
        const QList<Matiere> matieres = getAll();
        if (filtre.isEmpty())
            return matieres;

        for (const Matiere &matiere : matieres)
        {
            if (matiere.getCode().contains(filtre, Qt::CaseInsensitive)
                || matiere.getIntitule().contains(filtre, Qt::CaseInsensitive)
                || QString::number(matiere.getCredits()).contains(filtre)
                || QString::number(matiere.getCoefficient()).contains(filtre))
                resultat.append(matiere);
        }

        return resultat;
    }
};

#endif // MATIERECONTROLLER_H