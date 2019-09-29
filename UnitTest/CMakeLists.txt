cmake_minimum_required(VERSION 3.14)
project(UnitTest)

enable_testing()
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Test REQUIRED)

add_executable(UnitTest UnitTest.cpp )

target_link_libraries(UnitTest Qt5::Widgets)
target_link_libraries(UnitTest Qt5::Multimedia)
target_link_libraries(UnitTest Qt5::Test)
