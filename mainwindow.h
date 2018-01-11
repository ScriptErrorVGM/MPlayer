#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>

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
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();


private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QProgressBar* bar;
    QSlider* slider;
    QSlider* volume;

};

#endif // MAINWINDOW_H
