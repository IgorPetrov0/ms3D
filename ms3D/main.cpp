#include <QApplication>
#include "mainwindow.h"
#include "editorcore.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    editorCore editor;
    w.setEditorPointer(&editor);
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
