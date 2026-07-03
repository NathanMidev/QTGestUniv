#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>
#include <QList>

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

    // CRUD
    bool create();
    bool update();
    bool remove(int id);

    static Utilisateur getById(int id);
    static QList<Utilisateur> getAll();

    // Authentification
    static bool login(const QString &username,
                      const QString &password,
                      Utilisateur &user);
};

#endif // UTILISATEUR_H
