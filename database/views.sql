CREATE VIEW vue_etudiants AS

SELECT
e.id,
e.nom,
e.prenom,
f.nom AS filiere

FROM etudiants e

JOIN filieres f

ON e.filiere_id=f.id;
