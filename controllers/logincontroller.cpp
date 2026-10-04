#include "controllers/logincontroller.h"

bool LoginController::login(const QString &username,
                           const QString &password,
                           Utilisateur &user)
{
    if (username.trimmed().isEmpty() || password.isEmpty())
        return false;

    return Utilisateur::login(username.trimmed(), password, user);
}
