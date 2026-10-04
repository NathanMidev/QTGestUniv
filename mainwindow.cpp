#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dashboard.h"
#include "ui_etudiant.h"
#include "ui_enseignant.h"
#include "ui_matiere.h"
#include "ui_note.h"
#include "ui_emploitemps.h"
#include "ui_notification.h"

#include "controllers/etudiantcontrolleur.h"
#include "controllers/enseignantcontroller.h"
#include "controllers/matierecontroller.h"
#include "controllers/notecontroller.h"
#include "models/etudiant.h"
#include "models/enseignant.h"
#include "models/matiere.h"
#include "models/note.h"

#include <QLabel>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dashboardPage(nullptr),
    dashboardUi(nullptr),
    etudiantPage(nullptr),
    etudiantUi(nullptr),
    enseignantPage(nullptr),
    enseignantUi(nullptr),
    matierePage(nullptr),
    matiereUi(nullptr),
    notePage(nullptr),
    noteUi(nullptr),
    emploiTempsPage(nullptr),
    emploiTempsUi(nullptr),
    notificationPage(nullptr),
    notificationUi(nullptr)
{
    ui->setupUi(this);
    initializeNavigation();
    setupDashboardPage();
    refreshDashboard();
}

MainWindow::~MainWindow()
{
    if (dashboardUi)
        delete dashboardUi;
    if (dashboardPage)
        delete dashboardPage;
    if (etudiantUi)
        delete etudiantUi;
    if (etudiantPage)
        delete etudiantPage;
    delete enseignantUi;
    delete enseignantPage;
    delete matiereUi;
    delete matierePage;
    delete noteUi;
    delete notePage;
    delete emploiTempsUi;
    delete emploiTempsPage;
    delete notificationUi;
    delete notificationPage;
    delete ui;
}

void MainWindow::initializeNavigation()
{
    connect(ui->btnDashboard, &QPushButton::clicked, this, &MainWindow::onDashboardClicked);
    connect(ui->btnEtudiants, &QPushButton::clicked, this, &MainWindow::onEtudiantsClicked);
    connect(ui->btnEnseignants, &QPushButton::clicked, this, &MainWindow::onEnseignantsClicked);
    connect(ui->btnMatieres, &QPushButton::clicked, this, &MainWindow::onMatieresClicked);
    connect(ui->btnNotes, &QPushButton::clicked, this, &MainWindow::onNotesClicked);
    connect(ui->btnEmploiTemps, &QPushButton::clicked, this, &MainWindow::onEmploiTempsClicked);
    connect(ui->btnNotifications, &QPushButton::clicked, this, &MainWindow::onNotificationsClicked);

    ui->stackedPages->setCurrentIndex(0);
}

void MainWindow::setupDashboardPage()
{
    dashboardPage = new QWidget(this);
    dashboardUi = new Ui::Dashboard;
    dashboardUi->setupUi(dashboardPage);
    ui->stackedPages->addWidget(dashboardPage);

    setupEtudiantPage();
    setupEnseignantPage();
    setupMatierePage();
    setupNotePage();
    setupEmploiTempsPage();
    setupNotificationPage();
}

void MainWindow::setupEtudiantPage()
{
    etudiantPage = new QWidget(this);
    etudiantUi = new Ui::EtudiantForm;
    etudiantUi->setupUi(etudiantPage);

    connect(etudiantUi->btnActualiser, &QPushButton::clicked, this, [=]() {
        refreshEtudiantTable();
    });

    connect(etudiantUi->btnRechercher, &QPushButton::clicked, this, [=]() {
        const QString filtre = etudiantUi->txtRecherche->text().trimmed();
        QList<Etudiant> resultats = EtudiantController::rechercher(filtre);
        etudiantUi->tableEtudiants->setRowCount(0);

        for (const Etudiant &etudiant : resultats)
        {
            const int row = etudiantUi->tableEtudiants->rowCount();
            etudiantUi->tableEtudiants->insertRow(row);
            etudiantUi->tableEtudiants->setItem(row, 0, new QTableWidgetItem(QString::number(etudiant.getId())));
            etudiantUi->tableEtudiants->setItem(row, 1, new QTableWidgetItem(etudiant.getMatricule()));
            etudiantUi->tableEtudiants->setItem(row, 2, new QTableWidgetItem(etudiant.getNom()));
            etudiantUi->tableEtudiants->setItem(row, 3, new QTableWidgetItem(etudiant.getPrenom()));
            etudiantUi->tableEtudiants->setItem(row, 4, new QTableWidgetItem(etudiant.getEmail()));
            etudiantUi->tableEtudiants->setItem(row, 5, new QTableWidgetItem(etudiant.getTelephone()));
            etudiantUi->tableEtudiants->setItem(row, 6, new QTableWidgetItem(etudiant.getNiveau()));
            etudiantUi->tableEtudiants->setItem(row, 7, new QTableWidgetItem(QString::number(etudiant.getFiliereId())));
        }
    });

    connect(etudiantUi->tableEtudiants, &QTableWidget::itemSelectionChanged, this, [=]() {
        fillEtudiantFormFromSelection();
    });

    connect(etudiantUi->btnAjouter, &QPushButton::clicked, this, [=]() {
        Etudiant etudiant;
        etudiant.setMatricule(etudiantUi->txtMatricule->text().trimmed());
        etudiant.setNom(etudiantUi->txtNom->text().trimmed());
        etudiant.setPrenom(etudiantUi->txtPrenom->text().trimmed());
        etudiant.setEmail(etudiantUi->txtEmail->text().trimmed());
        etudiant.setTelephone(etudiantUi->txtTelephone->text().trimmed());
        etudiant.setNiveau(etudiantUi->txtNiveau->text().trimmed());
        etudiant.setFiliereId(etudiantUi->spinFiliereId->value());

        if (etudiant.getMatricule().isEmpty() || etudiant.getNom().isEmpty() || etudiant.getPrenom().isEmpty())
        {
            QMessageBox::warning(this, "Erreur", "Les champs Matricule, Nom et Prénom sont obligatoires.");
            return;
        }

        if (!EtudiantController::ajouter(etudiant))
        {
            QMessageBox::warning(this, "Erreur", "Impossible d'ajouter cet étudiant.");
            return;
        }

        QMessageBox::information(this, "Succès", "Étudiant ajouté avec succès.");
        clearEtudiantForm();
        refreshEtudiantTable();
    });

    connect(etudiantUi->btnModifier, &QPushButton::clicked, this, [=]() {
        const int row = etudiantUi->tableEtudiants->currentRow();
        if (row < 0)
        {
            QMessageBox::warning(this, "Erreur", "Sélectionnez un étudiant à modifier.");
            return;
        }

        const int id = etudiantUi->tableEtudiants->item(row, 0)->text().toInt();
        Etudiant etudiant = Etudiant::getById(id);
        etudiant.setMatricule(etudiantUi->txtMatricule->text().trimmed());
        etudiant.setNom(etudiantUi->txtNom->text().trimmed());
        etudiant.setPrenom(etudiantUi->txtPrenom->text().trimmed());
        etudiant.setEmail(etudiantUi->txtEmail->text().trimmed());
        etudiant.setTelephone(etudiantUi->txtTelephone->text().trimmed());
        etudiant.setNiveau(etudiantUi->txtNiveau->text().trimmed());
        etudiant.setFiliereId(etudiantUi->spinFiliereId->value());

        if (!EtudiantController::modifier(etudiant))
        {
            QMessageBox::warning(this, "Erreur", "Impossible de modifier cet étudiant.");
            return;
        }

        QMessageBox::information(this, "Succès", "Étudiant modifié avec succès.");
        refreshEtudiantTable();
    });

    connect(etudiantUi->btnSupprimer, &QPushButton::clicked, this, [=]() {
        const int row = etudiantUi->tableEtudiants->currentRow();
        if (row < 0)
        {
            QMessageBox::warning(this, "Erreur", "Sélectionnez un étudiant à supprimer.");
            return;
        }

        const int id = etudiantUi->tableEtudiants->item(row, 0)->text().toInt();
        const QMessageBox::StandardButton rep = QMessageBox::question(
            this,
            "Confirmation",
            "Êtes-vous sûr de vouloir supprimer cet étudiant ?",
            QMessageBox::Yes | QMessageBox::No
        );

        if (rep != QMessageBox::Yes)
            return;

        if (!EtudiantController::supprimer(id))
        {
            QMessageBox::warning(this, "Erreur", "Impossible de supprimer cet étudiant.");
            return;
        }

        QMessageBox::information(this, "Succès", "Étudiant supprimé avec succès.");
        clearEtudiantForm();
        refreshEtudiantTable();
    });

    refreshEtudiantTable();
    ui->stackedPages->addWidget(etudiantPage);
}

void MainWindow::setupEnseignantPage()
{
    enseignantPage = new QWidget(this);
    enseignantUi = new Ui::EnseignantForm;
    enseignantUi->setupUi(enseignantPage);
    enseignantUi->tableEnseignants->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(enseignantUi->btnActualiser, &QPushButton::clicked, this, &MainWindow::refreshEnseignantTable);
    connect(enseignantUi->btnRechercher, &QPushButton::clicked, this, [this]() {
        afficherEnseignants(EnseignantController::rechercher(enseignantUi->txtRecherche->text()));
    });
    connect(enseignantUi->tableEnseignants, &QTableWidget::itemSelectionChanged,
            this, &MainWindow::fillEnseignantFormFromSelection);

    connect(enseignantUi->btnAjouter, &QPushButton::clicked, this, [this]() {
        Enseignant enseignant;
        enseignant.setMatricule(enseignantUi->txtMatricule->text().trimmed());
        enseignant.setNom(enseignantUi->txtNom->text().trimmed());
        enseignant.setPrenom(enseignantUi->txtPrenom->text().trimmed());
        enseignant.setGrade(enseignantUi->txtGrade->text().trimmed());
        enseignant.setEmail(enseignantUi->txtEmail->text().trimmed());
        enseignant.setTelephone(enseignantUi->txtTelephone->text().trimmed());
        enseignant.setSpecialite(enseignantUi->txtSpecialite->text().trimmed());
        enseignant.setDepartementId(enseignantUi->spinDepartementId->value());

        if (!EnseignantController::ajouter(enseignant))
        {
            QMessageBox::warning(this, "Erreur", "Vérifiez les champs obligatoires et l'identifiant du département.");
            return;
        }

        enseignantUi->txtMatricule->clear();
        enseignantUi->txtNom->clear();
        enseignantUi->txtPrenom->clear();
        enseignantUi->txtGrade->clear();
        enseignantUi->txtEmail->clear();
        enseignantUi->txtTelephone->clear();
        enseignantUi->txtSpecialite->clear();
        enseignantUi->spinDepartementId->setValue(0);
        refreshEnseignantTable();
    });

    connect(enseignantUi->btnModifier, &QPushButton::clicked, this, [this]() {
        const int row = enseignantUi->tableEnseignants->currentRow();
        if (row < 0 || !enseignantUi->tableEnseignants->item(row, 0))
        {
            QMessageBox::warning(this, "Erreur", "Sélectionnez un enseignant à modifier.");
            return;
        }

        Enseignant enseignant = Enseignant::getById(enseignantUi->tableEnseignants->item(row, 0)->text().toInt());
        enseignant.setMatricule(enseignantUi->txtMatricule->text().trimmed());
        enseignant.setNom(enseignantUi->txtNom->text().trimmed());
        enseignant.setPrenom(enseignantUi->txtPrenom->text().trimmed());
        enseignant.setGrade(enseignantUi->txtGrade->text().trimmed());
        enseignant.setEmail(enseignantUi->txtEmail->text().trimmed());
        enseignant.setTelephone(enseignantUi->txtTelephone->text().trimmed());
        enseignant.setSpecialite(enseignantUi->txtSpecialite->text().trimmed());
        enseignant.setDepartementId(enseignantUi->spinDepartementId->value());

        if (!EnseignantController::modifier(enseignant))
        {
            QMessageBox::warning(this, "Erreur", "Impossible de modifier cet enseignant.");
            return;
        }
        refreshEnseignantTable();
        remplirComboEnseignants();
    });

    connect(enseignantUi->btnSupprimer, &QPushButton::clicked, this, [this]() {
        const int row = enseignantUi->tableEnseignants->currentRow();
        if (row < 0 || !enseignantUi->tableEnseignants->item(row, 0))
        {
            QMessageBox::warning(this, "Erreur", "Sélectionnez un enseignant à supprimer.");
            return;
        }
        if (QMessageBox::question(this, "Confirmation", "Supprimer cet enseignant ?",
                                  QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes)
            return;

        if (!EnseignantController::supprimer(enseignantUi->tableEnseignants->item(row, 0)->text().toInt()))
        {
            QMessageBox::warning(this, "Erreur", "Suppression impossible. Cet enseignant peut être utilisé par une matière ou un emploi du temps.");
            return;
        }
        refreshEnseignantTable();
        remplirComboEnseignants();
    });

    refreshEnseignantTable();
    ui->stackedPages->addWidget(enseignantPage);
}

void MainWindow::afficherEnseignants(const QList<Enseignant> &enseignants)
{
    enseignantUi->tableEnseignants->setRowCount(0);
    for (const Enseignant &enseignant : enseignants)
    {
        const int row = enseignantUi->tableEnseignants->rowCount();
        enseignantUi->tableEnseignants->insertRow(row);
        enseignantUi->tableEnseignants->setItem(row, 0, new QTableWidgetItem(QString::number(enseignant.getId())));
        enseignantUi->tableEnseignants->setItem(row, 1, new QTableWidgetItem(enseignant.getMatricule()));
        enseignantUi->tableEnseignants->setItem(row, 2, new QTableWidgetItem(enseignant.getNom()));
        enseignantUi->tableEnseignants->setItem(row, 3, new QTableWidgetItem(enseignant.getPrenom()));
        enseignantUi->tableEnseignants->setItem(row, 4, new QTableWidgetItem(enseignant.getGrade()));
        enseignantUi->tableEnseignants->setItem(row, 5, new QTableWidgetItem(enseignant.getEmail()));
        enseignantUi->tableEnseignants->setItem(row, 6, new QTableWidgetItem(enseignant.getTelephone()));
        enseignantUi->tableEnseignants->setItem(row, 7, new QTableWidgetItem(enseignant.getSpecialite()));
        enseignantUi->tableEnseignants->setItem(row, 8, new QTableWidgetItem(QString::number(enseignant.getDepartementId())));
    }
}

void MainWindow::refreshEnseignantTable()
{
    if (enseignantUi)
        afficherEnseignants(EnseignantController::getAll());
}

void MainWindow::fillEnseignantFormFromSelection()
{
    const int row = enseignantUi->tableEnseignants->currentRow();
    if (row < 0 || !enseignantUi->tableEnseignants->item(row, 0))
        return;
    const Enseignant enseignant = Enseignant::getById(enseignantUi->tableEnseignants->item(row, 0)->text().toInt());
    enseignantUi->txtMatricule->setText(enseignant.getMatricule());
    enseignantUi->txtNom->setText(enseignant.getNom());
    enseignantUi->txtPrenom->setText(enseignant.getPrenom());
    enseignantUi->txtGrade->setText(enseignant.getGrade());
    enseignantUi->txtEmail->setText(enseignant.getEmail());
    enseignantUi->txtTelephone->setText(enseignant.getTelephone());
    enseignantUi->txtSpecialite->setText(enseignant.getSpecialite());
    enseignantUi->spinDepartementId->setValue(enseignant.getDepartementId());
}

void MainWindow::setupMatierePage()
{
    matierePage = new QWidget(this);
    matiereUi = new Ui::MatiereForm;
    matiereUi->setupUi(matierePage);
    matiereUi->tableMatieres->setEditTriggers(QAbstractItemView::NoEditTriggers);
    remplirComboEnseignants();

    connect(matiereUi->btnActualiser, &QPushButton::clicked, this, [this]() {
        remplirComboEnseignants();
        refreshMatiereTable();
    });
    connect(matiereUi->btnRechercher, &QPushButton::clicked, this, [this]() {
        afficherMatieres(MatiereController::rechercher(matiereUi->txtRecherche->text()));
    });
    connect(matiereUi->tableMatieres, &QTableWidget::itemSelectionChanged,
            this, &MainWindow::fillMatiereFormFromSelection);
    connect(matiereUi->btnAjouter, &QPushButton::clicked, this, [this]() {
        Matiere matiere;
        matiere.setCode(matiereUi->txtCode->text().trimmed());
        matiere.setIntitule(matiereUi->txtIntitule->text().trimmed());
        matiere.setCoefficient(matiereUi->spinCoefficient->value());
        matiere.setCredits(matiereUi->spinCredits->value());
        matiere.setEnseignantId(matiereUi->comboEnseignant->currentData().toInt());
        if (!MatiereController::ajouter(matiere))
        {
            QMessageBox::warning(this, "Erreur", "Vérifiez le code et l'intitulé de la matière.");
            return;
        }
        matiereUi->txtCode->clear();
        matiereUi->txtIntitule->clear();
        matiereUi->spinCoefficient->setValue(1);
        matiereUi->spinCredits->setValue(0);
        matiereUi->comboEnseignant->setCurrentIndex(0);
        refreshMatiereTable();
    });
    connect(matiereUi->btnModifier, &QPushButton::clicked, this, [this]() {
        const int row = matiereUi->tableMatieres->currentRow();
        if (row < 0 || !matiereUi->tableMatieres->item(row, 0))
        {
            QMessageBox::warning(this, "Erreur", "Sélectionnez une matière à modifier.");
            return;
        }
        Matiere matiere = Matiere::getById(matiereUi->tableMatieres->item(row, 0)->text().toInt());
        matiere.setCode(matiereUi->txtCode->text().trimmed());
        matiere.setIntitule(matiereUi->txtIntitule->text().trimmed());
        matiere.setCoefficient(matiereUi->spinCoefficient->value());
        matiere.setCredits(matiereUi->spinCredits->value());
        matiere.setEnseignantId(matiereUi->comboEnseignant->currentData().toInt());
        if (!MatiereController::modifier(matiere))
        {
            QMessageBox::warning(this, "Erreur", "Impossible de modifier cette matière.");
            return;
        }
        refreshMatiereTable();
    });
    connect(matiereUi->btnSupprimer, &QPushButton::clicked, this, [this]() {
        const int row = matiereUi->tableMatieres->currentRow();
        if (row < 0 || !matiereUi->tableMatieres->item(row, 0))
        {
            QMessageBox::warning(this, "Erreur", "Sélectionnez une matière à supprimer.");
            return;
        }
        if (QMessageBox::question(this, "Confirmation", "Supprimer cette matière ?",
                                  QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes)
            return;
        if (!MatiereController::supprimer(matiereUi->tableMatieres->item(row, 0)->text().toInt()))
        {
            QMessageBox::warning(this, "Erreur", "Suppression impossible. Cette matière peut être utilisée par des notes ou un emploi du temps.");
            return;
        }
        refreshMatiereTable();
    });

    refreshMatiereTable();
    ui->stackedPages->addWidget(matierePage);
}

void MainWindow::remplirComboEnseignants()
{
    if (!matiereUi)
        return;
    const int selectedId = matiereUi->comboEnseignant->currentData().toInt();
    matiereUi->comboEnseignant->clear();
    matiereUi->comboEnseignant->addItem("Aucun enseignant", 0);
    const QList<Enseignant> enseignants = EnseignantController::getAll();
    for (const Enseignant &enseignant : enseignants)
        matiereUi->comboEnseignant->addItem(
            QString("%1 - %2 %3").arg(enseignant.getId()).arg(enseignant.getNom(), enseignant.getPrenom()),
            enseignant.getId());
    const int index = matiereUi->comboEnseignant->findData(selectedId);
    matiereUi->comboEnseignant->setCurrentIndex(index >= 0 ? index : 0);
}

void MainWindow::afficherMatieres(const QList<Matiere> &matieres)
{
    matiereUi->tableMatieres->setRowCount(0);
    for (const Matiere &matiere : matieres)
    {
        const int row = matiereUi->tableMatieres->rowCount();
        matiereUi->tableMatieres->insertRow(row);
        matiereUi->tableMatieres->setItem(row, 0, new QTableWidgetItem(QString::number(matiere.getId())));
        matiereUi->tableMatieres->setItem(row, 1, new QTableWidgetItem(matiere.getCode()));
        matiereUi->tableMatieres->setItem(row, 2, new QTableWidgetItem(matiere.getIntitule()));
        matiereUi->tableMatieres->setItem(row, 3, new QTableWidgetItem(QString::number(matiere.getCoefficient())));
        matiereUi->tableMatieres->setItem(row, 4, new QTableWidgetItem(QString::number(matiere.getCredits())));
        const Enseignant enseignant = Enseignant::getById(matiere.getEnseignantId());
        const QString enseignantLabel = matiere.getEnseignantId() > 0
            ? QString("%1 - %2 %3").arg(enseignant.getId()).arg(enseignant.getNom(), enseignant.getPrenom())
            : QString("Aucun enseignant");
        matiereUi->tableMatieres->setItem(row, 5, new QTableWidgetItem(enseignantLabel));
    }
}

void MainWindow::refreshMatiereTable()
{
    if (matiereUi)
        afficherMatieres(MatiereController::getAll());
}

void MainWindow::fillMatiereFormFromSelection()
{
    const int row = matiereUi->tableMatieres->currentRow();
    if (row < 0 || !matiereUi->tableMatieres->item(row, 0))
        return;
    const Matiere matiere = Matiere::getById(matiereUi->tableMatieres->item(row, 0)->text().toInt());
    matiereUi->txtCode->setText(matiere.getCode());
    matiereUi->txtIntitule->setText(matiere.getIntitule());
    matiereUi->spinCoefficient->setValue(matiere.getCoefficient());
    matiereUi->spinCredits->setValue(matiere.getCredits());
    const int index = matiereUi->comboEnseignant->findData(matiere.getEnseignantId());
    matiereUi->comboEnseignant->setCurrentIndex(index >= 0 ? index : 0);
}

void MainWindow::setupNotePage()
{
    notePage = new QWidget(this);
    noteUi = new Ui::NoteForm;
    noteUi->setupUi(notePage);
    noteUi->tableNotes->setEditTriggers(QAbstractItemView::NoEditTriggers);
    remplirCombosNotes();

    const auto calculerFinale = [this]() {
        noteUi->spinFinale->setValue((noteUi->spinCC->value() + noteUi->spinExamen->value()) / 2.0);
    };
    connect(noteUi->spinCC, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
            [calculerFinale](double) { calculerFinale(); });
    connect(noteUi->spinExamen, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
            [calculerFinale](double) { calculerFinale(); });
    connect(noteUi->btnActualiser, &QPushButton::clicked, this, [this]() {
        remplirCombosNotes();
        refreshNoteTable();
    });
    connect(noteUi->btnRechercher, &QPushButton::clicked, this, [this]() {
        afficherNotes(NoteController::rechercher(noteUi->txtRecherche->text()));
    });
    connect(noteUi->tableNotes, &QTableWidget::itemSelectionChanged,
            this, &MainWindow::fillNoteFormFromSelection);
    connect(noteUi->btnAjouter, &QPushButton::clicked, this, [this]() {
        Note note;
        note.setEtudiantId(noteUi->comboEtudiant->currentData().toInt());
        note.setMatiereId(noteUi->comboMatiere->currentData().toInt());
        note.setSemestre(noteUi->spinSemestre->value());
        note.setNoteCC(static_cast<float>(noteUi->spinCC->value()));
        note.setNoteExamen(static_cast<float>(noteUi->spinExamen->value()));
        note.setNoteFinale(static_cast<float>(noteUi->spinFinale->value()));
        if (!NoteController::ajouter(note))
        {
            QMessageBox::warning(this, "Erreur", "Sélectionnez un étudiant, une matière et un semestre valides.");
            return;
        }
        noteUi->txtRecherche->clear();
        refreshNoteTable();
    });
    connect(noteUi->btnModifier, &QPushButton::clicked, this, [this]() {
        const int row = noteUi->tableNotes->currentRow();
        if (row < 0 || !noteUi->tableNotes->item(row, 0))
        {
            QMessageBox::warning(this, "Erreur", "Sélectionnez une note à modifier.");
            return;
        }
        Note note = Note::getById(noteUi->tableNotes->item(row, 0)->text().toInt());
        note.setEtudiantId(noteUi->comboEtudiant->currentData().toInt());
        note.setMatiereId(noteUi->comboMatiere->currentData().toInt());
        note.setSemestre(noteUi->spinSemestre->value());
        note.setNoteCC(static_cast<float>(noteUi->spinCC->value()));
        note.setNoteExamen(static_cast<float>(noteUi->spinExamen->value()));
        note.setNoteFinale(static_cast<float>(noteUi->spinFinale->value()));
        if (!NoteController::modifier(note))
        {
            QMessageBox::warning(this, "Erreur", "Impossible de modifier cette note.");
            return;
        }
        refreshNoteTable();
    });
    connect(noteUi->btnSupprimer, &QPushButton::clicked, this, [this]() {
        const int row = noteUi->tableNotes->currentRow();
        if (row < 0 || !noteUi->tableNotes->item(row, 0))
        {
            QMessageBox::warning(this, "Erreur", "Sélectionnez une note à supprimer.");
            return;
        }
        if (QMessageBox::question(this, "Confirmation", "Supprimer cette note ?",
                                  QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes)
            return;
        if (!NoteController::supprimer(noteUi->tableNotes->item(row, 0)->text().toInt()))
        {
            QMessageBox::warning(this, "Erreur", "Impossible de supprimer cette note.");
            return;
        }
        refreshNoteTable();
    });

    refreshNoteTable();
    ui->stackedPages->addWidget(notePage);
}

void MainWindow::remplirCombosNotes()
{
    if (!noteUi)
        return;
    const int etudiantId = noteUi->comboEtudiant->currentData().toInt();
    const int matiereId = noteUi->comboMatiere->currentData().toInt();
    noteUi->comboEtudiant->clear();
    for (const Etudiant &etudiant : EtudiantController::getAll())
        noteUi->comboEtudiant->addItem(
            QString("%1 - %2 %3").arg(etudiant.getId()).arg(etudiant.getNom(), etudiant.getPrenom()),
            etudiant.getId());
    noteUi->comboMatiere->clear();
    for (const Matiere &matiere : MatiereController::getAll())
        noteUi->comboMatiere->addItem(
            QString("%1 - %2").arg(matiere.getId()).arg(matiere.getIntitule()), matiere.getId());
    const int selectedEtudiant = noteUi->comboEtudiant->findData(etudiantId);
    const int selectedMatiere = noteUi->comboMatiere->findData(matiereId);
    if (selectedEtudiant >= 0)
        noteUi->comboEtudiant->setCurrentIndex(selectedEtudiant);
    if (selectedMatiere >= 0)
        noteUi->comboMatiere->setCurrentIndex(selectedMatiere);
}

void MainWindow::afficherNotes(const QList<Note> &notes)
{
    noteUi->tableNotes->setRowCount(0);
    for (const Note &note : notes)
    {
        const int row = noteUi->tableNotes->rowCount();
        noteUi->tableNotes->insertRow(row);
        noteUi->tableNotes->setItem(row, 0, new QTableWidgetItem(QString::number(note.getId())));
        const Etudiant etudiant = Etudiant::getById(note.getEtudiantId());
        const Matiere matiere = Matiere::getById(note.getMatiereId());
        const QString etudiantLabel = etudiant.getId() > 0
            ? QString("%1 - %2 %3").arg(etudiant.getId()).arg(etudiant.getNom(), etudiant.getPrenom())
            : QString::number(note.getEtudiantId());
        const QString matiereLabel = matiere.getId() > 0
            ? QString("%1 - %2").arg(matiere.getId()).arg(matiere.getIntitule())
            : QString::number(note.getMatiereId());
        noteUi->tableNotes->setItem(row, 1, new QTableWidgetItem(etudiantLabel));
        noteUi->tableNotes->setItem(row, 2, new QTableWidgetItem(matiereLabel));
        noteUi->tableNotes->setItem(row, 3, new QTableWidgetItem(QString::number(note.getSemestre())));
        noteUi->tableNotes->setItem(row, 4, new QTableWidgetItem(QString::number(note.getNoteCC(), 'f', 2)));
        noteUi->tableNotes->setItem(row, 5, new QTableWidgetItem(QString::number(note.getNoteExamen(), 'f', 2)));
        noteUi->tableNotes->setItem(row, 6, new QTableWidgetItem(QString::number(note.getNoteFinale(), 'f', 2)));
    }
}

void MainWindow::refreshNoteTable()
{
    if (noteUi)
        afficherNotes(NoteController::getAll());
}

void MainWindow::fillNoteFormFromSelection()
{
    const int row = noteUi->tableNotes->currentRow();
    if (row < 0 || !noteUi->tableNotes->item(row, 0))
        return;
    const Note note = Note::getById(noteUi->tableNotes->item(row, 0)->text().toInt());
    const int etudiantIndex = noteUi->comboEtudiant->findData(note.getEtudiantId());
    const int matiereIndex = noteUi->comboMatiere->findData(note.getMatiereId());
    if (etudiantIndex >= 0)
        noteUi->comboEtudiant->setCurrentIndex(etudiantIndex);
    if (matiereIndex >= 0)
        noteUi->comboMatiere->setCurrentIndex(matiereIndex);
    noteUi->spinSemestre->setValue(note.getSemestre());
    noteUi->spinCC->setValue(note.getNoteCC());
    noteUi->spinExamen->setValue(note.getNoteExamen());
    noteUi->spinFinale->setValue(note.getNoteFinale());
}

void MainWindow::setupEmploiTempsPage()
{
    emploiTempsPage = new QWidget(this);
    emploiTempsUi = new Ui::EmploiTempsForm;
    emploiTempsUi->setupUi(emploiTempsPage);
    emploiTempsUi->tableEmploisTemps->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->stackedPages->addWidget(emploiTempsPage);
}

void MainWindow::setupNotificationPage()
{
    notificationPage = new QWidget(this);
    notificationUi = new Ui::NotificationForm;
    notificationUi->setupUi(notificationPage);
    notificationUi->tableNotifications->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->stackedPages->addWidget(notificationPage);
}

void MainWindow::refreshEtudiantTable()
{
    if (!etudiantUi)
        return;

    QList<Etudiant> etudiants = EtudiantController::getAll();
    etudiantUi->tableEtudiants->setRowCount(0);

    for (const Etudiant &etudiant : etudiants)
    {
        const int row = etudiantUi->tableEtudiants->rowCount();
        etudiantUi->tableEtudiants->insertRow(row);
        etudiantUi->tableEtudiants->setItem(row, 0, new QTableWidgetItem(QString::number(etudiant.getId())));
        etudiantUi->tableEtudiants->setItem(row, 1, new QTableWidgetItem(etudiant.getMatricule()));
        etudiantUi->tableEtudiants->setItem(row, 2, new QTableWidgetItem(etudiant.getNom()));
        etudiantUi->tableEtudiants->setItem(row, 3, new QTableWidgetItem(etudiant.getPrenom()));
        etudiantUi->tableEtudiants->setItem(row, 4, new QTableWidgetItem(etudiant.getEmail()));
        etudiantUi->tableEtudiants->setItem(row, 5, new QTableWidgetItem(etudiant.getTelephone()));
        etudiantUi->tableEtudiants->setItem(row, 6, new QTableWidgetItem(etudiant.getNiveau()));
        etudiantUi->tableEtudiants->setItem(row, 7, new QTableWidgetItem(QString::number(etudiant.getFiliereId())));
    }
}

void MainWindow::fillEtudiantFormFromSelection()
{
    if (!etudiantUi)
        return;

    const int row = etudiantUi->tableEtudiants->currentRow();
    if (row < 0)
        return;

    const QTableWidgetItem *idItem = etudiantUi->tableEtudiants->item(row, 0);
    if (!idItem)
        return;

    const int id = idItem->text().toInt();
    const Etudiant etudiant = Etudiant::getById(id);
    etudiantUi->txtMatricule->setText(etudiant.getMatricule());
    etudiantUi->txtNom->setText(etudiant.getNom());
    etudiantUi->txtPrenom->setText(etudiant.getPrenom());
    etudiantUi->txtEmail->setText(etudiant.getEmail());
    etudiantUi->txtTelephone->setText(etudiant.getTelephone());
    etudiantUi->txtNiveau->setText(etudiant.getNiveau());
    etudiantUi->spinFiliereId->setValue(etudiant.getFiliereId());
}

void MainWindow::clearEtudiantForm()
{
    if (!etudiantUi)
        return;

    etudiantUi->txtMatricule->clear();
    etudiantUi->txtNom->clear();
    etudiantUi->txtPrenom->clear();
    etudiantUi->txtEmail->clear();
    etudiantUi->txtTelephone->clear();
    etudiantUi->txtNiveau->clear();
    etudiantUi->txtRecherche->clear();
    etudiantUi->spinFiliereId->setValue(0);
    etudiantUi->tableEtudiants->clearSelection();
}

void MainWindow::refreshDashboard()
{
    if (!dashboardUi)
        return;

    const QList<Etudiant> etudiants = Etudiant::getAll();
    const QList<Enseignant> enseignants = Enseignant::getAll();
    const QList<Matiere> matieres = Matiere::getAll();
    const QList<Note> notes = Note::getAll();

    const int nbEtudiants = etudiants.size();
    const int nbEnseignants = enseignants.size();
    const int nbMatieres = matieres.size();
    const int nbNotes = notes.size();

    double moyenne = 0.0;
    double somme = 0.0;
    for (const Note &note : notes)
        somme += note.getNoteFinale();

    if (nbNotes > 0)
        moyenne = somme / nbNotes;

    dashboardUi->lblEtudiants->setText(QString::number(nbEtudiants));
    dashboardUi->lblEnseignants->setText(QString::number(nbEnseignants));
    dashboardUi->lblMatieres->setText(QString::number(nbMatieres));
    dashboardUi->lblNotes->setText(QString::number(nbNotes));
    dashboardUi->lblMoyenneGenerale->setText(QString::number(moyenne, 'f', 2));
}

void MainWindow::onDashboardClicked()
{
    ui->stackedPages->setCurrentIndex(0);
}

void MainWindow::onEtudiantsClicked()
{
    refreshEtudiantTable();
    ui->stackedPages->setCurrentIndex(1);
}

void MainWindow::onEnseignantsClicked()
{
    ui->stackedPages->setCurrentIndex(2);
}

void MainWindow::onMatieresClicked()
{
    ui->stackedPages->setCurrentIndex(3);
}

void MainWindow::onNotesClicked()
{
    ui->stackedPages->setCurrentIndex(4);
}

void MainWindow::onEmploiTempsClicked()
{
    ui->stackedPages->setCurrentIndex(5);
}

void MainWindow::onNotificationsClicked()
{
    ui->stackedPages->setCurrentIndex(6);
}
