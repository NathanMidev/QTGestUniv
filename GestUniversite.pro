#-------------------------------------------------
#
# Project created by QtCreator 2026-07-02T21:08:42
#
#-------------------------------------------------
QT += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GestUniversite
TEMPLATE = app

INCLUDEPATH += $$PWD/Headers
INCLUDEPATH += $$PWD/Headers/database
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        controllers/logincontroller.cpp \
        database/databaseinitializer.cpp \
        database/databasemanager.cpp \
        main.cpp \
        mainwindow.cpp \
        models/enseignant.cpp \
        models/etudiant.cpp \
        models/matiere.cpp \
        models/note.cpp \
        models/utilisateur.cpp \
        utils/pdfexporter.cpp

HEADERS += \
        controllers/etudiantcontrolleur.h \
        controllers/logincontroller.h \
        database/databaseinitializer.h \
        database/databasemanager.h \
        mainwindow.h \
        models/enseignant.h \
        models/etudiant.h \
        models/matiere.h \
        models/note.h \
        models/utilisateur.h \
        utils/pdfexporter.h \
        utils/validator.h

FORMS += \
        dashboard.ui \
        emploitemps.ui \
        enseignant.ui \
        etudiant.ui \
        login.ui \
        mainwindow.ui \
        matiere.ui \
        note.ui \
        notification.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md \
    database/create_database.sql \
    database/indexes.sql \
    database/insert_demo_data.sql \
    database/triggers.sql \
    database/views.sql
