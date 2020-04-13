#ifndef VIDEOSLIDEMAKER_H
#define VIDEOSLIDEMAKER_H

#include "videoslidemakeroptions.h"

class VideoSlideMaker
{
public:
    VideoSlideMaker(VideoSlideMakerOptions vsm_options);

private:
    void parse_files(std::string directory);

};

#endif // VIDEOSLIDEMAKER_H
