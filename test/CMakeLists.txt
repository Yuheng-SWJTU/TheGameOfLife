cmake_minimum_required(VERSION 3.19)
project(test C)

set(CMAKE_C_STANDARD 99)

# Declare a variable SDL2 DIR to contain all SDL2 header files
set(SDL2_DIR
        SDL2/SDL2-2.0.22/x86_64-w64-mingw32/include/SDL2
        SDL2/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2
        SDL2/SDL2_ttf-2.0.18/x86_64-w64-mingw32/include/SDL2
        )

# Declare a variable as SDL2 LINK containing the path to all libraries
set(SDL2_LINK
        SDL2/SDL2-2.0.22/x86_64-w64-mingw32/bin
        SDL2/SDL2_image-2.0.5/x86_64-w64-mingw32/bin
        SDL2/SDL2_ttf-2.0.18/x86_64-w64-mingw32/bin
        )

# Associate all header files
include_directories(${SDL2_DIR})

# Associate all libraries
link_directories(${SDL2_LINK})

add_executable(test test_unit.c ../game.c ../game.h ../utilities.c ../utilities.h ../window.c ../window.h)

# Configure the name of the associated library
target_link_libraries(test CUnit SDL2 SDL2_image SDL2_ttf)