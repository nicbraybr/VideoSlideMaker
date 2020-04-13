#include "videoslidemaker.h"
#include <QApplication>
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
    std::vector<std::string> file_names;

    for(auto& file : boost::make_iterator_range(boost::filesystem::directory_iterator(directory), {})){
        file_names.push_back(file.path().string());
    }
}
