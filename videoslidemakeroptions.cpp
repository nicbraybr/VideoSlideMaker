#include "videoslidemakeroptions.h"
#include <iostream>

VideoSlideMakerOptions::VideoSlideMakerOptions(int argc, char *argv[])
{
    boost::program_options::options_description desc{"Options"};
    desc.add_options()
            ("help,h", "Help screen")
            ("directory,d", boost::program_options::value<std::string>(), "The Directory")
            ("height", boost::program_options::value<int>(), "The Height in pixels")
            ("width", boost::program_options::value<int>(), "The Width in pixels");

    boost::program_options::variables_map vm;
    boost::program_options::store(parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    if (vm.count("help")){
        std::cout << desc << '\n';}
    else if (vm.count("directory")){
        directory = vm["directory"].as<std::string>();
    }
    else if (vm.count("height")){
        height = vm["height"].as<int>();
    }
    else if (vm.count("width")){
        width = vm["width"].as<int>();
    }
}
