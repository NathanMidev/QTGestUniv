#ifndef MATIERE_H
#define MATIERE_H

#include <QString>

class Matiere
{
private:
    int id;
    QString code;
    QString intitule;
    int credits;

public:
    Matiere();

    int getId() const;
    QString getCode() const;
    QString getIntitule() const;
    int getCredits() const;

    void setId(int id);
    void setCode(const QString &code);
    void setIntitule(const QString &intitule);
    void setCredits(int credits);
};

#endif // MATIERE_H
