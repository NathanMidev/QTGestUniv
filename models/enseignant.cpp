#include "models/Enseignant.h"

Enseignant::Enseignant()
{
    id = 0;
}

int Enseignant::getId() const { return id; }
QString Enseignant::getMatricule() const { return matricule; }
QString Enseignant::getNom() const { return nom; }
QString Enseignant::getPrenom() const { return prenom; }
QString Enseignant::getEmail() const { return email; }
QString Enseignant::getSpecialite() const { return specialite; }

void Enseignant::setId(int id) { this->id = id; }
void Enseignant::setMatricule(const QString &matricule) { this->matricule = matricule; }
void Enseignant::setNom(const QString &nom) { this->nom = nom; }
void Enseignant::setPrenom(const QString &prenom) { this->prenom = prenom; }
void Enseignant::setEmail(const QString &email) { this->email = email; }
void Enseignant::setSpecialite(const QString &specialite) { this->specialite = specialite; }
