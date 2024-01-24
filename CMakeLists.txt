cmake_minimum_required(VERSION 3.10)
project(GraphEngine)

set(CMAKE_CXX_STANDARD 14)

# Add your source files
set(SOURCE_FILES
    main.cpp
    src/Geometries.hpp
    src/Geometries.cpp
    src/PixelBuffer.hpp
    src/PixelBuffer.cpp
)

# Add executable target
add_executable(GraphEngine ${SOURCE_FILES})

# If you are using ncurses, link against it
find_package(Curses REQUIRED)
target_link_libraries(GraphEngine ${CURSES_LIBRARIES})
