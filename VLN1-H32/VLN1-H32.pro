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
    servicelayer.cpp \
    datalayer.cpp \
    person.cpp \
    computer.cpp \
    mainwindow.cpp \
    addscientistdialog.cpp \
    addcomputerdialog.cpp \
    addlinkdialog.cpp \
    deleteconfirmationdialog.cpp \
    moreinfo.cpp \
    models.cpp
    deleteconfirmationdialog.cpp

HEADERS += \
    servicelayer.h \
    datalayer.h \
    person.h \
    computer.h \
    mainwindow.h \
    addscientistdialog.h \
    addcomputerdialog.h \
    addlinkdialog.h \
    deleteconfirmationdialog.h \
    moreinfo.h
    deleteconfirmationdialog.h

DISTFILES += \
    images/Scientists/Donald Knuth.gif \
    images/Scientists/Edgar F. Codd.gif \
    images/Scientists/Steve Wozniak.gif \
    images/Scientists/Ada Lovelace.jpg \
    images/Scientists/Adele Goldberg.jpg \
    images/Scientists/Alan Kay.jpg \
    images/Scientists/Alan Turing.jpg \
    images/Scientists/Anita Borg.jpg \
    images/Scientists/Barbara Liskov.jpg \
    images/Scientists/Bill Gates.jpeg \
    images/Scientists/Bjarne Stroustrup.jpg \
    images/Scientists/Brian Kernighan.jpg \
    images/Scientists/Charles Babbage.jpg \
    images/Scientists/Claude Shannon.jpg \
    images/Scientists/Dennis Ritchie.jpg \
    images/Scientists/Douglas Crockford.jpg \
    images/Scientists/Edsger W. Dijkstra.jpg \
    images/Scientists/Frances Allen.jpg \
    images/Scientists/George Boole.jpg \
    images/Scientists/Grace Hopper.jpg \
    images/Scientists/Guido van Rossum.jpg \
    images/Scientists/James Gosling.jpg \
    images/Scientists/Jean Bartik.jpg \
    images/Scientists/Jean E. Sammet.jpg \
    images/Scientists/John Backus.jpg \
    images/Scientists/John Vincent Atanasoff.jpg \
    images/Scientists/John Von Neumann.jpg \
    images/Scientists/Ken Thompson.jpg \
    images/Scientists/Larry Page.jpg \
    images/Scientists/Leslie Lamport.jpg \
    images/Scientists/Linus Torvalds.jpg \
    images/Scientists/Lois Haibt.jpg \
    images/Scientists/Lynn Conway.jpg \
    images/Scientists/Margaret Hamilton.jpg \
    images/Scientists/Marissa Mayer.jpg \
    images/Scientists/Michael Widenius.jpg \
    images/Scientists/Niklaus Wirth.jpg \
    images/Scientists/Per Brinch Hansen.jpg \
    images/Scientists/Radia Perlman.jpg \
    images/Scientists/Richard Stallman.jpeg \
    images/Scientists/Sergey Brin.jpg \
    images/Scientists/Shafi Goldwasser.jpg \
    images/Scientists/Sophie Wilson.jpg \
    images/Scientists/Tim Berners.jpg \
    images/noImage.jpg \
    images/random.jpg \
    images/Scientists/John McCarthy.png \
    images/Scientists/Donald Knuth.gif \
    images/Scientists/Edgar F. Codd.gif \
    images/Scientists/Steve Wozniak.gif \
    images/Scientists/Ada Lovelace.jpg \
    images/Scientists/Adele Goldberg.jpg \
    images/Scientists/Alan Kay.jpg \
    images/Scientists/Alan Turing.jpg \
    images/Scientists/Anita Borg.jpg \
    images/Scientists/Barbara Liskov.jpg \
    images/Scientists/Bill Gates.jpeg \
    images/Scientists/Bjarne Stroustrup.jpg \
    images/Scientists/Brian Kernighan.jpg \
    images/Scientists/Charles Babbage.jpg \
    images/Scientists/Claude Shannon.jpg \
    images/Scientists/Dennis Ritchie.jpg \
    images/Scientists/Douglas Crockford.jpg \
    images/Scientists/Edsger W. Dijkstra.jpg \
    images/Scientists/Frances Allen.jpg \
    images/Scientists/George Boole.jpg \
    images/Scientists/Grace Hopper.jpg \
    images/Scientists/Guido van Rossum.jpg \
    images/Scientists/James Gosling.jpg \
    images/Scientists/Jean Bartik.jpg \
    images/Scientists/Jean E. Sammet.jpg \
    images/Scientists/John Backus.jpg \
    images/Scientists/John Vincent Atanasoff.jpg \
    images/Scientists/John Von Neumann.jpg \
    images/Scientists/Ken Thompson.jpg \
    images/Scientists/Larry Page.jpg \
    images/Scientists/Leslie Lamport.jpg \
    images/Scientists/Linus Torvalds.jpg \
    images/Scientists/Lois Haibt.jpg \
    images/Scientists/Lynn Conway.jpg \
    images/Scientists/Margaret Hamilton.jpg \
    images/Scientists/Marissa Mayer.jpg \
    images/Scientists/Michael Widenius.jpg \
    images/Scientists/Niklaus Wirth.jpg \
    images/Scientists/Per Brinch Hansen.jpg \
    images/Scientists/Radia Perlman.jpg \
    images/Scientists/Richard Stallman.jpeg \
    images/Scientists/Sergey Brin.jpg \
    images/Scientists/Shafi Goldwasser.jpg \
    images/Scientists/Sophie Wilson.jpg \
    images/Scientists/Tim Berners.jpg \
    images/Scientists/John McCarthy.png \
    images/Scientists/Donald Knuth.gif \
    images/Scientists/Edgar F. Codd.gif \
    images/Scientists/Steve Wozniak.gif \
    images/Computers/Apollo Guidance Computer.jpg \
    images/Computers/Atanasoff-Berry Computer.jpg \
    images/Computers/BESK.jpg \
    images/Computers/BINAC.jpg \
    images/Computers/Commadore 64.jpg \
    images/Computers/Compaq Deskpro.jpg \
    images/Computers/Cray-1.jpg \
    images/Computers/CSIRAC.jpg \
    images/Computers/DEC PDP-8.jpg \
    images/Computers/Difference Engine.jpg \
    images/Computers/EDSAC.jpg \
    images/Computers/ENIAC.jpg \
    images/Computers/Harwell Dekatron.jpg \
    images/Computers/IBM 305 RAMAC.jpg \
    images/Computers/IBM 650.jpg \
    images/Computers/IBM NORC.jpg \
    images/Computers/IBM PC.jpg \
    images/Computers/IBM System360.jpg \
    images/Computers/Macintosh 128k.jpg \
    images/Computers/MADDIDA.JPG \
    images/Computers/Manchester SSEM (baby).jpg \
    images/Computers/Pascaline.jpg \
    images/Computers/Pilot ACE.jpg \
    images/Computers/Sinclair ZX81.jpg \
    images/Computers/Strela Computer.jpg \
    images/Computers/TRADIC.jpg \
    images/Computers/Whirlwind I.jpg \
    images/Computers/Z3.jpg \
    images/Scientists/Ada Lovelace.jpg \
    images/Scientists/Adele Goldberg.jpg \
    images/Scientists/Alan Kay.jpg \
    images/Scientists/Alan Turing.jpg \
    images/Scientists/Anita Borg.jpg \
    images/Scientists/Barbara Liskov.jpg \
    images/Scientists/Bill Gates.jpeg \
    images/Scientists/Bjarne Stroustrup.jpg \
    images/Scientists/Brian Kernighan.jpg \
    images/Scientists/Charles Babbage.jpg \
    images/Scientists/Claude Shannon.jpg \
    images/Scientists/Dennis Ritchie.jpg \
    images/Scientists/Douglas Crockford.jpg \
    images/Scientists/Edsger W. Dijkstra.jpg \
    images/Scientists/Frances Allen.jpg \
    images/Scientists/George Boole.jpg \
    images/Scientists/Grace Hopper.jpg \
    images/Scientists/Guido van Rossum.jpg \
    images/Scientists/James Gosling.jpg \
    images/Scientists/Jean Bartik.jpg \
    images/Scientists/Jean E. Sammet.jpg \
    images/Scientists/John Backus.jpg \
    images/Scientists/John Vincent Atanasoff.jpg \
    images/Scientists/John Von Neumann.jpg \
    images/Scientists/Ken Thompson.jpg \
    images/Scientists/Larry Page.jpg \
    images/Scientists/Leslie Lamport.jpg \
    images/Scientists/Linus Torvalds.jpg \
    images/Scientists/Lois Haibt.jpg \
    images/Scientists/Lynn Conway.jpg \
    images/Scientists/Margaret Hamilton.jpg \
    images/Scientists/Marissa Mayer.jpg \
    images/Scientists/Michael Widenius.jpg \
    images/Scientists/Niklaus Wirth.jpg \
    images/Scientists/Per Brinch Hansen.jpg \
    images/Scientists/Radia Perlman.jpg \
    images/Scientists/Richard Stallman.jpeg \
    images/Scientists/Sergey Brin.jpg \
    images/Scientists/Shafi Goldwasser.jpg \
    images/Scientists/Sophie Wilson.jpg \
    images/Scientists/Tim Berners.jpg \
    images/Computers/Colossus.png \
    images/Computers/EDVAC.png \
    images/Scientists/John McCarthy.png

FORMS += \
    mainwindow.ui \
    addscientistdialog.ui \
    addcomputerdialog.ui \
    addlinkdialog.ui \
    deleteconfirmationdialog.ui \
    moreinfo.ui
    deleteconfirmationdialog.ui
