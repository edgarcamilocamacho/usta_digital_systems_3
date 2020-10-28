#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    char myfifo[] = "/tmp/myfifo";
//    mkfifo(myfifo, 0666);
//    fd = open(myfifo, O_RDONLY);

    counter = 0;
    timer1 = new QTimer();
    connect(timer1, &QTimer::timeout, this, &MainWindow::timer1_tick);
    timer1->start(500);

    pipeThread = new PipeThread();
    connect(pipeThread, &PipeThread::text_received, this, &MainWindow::input_text);
    connect(pipeThread, &PipeThread::log, this, &MainWindow::input_log);
    pipeThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timer1_tick()
{
    counter++;
    ui->label->setText(QString::number(counter));

//    char text[80];
//    read(fd, text, 80);
//    ui->listInput->addItem( QString(text) );

}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->progressBar->setValue(position);
}

void MainWindow::on_pushButton_clicked()
{
    ui->listInput->addItem( "Hola" );
}

void MainWindow::input_text(QString text){
    ui->listInput->addItem(text);
}

void MainWindow::input_log(QString text){
    ui->listLog->addItem(text);
}
