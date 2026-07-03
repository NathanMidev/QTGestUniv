#ifndef MATIERE_H
#define MATIERE_H

#include <QString>
#include <QList>

class Matiere
{
private:
    int id;
    QString code;
    QString intitule;
    int credits;

public:
    Matiere();

    // Getters
    int getId() const;
    QString getCode() const;
    QString getIntitule() const;
    int getCredits() const;

    // Setters
    void setId(int id);
    void setCode(const QString &code);
    void setIntitule(const QString &intitule);
    void setCredits(int credits);

    // CRUD
    bool create();
    bool update();
    bool remove(int id);

    static Matiere getById(int id);
    static QList<Matiere> getAll();
};

#endif // MATIERE_H
