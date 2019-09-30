project(UnitTest)
cmake_minimum_required(VERSION 3.13)

enable_testing()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)

set(TestSources UnitTest.cpp)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Test REQUIRED)

add_executable(UnitTest ${TestSources})

link_libraries(UnitTest DrumMachineTest)
target_link_libraries(UnitTest Qt5::Widgets)
target_link_libraries(UnitTest Qt5::Multimedia)
target_link_libraries(UnitTest Qt5::Test)
