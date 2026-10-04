#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QString>
#include "models/utilisateur.h"

class LoginController
{
public:
    static bool login(const QString &username,
                      const QString &password,
                      Utilisateur &user);
};

#endif // LOGINCONTROLLER_H
