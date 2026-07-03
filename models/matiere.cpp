#include "models/Matiere.h"

Matiere::Matiere()
{
    id = 0;
    credits = 0;
}

int Matiere::getId() const { return id; }
QString Matiere::getCode() const { return code; }
QString Matiere::getIntitule() const { return intitule; }
int Matiere::getCredits() const { return credits; }

void Matiere::setId(int id) { this->id = id; }
void Matiere::setCode(const QString &code) { this->code = code; }
void Matiere::setIntitule(const QString &intitule) { this->intitule = intitule; }
void Matiere::setCredits(int credits) { this->credits = credits; }
