#ifndef ETUDIANTCONTROLLEUR_H
#define ETUDIANTCONTROLLEUR_H

#include "models/etudiant.h"

#include <QList>
#include <QString>

class EtudiantController
{
public:
    static QList<Etudiant> getAll()
    {
        return Etudiant::getAll();
    }

    static bool ajouter(Etudiant &etudiant)
    {
        if (etudiant.getMatricule().trimmed().isEmpty())
            return false;

        return etudiant.create();
    }

    static bool modifier(Etudiant &etudiant)
    {
        if (etudiant.getId() <= 0)
            return false;

        return etudiant.update();
    }

    static bool supprimer(int id)
    {
        if (id <= 0)
            return false;

        return Etudiant().remove(id);
    }

    static QList<Etudiant> rechercher(const QString &terme)
    {
        QList<Etudiant> resultat;
        const QString filtre = terme.trimmed();
        if (filtre.isEmpty())
            return getAll();

        const QList<Etudiant> etudiants = getAll();
        for (const Etudiant &etudiant : etudiants)
        {
            const bool matchNom = etudiant.getNom().contains(filtre, Qt::CaseInsensitive);
            const bool matchPrenom = etudiant.getPrenom().contains(filtre, Qt::CaseInsensitive);
            const bool matchMatricule = etudiant.getMatricule().contains(filtre, Qt::CaseInsensitive);

            if (matchNom || matchPrenom || matchMatricule)
                resultat.append(etudiant);
        }

        return resultat;
    }
};

#endif // ETUDIANTCONTROLLEUR_H
