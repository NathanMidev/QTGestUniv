#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>

class Utilisateur
{
private:
    int id;
    QString username;
    QString password;
    QString email;
    QString role;

public:
    Utilisateur();

    int getId() const;
    QString getUsername() const;
    QString getPassword() const;
    QString getEmail() const;
    QString getRole() const;

    void setId(int id);
    void setUsername(const QString &username);
    void setPassword(const QString &password);
    void setEmail(const QString &email);
    void setRole(const QString &role);
};

#endif // UTILISATEUR_H
