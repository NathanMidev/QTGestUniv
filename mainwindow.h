#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

#include "models/enseignant.h"
#include "models/matiere.h"
#include "models/note.h"

namespace Ui {
class MainWindow;
class Dashboard;
class EtudiantForm;
class EnseignantForm;
class MatiereForm;
class NoteForm;
class EmploiTempsForm;
class NotificationForm;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDashboardClicked();
    void onEtudiantsClicked();
    void onEnseignantsClicked();
    void onMatieresClicked();
    void onNotesClicked();
    void onEmploiTempsClicked();
    void onNotificationsClicked();

private:
    void initializeNavigation();
    void refreshDashboard();
    void setupDashboardPage();
    void setupEtudiantPage();
    void setupEnseignantPage();
    void setupMatierePage();
    void setupNotePage();
    void setupEmploiTempsPage();
    void setupNotificationPage();
    void refreshEtudiantTable();
    void refreshEnseignantTable();
    void afficherEnseignants(const QList<Enseignant> &enseignants);
    void refreshMatiereTable();
    void afficherMatieres(const QList<Matiere> &matieres);
    void refreshNoteTable();
    void afficherNotes(const QList<Note> &notes);
    void remplirComboEnseignants();
    void remplirCombosNotes();
    void fillEtudiantFormFromSelection();
    void fillEnseignantFormFromSelection();
    void fillMatiereFormFromSelection();
    void fillNoteFormFromSelection();
    void clearEtudiantForm();

    Ui::MainWindow *ui;
    QWidget *dashboardPage;
    Ui::Dashboard *dashboardUi;
    QWidget *etudiantPage;
    Ui::EtudiantForm *etudiantUi;
    QWidget *enseignantPage;
    Ui::EnseignantForm *enseignantUi;
    QWidget *matierePage;
    Ui::MatiereForm *matiereUi;
    QWidget *notePage;
    Ui::NoteForm *noteUi;
    QWidget *emploiTempsPage;
    Ui::EmploiTempsForm *emploiTempsUi;
    QWidget *notificationPage;
    Ui::NotificationForm *notificationUi;
};

#endif // MAINWINDOW_H
