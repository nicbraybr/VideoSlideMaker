#include "videoslidemakeroptions.h"
#include <iostream>

using namespace boost::program_options;

VideoSlideMakerOptions::VideoSlideMakerOptions(int argc, char *argv[])
{
    options_description desc{"Options"};
    desc.add_options()
            ("help,h", "Help screen")
            ("directory,d", value<std::string>(), "The Directory");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help")){
        std::cout << desc << '\n';}
    else if (vm.count("directory")){
        directory = vm["directory"].as<std::string>();
    }
}
