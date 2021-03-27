cmake_minimum_required(VERSION 3.17)
project(LBPSequential)

set(CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(LBPSequential main.cpp LocalBinaryPattern.h LocalBinaryPattern.cpp)
target_link_libraries(LBPSequential ${OpenCV_LIBS})