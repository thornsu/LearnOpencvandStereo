cmake_minimum_required(VERSION 2.8.3)
project(LearnStereo)


set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( rgbstereo ./src/rgbstereo.cpp)

target_link_libraries( rgbstereo ${OpenCV_LIBS}
)










