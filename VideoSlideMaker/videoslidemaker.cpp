#include "videoslidemaker.h"
#include <QApplication>
#include <QPicture>
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
}

void VideoSlideMaker::parse_files(std::string directory){

    for(auto& file : boost::make_iterator_range(boost::filesystem::directory_iterator(directory), {})){
        files.push_back(file.path().string());
    }
    add_videos();
}


void VideoSlideMaker::add_videos(){
    auto player = new QMediaPlayer;

    auto playlist = new QMediaPlaylist(player);

    for (const auto& file : files){
        playlist->addMedia(QUrl(QString::fromStdString(file)));
    }
    auto videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);

    videoWidget->show();
    playlist->setCurrentIndex(1);
    player->play();
}
