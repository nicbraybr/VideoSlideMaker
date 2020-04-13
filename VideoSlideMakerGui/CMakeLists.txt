cmake_minimum_required(VERSION 2.8.12)

PROJECT(VideoSlideMakerGui)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets REQUIRED)

# The Qt5Widgets_INCLUDES also includes the include directories for
# dependencies QtCore and QtGui
include_directories(${Qt5Widgets_INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} )

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

SET(VideoSlideMakerGui_SOURCES
    videoslidemakerpresenter.cpp
    videoslidemakerwindow.cpp)

SET(VideoSlideMakerGui_HEADERS
    videoslidemakerpresenter.h
    videoslidemakerwindow.h)

SET(VideoSlideMakerGui_FORMS
    videoslidemakerwindow.ui)

QT5_WRAP_CPP(VideoSlideMakerGui_HEADERS_MOC ${VideoSlideMakerGui_HEADERS})
QT5_WRAP_UI(VideoSlideMakerGui_FORMS_HEADERS ${VideoSlideMakerGui_FORMS})

ADD_EXECUTABLE(VideoSlideMakerGui
    ${VideoSlideMakerGui_SOURCES}
    ${VideoSlideMakerGui_HEADERS_MOC}
    ${VideoSlideMakerGui_FORMS_HEADERS}
    )

# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
TARGET_LINK_LIBRARIES(VideoSlideMakerGui ${Qt5Widgets_LIBRARIES})
