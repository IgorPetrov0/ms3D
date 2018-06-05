#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addModel,SIGNAL(triggered(bool)),this,SLOT(addNewModel(bool)));
}
/////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete ui;
}
//////////////////////////////////////////////////////////
void MainWindow::addNewModel(){
    QFileDialog dialog(this);
    QStringList fileNames;

    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setDirectory(QApplication::applicationDirPath());
    dialog.setNameFilter(MODELS_FILE_FILTER);
    dialog.setLabelText(QFileDialog::LookIn,tr("Open 3D model"));
    dialog.setViewMode(QFileDialog::Detail);
    if(dialog.exec()){
        fileNames=dialog.selectedFiles();
    }
    int t=0;


}
