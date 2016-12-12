#include <QApplication>

#include "userinterface.h"
#include "MainWindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //userInterface ui;
    //ui.run();
    MainWindow mainwin;
    mainwin.show();
    return a.exec();
}
