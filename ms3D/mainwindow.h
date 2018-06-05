#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "defines.h"
#include "parsers/parserobj.h"
#include "enginecore.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setCorePointer(engineCore *corePointer);
    ~MainWindow();

protected:
    engineCore *corePointer;


protected slots:
    void addNewModel(bool a);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
