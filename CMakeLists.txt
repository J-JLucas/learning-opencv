cmake_minimum_required(VERSION 3.10)
project(openCV)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Add your executable
add_executable(helloimg helloimg.cpp)
add_executable(hellovid hellovid.cpp)

# Link OpenCV libraries to your executable
target_link_libraries(helloimg ${OpenCV_LIBS})
target_link_libraries(hellovid ${OpenCV_LIBS})

# Enable generation of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

