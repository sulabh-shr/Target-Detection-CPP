cmake_minimum_required(VERSION 2.8)
project( Target-Detection-CPP )
find_package( OpenCV REQUIRED )
include_directories(src)

file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

add_executable( Target-Detection-Cpp ${SOURCES} )
target_link_libraries( Target-Detection-Cpp ${OpenCV_LIBS})