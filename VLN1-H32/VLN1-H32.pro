QT += core
QT += core gui
QT += sql
QT += widgets
QT += gui

CONFIG += c++11

TARGET = VLN1-H32
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    userinterface.cpp \
    servicelayer.cpp \
    datalayer.cpp \
    person.cpp \
    computer.cpp \
    mainwindow.cpp \
    addscientistdialog.cpp \
    addcomputerdialog.cpp \
    addlinkdialog.cpp \
<<<<<<< HEAD
    editscientistdialog.cpp \
    editcomputerdialog.cpp \
    deleteconfirmationdialog.cpp \
    moreinfo.cpp
=======
    deleteconfirmationdialog.cpp
>>>>>>> 670f2ff2c1e72ea3fe58937bf144f66c680eb2d2

HEADERS += \
    userinterface.h \
    servicelayer.h \
    datalayer.h \
    person.h \
    computer.h \
    mainwindow.h \
    addscientistdialog.h \
    addcomputerdialog.h \
    addlinkdialog.h \
<<<<<<< HEAD
    editscientistdialog.h \
    editcomputerdialog.h \
    deleteconfirmationdialog.h \
    moreinfo.h
=======
    deleteconfirmationdialog.h
>>>>>>> 670f2ff2c1e72ea3fe58937bf144f66c680eb2d2

DISTFILES +=

FORMS += \
    mainwindow.ui \
    addscientistdialog.ui \
    addcomputerdialog.ui \
    addlinkdialog.ui \
<<<<<<< HEAD
    editscientistdialog.ui \
    editcomputerdialog.ui \
    deleteconfirmationdialog.ui \
    moreinfo.ui
=======
    deleteconfirmationdialog.ui
>>>>>>> 670f2ff2c1e72ea3fe58937bf144f66c680eb2d2
