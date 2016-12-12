#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addscientistdialog.h"
#include "addcomputerdialog.h"
#include "editscientistdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_addScientist_clicked();

private:
    Ui::MainWindow *ui;
    AddScientistDialog addSci;

};

#endif // MAINWINDOW_H
