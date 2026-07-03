CREATE TRIGGER calcul_note_finale
AFTER INSERT ON notes
BEGIN

UPDATE notes

SET note_finale=(NEW.note_cc+NEW.note_exam)/2

WHERE id=NEW.id;

END;
