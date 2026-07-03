#include "models/Utilisateur.h"

Utilisateur::Utilisateur()
{
    id = 0;
}

int Utilisateur::getId() const { return id; }
QString Utilisateur::getUsername() const { return username; }
QString Utilisateur::getPassword() const { return password; }
QString Utilisateur::getEmail() const { return email; }
QString Utilisateur::getRole() const { return role; }

void Utilisateur::setId(int id) { this->id = id; }
void Utilisateur::setUsername(const QString &username) { this->username = username; }
void Utilisateur::setPassword(const QString &password) { this->password = password; }
void Utilisateur::setEmail(const QString &email) { this->email = email; }
void Utilisateur::setRole(const QString &role) { this->role = role; }
