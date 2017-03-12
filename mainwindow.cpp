#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serialDetector = new SerialDetector();

    connect(serialDetector,SIGNAL(onDetect(int,QSet<QString>)),this,SLOT(detected(int,QSet<QString>)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::detected(int status, QSet<QString> coms){


    if (status==0){

        foreach (QString comNames, coms) {

            ui->plainTextEdit->appendPlainText("Disconnected: "+comNames);

        }

    }else{

        foreach (QString comNames, coms) {

            ui->plainTextEdit->appendPlainText("Connected: "+comNames);

        }

    }



}



