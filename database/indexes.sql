CREATE INDEX idx_etudiant_nom
ON etudiants(nom);

CREATE INDEX idx_matricule
ON etudiants(matricule);

CREATE INDEX idx_note
ON notes(etudiant_id);
