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
    addlinkdialog.cpp

HEADERS += \
    userinterface.h \
    servicelayer.h \
    datalayer.h \
    person.h \
    computer.h \
    mainwindow.h \
    addscientistdialog.h \
    addcomputerdialog.h \
    addlinkdialog.h

DISTFILES +=

FORMS += \
    mainwindow.ui \
    addscientistdialog.ui \
    addcomputerdialog.ui \
    addlinkdialog.ui
