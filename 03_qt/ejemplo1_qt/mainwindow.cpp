#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::cout << "Creando la ventana" << std::endl;
}

MainWindow::~MainWindow()
{
    std::cout << "Destruyendo la ventana" << std::endl;
    delete ui;
}

void MainWindow::on_btn1_clicked()
{
    ui->lbl1->setText("Hola!!!");
}
