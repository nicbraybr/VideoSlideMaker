#ifndef VIDEOSLIDEMAKERWINDOW_H
#define VIDEOSLIDEMAKERWINDOW_H

#include <QMainWindow>

namespace Ui {
class VideoSlideMakerWindow;
}

class VideoSlideMakerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoSlideMakerWindow(QWidget *parent = 0);
    ~VideoSlideMakerWindow();

private:
    Ui::VideoSlideMakerWindow *ui;
};

#endif // VIDEOSLIDEMAKERWINDOW_H
