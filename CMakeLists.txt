PROJECT(MyTest)
cmake_minimum_required(VERSION 3.13)
 set(MySources
         "src/main.cpp" "src/Observer.h" "src/Subject.h"
         "src/MainWindow.h" "src/MainWindow.cpp"  "src/StepButton.h" "src/StepButton.cpp"
         "src/Drum.h" "src/Drum.cpp" "src/DrumWidget.h" "src/DrumWidget.cpp"  "src/Timeline.h" "src/Timeline.cpp"
         "src/DrumKit.cpp" "src/DrumKit.h" "src/DrumKitWidget.h" "src/DrumKitWidget.cpp"
         "src/Metronome.h" "src/Metronome.cpp" "src/MetronomeWidget.h" "src/MetronomeWidget.cpp"
         "src/MyDial.h" "src/MyDial.cpp"
         "src/Player.cpp" "src/Player.h" "src/PlayerWidget.cpp" "src/PlayerWidget.h"
        "src/DisplayWidget.h" "src/DisplayWidget.cpp")

 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 set(CMAKE_AUTOMOC ON)
 set(CMAKE_AUTOUIC ON)

 find_package(Qt5Widgets CONFIG REQUIRED)

 find_package(Qt5Multimedia REQUIRED)

 ADD_EXECUTABLE(MyTest ${MySources})
 target_link_libraries(MyTest Qt5::Widgets)
 target_link_libraries(MyTest Qt5::Multimedia)
