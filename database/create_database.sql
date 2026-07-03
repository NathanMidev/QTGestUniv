PRAGMA foreign_keys = ON;

-----------------------------------------------------
-- TABLE DES RÔLES
-----------------------------------------------------

CREATE TABLE roles
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    nom TEXT NOT NULL UNIQUE
);

-----------------------------------------------------
-- UTILISATEURS
-----------------------------------------------------

CREATE TABLE utilisateurs
(
id INTEGER PRIMARY KEY AUTOINCREMENT,

    username TEXT NOT NULL UNIQUE,

    password TEXT NOT NULL,

    email TEXT UNIQUE,

    role_id INTEGER NOT NULL,

    actif INTEGER DEFAULT 1,

    date_creation DATETIME DEFAULT CURRENT_TIMESTAMP,

    FOREIGN KEY(role_id)
        REFERENCES roles(id)
);

-----------------------------------------------------
-- FILIERES
-----------------------------------------------------

CREATE TABLE filieres
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    code TEXT UNIQUE,

    nom TEXT NOT NULL,

    description TEXT
);

-----------------------------------------------------
-- DEPARTEMENTS
-----------------------------------------------------
CREATE TABLE departements
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    nom TEXT NOT NULL UNIQUE
);

-----------------------------------------------------
-- ENSEIGNANTS
-----------------------------------------------------
CREATE TABLE enseignants
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    matricule TEXT UNIQUE,

    nom TEXT,

    prenom TEXT,

    grade TEXT,

    email TEXT,

    telephone TEXT,

    specialite TEXT,

    departement_id INTEGER,

    FOREIGN KEY(departement_id)
        REFERENCES departements(id)
);

-----------------------------------------------------
-- ETUDIANTS
-----------------------------------------------------

CREATE TABLE etudiants
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    matricule TEXT UNIQUE,

    nom TEXT,

    prenom TEXT,

    sexe TEXT,

    date_naissance DATE,

    email TEXT,

    telephone TEXT,

    niveau TEXT,

    photo TEXT,

    filiere_id INTEGER,

    FOREIGN KEY(filiere_id)
        REFERENCES filieres(id)
);

-----------------------------------------------------
-- MATIERES
-----------------------------------------------------

CREATE TABLE matieres
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    code TEXT UNIQUE,

    intitule TEXT,

    coefficient INTEGER,

    credits INTEGER,

    enseignant_id INTEGER,

    FOREIGN KEY(enseignant_id)
        REFERENCES enseignants(id)
);

-----------------------------------------------------
-- SALLES
-----------------------------------------------------

CREATE TABLE salles
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    code TEXT UNIQUE,

    nom TEXT,

    capacite INTEGER,

    localisation TEXT
);

-----------------------------------------------------
-- EMPLOI DU TEMPS
-----------------------------------------------------

CREATE TABLE emplois_temps
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    matiere_id INTEGER,

    salle_id INTEGER,

    filiere_id INTEGER,

    enseignant_id INTEGER,

    jour TEXT,

    heure_debut TEXT,

    heure_fin TEXT,

    FOREIGN KEY(matiere_id)
        REFERENCES matieres(id),

    FOREIGN KEY(salle_id)
        REFERENCES salles(id),

    FOREIGN KEY(filiere_id)
        REFERENCES filieres(id),

    FOREIGN KEY(enseignant_id)
        REFERENCES enseignants(id)
);

-----------------------------------------------------
-- NOTES
-----------------------------------------------------
CREATE TABLE notes
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    etudiant_id INTEGER,

    matiere_id INTEGER,

    semestre INTEGER,

    note_cc REAL,

    note_exam REAL,

    note_finale REAL,

    FOREIGN KEY(etudiant_id)
        REFERENCES etudiants(id),

    FOREIGN KEY(matiere_id)
        REFERENCES matieres(id)
);

-----------------------------------------------------
-- NOTIFICATIONS
-----------------------------------------------------

CREATE TABLE notifications
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    titre TEXT,

    message TEXT,

    date_notification DATETIME DEFAULT CURRENT_TIMESTAMP,

    lu INTEGER DEFAULT 0
);

-----------------------------------------------------
-- BULLETINS
-----------------------------------------------------

CREATE TABLE bulletins
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    etudiant_id INTEGER,

    semestre INTEGER,

    moyenne REAL,

    decision TEXT,

    FOREIGN KEY(etudiant_id)
        REFERENCES etudiants(id)
);

-----------------------------------------------------
-- PARAMETRES
-----------------------------------------------------

CREATE TABLE parametres
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    cle TEXT UNIQUE,

    valeur TEXT
);
