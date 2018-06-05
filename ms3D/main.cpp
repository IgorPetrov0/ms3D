#include <QApplication>
#include "mainwindow.h"
#include "enginecore.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    engineCore core;
    MainWindow w;
    w.setCorePointer(&core);
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
