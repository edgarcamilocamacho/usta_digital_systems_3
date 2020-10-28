#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "pipethread.h"

//#include <stdio.h>
//#include <string.h>
//#include <fcntl.h>
//#include <sys/stat.h>
//#include <unistd.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_horizontalSlider_sliderMoved(int position);
    void timer1_tick();
    void on_pushButton_clicked();
    void input_text(QString text);
    void input_log(QString text);

private:
    Ui::MainWindow *ui;
    QTimer *timer1;
    PipeThread *pipeThread;
    int counter;
    int fd;
};

#endif // MAINWINDOW_H
