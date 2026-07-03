#ifndef NOTE_H
#define NOTE_H

class Note
{
private:
    int id;
    int etudiantId;
    int matiereId;
    float noteCC;
    float noteExamen;
    float noteFinale;

public:
    Note();

    int getId() const;
    int getEtudiantId() const;
    int getMatiereId() const;
    float getNoteCC() const;
    float getNoteExamen() const;
    float getNoteFinale() const;

    void setId(int id);
    void setEtudiantId(int id);
    void setMatiereId(int id);
    void setNoteCC(float note);
    void setNoteExamen(float note);
    void setNoteFinale(float note);
};

#endif // NOTE_H
