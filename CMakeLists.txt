cmake_minimum_required(VERSION 2.8)
project( Hough )
find_package( OpenCV REQUIRED )

set(EXECUTABLE_OUTPUT_PATH ../bin)
set (CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -g -std=c++11") 

set ( Project_SOURCES
    ../src/main.cpp
    ../src/Filter.cpp
    ../src/bilateralFilter.cpp
    ../src/blobFilter.cpp   
    ../src/houghFilter.cpp 
    )

add_executable( Hough ${Project_SOURCES} )
target_link_libraries( Hough ${OpenCV_LIBS} )
