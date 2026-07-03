#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include <QString>
#include <QList>

class Enseignant
{
private:
    int id;
    QString matricule;
    QString nom;
    QString prenom;
    QString email;
    QString specialite;

public:
    Enseignant();

    int getId() const;
    QString getMatricule() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    QString getSpecialite() const;

    void setId(int id);
    void setMatricule(const QString &matricule);
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setEmail(const QString &email);
    void setSpecialite(const QString &specialite);

    // CRUD
    bool create();
    bool update();
    bool remove(int id);

    static Enseignant getById(int id);
    static QList<Enseignant> getAll();
};

#endif // ENSEIGNANT_H
