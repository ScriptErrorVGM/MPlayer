#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    slider = new QSlider(this);
    bar = new QProgressBar(this);
    volume = new QSlider(this);

    slider->setOrientation(Qt::Horizontal);
    volume->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);
    ui->statusBar->addPermanentWidget(volume);
    ui->statusBar->addPermanentWidget(bar);

    connect(player,&QMediaPlayer::durationChanged,volume,&QSlider::setValue);
    connect(volume,&QSlider::sliderMoved,player,&QMediaPlayer::setVolume);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","(*.mp3)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();

}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusBar->showMessage("Playing");
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusBar->showMessage("Paused");
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusBar->showMessage("Stopped");
}

