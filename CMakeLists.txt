cmake_minimum_required(VERSION 3.17)
project(LBPSequential)
include_directories(/usr/local/Cellar/opencv/4.5.1_3/lib)


set(CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(LBPSequential main.cpp LocalBinaryPattern.h LocalBinaryPattern.cpp writeCsv.cpp writeCsv.h )
add_executable(timeTests runTests.cpp execTimeTests.cpp execTimeTests.h LocalBinaryPattern.h LocalBinaryPattern.cpp writeCsv.cpp writeCsv.h)
target_link_libraries(LBPSequential ${OpenCV_LIBS})
target_link_libraries(timeTests ${OpenCV_LIBS})