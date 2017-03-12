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
            ui->plainTextEdit->appendPlainText("Serial number: "+serialDetector->getSerialPortInfo(comNames).serialNumber());
            ui->plainTextEdit->appendPlainText("Manufacturer: "+serialDetector->getSerialPortInfo(comNames).manufacturer());


        }

    }



}



