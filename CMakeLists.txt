cmake_minimum_required(VERSION 3.19)
project(TheGameOfLife C)

set(CMAKE_C_STANDARD 99)

# 声明一个变量为SDL2_DIR包含所有的SDL2头文件
set(SDL2_DIR
        SDL2/SDL2-2.0.22/x86_64-w64-mingw32/include/SDL2
        SDL2/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2
        SDL2/SDL2_ttf-2.0.18/x86_64-w64-mingw32/include/SDL2
        )

# 声明一个变量为SDL2_LINK包含所有库的路径
set(SDL2_LINK
        SDL2/SDL2-2.0.22/x86_64-w64-mingw32/bin
        SDL2/SDL2_image-2.0.5/x86_64-w64-mingw32/bin
        SDL2/SDL2_ttf-2.0.18/x86_64-w64-mingw32/bin
        )

# 关联所有的头文件
include_directories(${SDL2_DIR})

# 关联所有的库
link_directories(${SDL2_LINK})

add_executable(TheGameOfLife main.c window.c game.c utilities.c utilities.h)

# 配置关联库的名称
target_link_libraries(TheGameOfLife mingw32 SDL2main SDL2 SDL2_image SDL2_ttf)