#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addModel,SIGNAL(toggled(bool)),this,SLOT(addNewModel(bool)));

}
/////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete ui;
}
//////////////////////////////////////////////////////////
void MainWindow::addNewModel(bool a){
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
    parserOBJ parser;
    if(parser.readFile(fileNames.at(1))){

    }



}
///////////////////////////////////////////////////////////////////////
void MainWindow::setCorePointer(engineCore *corePointer){
    this->corePointer=corePointer;
}
