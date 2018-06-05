#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "defines.h"
#include "editorcore.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setEditorPointer(editorCore *corePointer);
    ~MainWindow();

protected:
    editorCore *editorPointer;


protected slots:
    void addNewModel();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
