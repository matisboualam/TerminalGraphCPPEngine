cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME "GraphEngine")  # Set the variable PROJECT_NAME

project(${PROJECT_NAME})

# Use file(GLOB ...) to find all .cpp files in the src/ directory
file(GLOB SOURCE_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
