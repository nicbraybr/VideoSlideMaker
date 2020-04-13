cmake_minimum_required(VERSION 2.8.12)

PROJECT(VideoSlideMaker)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets REQUIRED)

# Other finds
find_package(Boost COMPONENTS
    program_options
    filesystem
    REQUIRED)

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(${Qt5Widgets_INCLUDES} ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} )

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

SET(VideoSlideMaker_SOURCES
    videoslidemaker.cpp
    main.cpp
    videoslidemakeroptions.cpp)

SET(VideoSlideMaker_HEADERS
    videoslidemaker.h
    videoslidemakeroptions.h)


QT5_WRAP_CPP(VideoSlideMaker_HEADERS_MOC ${VideoSlideMaker_HEADERS})
QT5_WRAP_UI(VideoSlideMaker_FORMS_HEADERS ${VideoSlideMaker_FORMS})

ADD_EXECUTABLE(VideoSlideMaker
    ${VideoSlideMaker_SOURCES}
    ${VideoSlideMaker_HEADERS_MOC}
    ${VideoSlideMaker_FORMS_HEADERS}
    )

# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
TARGET_LINK_LIBRARIES(VideoSlideMaker ${Qt5Widgets_LIBRARIES} ${Boost_LIBRARIES})
