QT += core
QT -= gui

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
    computer.cpp

HEADERS += \
    userinterface.h \
    servicelayer.h \
    datalayer.h \
    person.h \
    computer.h
