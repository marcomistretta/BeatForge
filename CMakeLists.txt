project(DrumMachine)
cmake_minimum_required(VERSION 3.13)
set(MySources
        src/Observer.h src/Subject.h
        src/MainWindow.h src/MainWindow.cpp src/StepButton.h src/StepButton.cpp
        src/Drum.h src/Drum.cpp src/DrumWidget.h src/DrumWidget.cpp src/Timeline.h src/Timeline.cpp
        src/DrumKit.cpp src/DrumKit.h src/DrumKitWidget.h src/DrumKitWidget.cpp
        src/Metronome.h src/Metronome.cpp src/MetronomeWidget.h src/MetronomeWidget.cpp
        src/MyDial.h src/MyDial.cpp
        src/Player.cpp src/Player.h src/PlayerWidget.cpp src/PlayerWidget.h
        src/DisplayWidget.h src/DisplayWidget.cpp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(UnitTest)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Multimedia REQUIRED)


add_library(DrumMachineTest ${MySources})
add_executable(DrumMachine src/main.cpp ${MySources})

target_link_libraries(DrumMachine Qt5::Widgets)
target_link_libraries(DrumMachine Qt5::Multimedia)
