PROJECT(MyTest)
cmake_minimum_required(VERSION 3.14)
 set(MySources "main.cpp" "Observer.h" "Subject.h" "Metronome.h" "Metronome.cpp"
         "MainWindow.h" "MainWindow.cpp" "Drum.h" "Drum.cpp" "StepButton.h" "StepButton.cpp"
         "DrumWidget.cpp" "DrumWidget.h"  "DrumKit.cpp" "DrumKit.h" )
 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 set(CMAKE_AUTOMOC ON)
 set(CMAKE_AUTOUIC ON)

 find_package(Qt5Widgets CONFIG REQUIRED)

 find_package(Qt5Multimedia REQUIRED)

 ADD_EXECUTABLE(MyTest ${MySources})
 target_link_libraries(MyTest Qt5::Widgets)
 target_link_libraries(MyTest Qt5::Multimedia)
