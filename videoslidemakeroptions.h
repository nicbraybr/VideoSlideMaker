#ifndef VIDEOSLIDEMAKEROPTIONS_H
#define VIDEOSLIDEMAKEROPTIONS_H

#include <QApplication>
#include <boost/program_options.hpp>
#include <string>

class VideoSlideMakerOptions
{
public:
    VideoSlideMakerOptions(int argc, char *argv[]);

    std::string directory;
    int height;
    int width;
};

#endif // VIDEOSLIDEMAKEROPTIONS_H
