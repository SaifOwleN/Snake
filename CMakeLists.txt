cmake_minimum_required(VERSION 3.10)

project(Snake)

# Add all your source files
set(SOURCES
    ./src/Game.cpp
    ./src/app.cpp
)

# Add your header file directory
include_directories(${CMAKE_SOURCE_DIR})


# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ncurses)
