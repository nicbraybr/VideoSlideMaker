#include "videoslidemaker.h"
#include <QApplication>
#include <QPicture>
#include <QMediaPlaylist>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <iostream>
#include <vector>
#include <string>

VideoSlideMaker::VideoSlideMaker(VideoSlideMakerOptions vsm_options)
{
    parse_files(vsm_options.directory);
    add_videos();
}

void VideoSlideMaker::parse_files(std::string directory){

    for(auto& file : boost::make_iterator_range(boost::filesystem::directory_iterator(directory), {})){
        files.push_back(file.path().string());
    break;
    }
}


void VideoSlideMaker::add_videos(){
/*
    QString file_loc;
    for (const auto& file : files){
        file_loc = QString::fromStdString(file);
        //media->setMedia(QUrl::fromLocalFile(QString::fromStdString(file)));
    }
*/
    QMediaPlayer *media=new QMediaPlayer;
    QVideoWidget *video=new QVideoWidget; //new QGLWidget()
    media->setVideoOutput(video);
    media->setMedia(QUrl::fromLocalFile("/home/nicole/Dev/VideoSlideProducer/Videos/zzzz.mov"));
    media->setPosition(3000000);
    media->play();
    QPushButton *pb=new QPushButton(video);
    pb->setText(QString("BOB"));
    //pb->setStyleSheet(QString("background:transparent;"));
    video->show();



}
