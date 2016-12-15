#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setWindowIcon(QIcon(".\\images\\favicon.png"));
    MainWindow mainwin;
    mainwin.showMaximized();
    return a.exec();
}
