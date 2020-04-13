#include "videoslidemaker.h"
#include "videoslidemakeroptions.h"
#include <QApplication>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>


#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    VideoSlideMakerOptions vsm_options(argc, argv);

    if (!boost::filesystem::is_directory(vsm_options.directory))
    {
        std::cout << vsm_options.directory << " is not a valid directory" << std::endl;
    }

    return a.exec();
}
