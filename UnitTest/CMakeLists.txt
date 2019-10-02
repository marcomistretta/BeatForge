project(UnitTest)
cmake_minimum_required(VERSION 3.13)

enable_testing()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(TestSources UnitTest.cpp)
set(Sources ../src/Observer.h ../src/Subject.h
        ../src/MainWindow.h ../src/MainWindow.cpp ../src/StepButton.h ../src/StepButton.cpp
        ../src/Drum.h ../src/Drum.cpp ../src/DrumWidget.h ../src/DrumWidget.cpp ../src/Timeline.h ../src/Timeline.cpp
        ../src/DrumKit.cpp ../src/DrumKit.h ../src/DrumKitWidget.h ../src/DrumKitWidget.cpp
        ../src/Metronome.h ../src/Metronome.cpp ../src/MetronomeWidget.h ../src/MetronomeWidget.cpp
        ../src/MyDial.h ../src/MyDial.cpp
        ../src/Player.cpp ../src/Player.h ../src/PlayerWidget.cpp ../src/PlayerWidget.h
        ../src/DisplayWidget.h ../src/DisplayWidget.cpp)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Test REQUIRED)

add_executable(UnitTest ${TestSources} ${Sources})

target_link_libraries(UnitTest Qt5::Widgets)
target_link_libraries(UnitTest Qt5::Multimedia)
target_link_libraries(UnitTest Qt5::Test)
