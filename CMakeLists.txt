cmake_minimum_required(VERSION 3.8.0)

project(myapp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
add_executable(myapp main.cxx file.cxx)
target_link_libraries(myapp Qt5::Core Qt5::WinMain)
