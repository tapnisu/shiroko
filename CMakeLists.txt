cmake_minimum_required(VERSION 3.8)
project("shiroko")

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(shiroko-image "src/shiroko-image.cpp" "src/asciiFunctions.hpp" "src/shiroko.h")
add_executable(shiroko-video "src/shiroko-video.cpp" "src/asciiFunctions.hpp" "src/shiroko.h")

target_link_libraries(shiroko-image ${OpenCV_LIBS})
target_link_libraries(shiroko-video ${OpenCV_LIBS})
