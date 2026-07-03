INSERT INTO roles(nom)
VALUES
('Administrateur'),
('Enseignant'),
('Etudiant');

INSERT INTO utilisateurs
(username,password,email,role_id)

VALUES

('admin',
'admin123',
'admin@universite.mg',
1);

INSERT INTO filieres(nom)

VALUES

('Informatique'),

('Gestion'),

('Télécommunication');
