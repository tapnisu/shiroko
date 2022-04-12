cmake_minimum_required(VERSION 3.8)
project("shiroko")

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(shiroko "src/shiroko.cpp" "src/shiroko.h")

target_link_libraries(shiroko ${OpenCV_LIBS})
