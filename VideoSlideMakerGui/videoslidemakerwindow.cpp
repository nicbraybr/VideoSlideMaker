#include "videoslidemakerwindow.h"
#include "ui_videoslidemakerwindow.h"

VideoSlideMakerWindow::VideoSlideMakerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VideoSlideMakerWindow)
{
    ui->setupUi(this);
}

VideoSlideMakerWindow::~VideoSlideMakerWindow()
{
    delete ui;
}
