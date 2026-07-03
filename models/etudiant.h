#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QString>
#include <QList>
class Etudiant
{
private:
    int id;
    QString matricule;
    QString nom;
    QString prenom;
    QString email;
    QString telephone;
    QString niveau;
    int filiereId;

public:
    Etudiant();

    int getId() const;
    QString getMatricule() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getEmail() const;
    QString getTelephone() const;
    QString getNiveau() const;
    int getFiliereId() const;

    void setId(int id);
    void setMatricule(const QString &matricule);
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setEmail(const QString &email);
    void setTelephone(const QString &telephone);
    void setNiveau(const QString &niveau);
    void setFiliereId(int filiereId);

    bool create();
    bool update();
    bool remove(int id);
    static Etudiant getById(int id);
    static QList<Etudiant> getAll();
};

#endif // ETUDIANTS_H
