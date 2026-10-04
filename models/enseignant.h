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
    QString grade;
    QString telephone;
    QString specialite;
    int departementId;

public:
    Enseignant();

    int getId() const;
    QString getMatricule() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    QString getGrade() const;
    QString getTelephone() const;
    QString getSpecialite() const;
    int getDepartementId() const;

    void setId(int id);
    void setMatricule(const QString &matricule);
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setEmail(const QString &email);
    void setGrade(const QString &grade);
    void setTelephone(const QString &telephone);
    void setSpecialite(const QString &specialite);
    void setDepartementId(int departementId);

    // CRUD
    bool create();
    bool update();
    bool remove(int id);

    static Enseignant getById(int id);
    static QList<Enseignant> getAll();
};

#endif // ENSEIGNANT_H
