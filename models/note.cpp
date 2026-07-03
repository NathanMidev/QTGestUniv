#include "models/Note.h"

Note::Note()
{
    id = 0;
    etudiantId = 0;
    matiereId = 0;
    noteCC = 0;
    noteExamen = 0;
    noteFinale = 0;
}

int Note::getId() const { return id; }
int Note::getEtudiantId() const { return etudiantId; }
int Note::getMatiereId() const { return matiereId; }
float Note::getNoteCC() const { return noteCC; }
float Note::getNoteExamen() const { return noteExamen; }
float Note::getNoteFinale() const { return noteFinale; }

void Note::setId(int id) { this->id = id; }
void Note::setEtudiantId(int id) { this->etudiantId = id; }
void Note::setMatiereId(int id) { this->matiereId = id; }
void Note::setNoteCC(float note) { this->noteCC = note; }
void Note::setNoteExamen(float note) { this->noteExamen = note; }
void Note::setNoteFinale(float note) { this->noteFinale = note; }
