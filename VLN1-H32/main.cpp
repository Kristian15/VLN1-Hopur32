#include <QApplication>

#include "userinterface.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    userInterface ui;
    ui.run();
    mainwindow mainwin;
    mainwin.show();
    return a.exec();
}
