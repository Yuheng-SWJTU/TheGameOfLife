# 🎇The Game of Life

🔗<b>Link: https://github.com/Bilgin-L/TheGameOfLife </b> (Private Now)

🕸<b> Language: C </b>

🎈<b> Platform: Windows </b>

🎑<b> Dependencies: SDL, SDL_image, SDL_ttf, CUnit</b>

## Project Context

This is a project implements Conway's Game of Life with a extremely pretty good window using SDL and has interactions with users.

## Installation

Before you start the program, you should follow the instructions below to configure environment.


### 🎁Install SDL and extensions

In the ThaGameOfLife.zip file, a SDL2 and extensions are contained. But also, there are external links for you to download the SDL libraries.

SDL2: https://www.libsdl.org/download-2.0.php

SDL_image: https://www.libsdl.org/projects/SDL_image/

SDL_ttf: https://www.libsdl.org/projects/docs/SDL_ttf/SDL_ttf.html

### 🎄Configure Environment

In the following, a mean of configuring SDL in windows will be given.

After downloading the libraries, you should copy all folders in the SDL2 to your 'mingw' folder, and choose combine all files.

## Instructions

### 🚀Start the program

```
./play [FILE] [MODE] [STEPS]
```

[ FILE ] : You can choose init_state.txt or history.txt file, in the history.txt file it will pick up where you left off.

[ MODE ] : If you choose CUSTOM mode, you can edit the board using mouse by yourself, otherwise, it will generate by the initial or history file.

[ STEPS ] : You can specify the generation step, when reach the step you specified, the window will pause. If you ignore this argument, it will continue to evolve.

### 🎮Operations

🖱 Mouse operations

1. Define lives by mouse left;
2. delete lives by mouse right.

⌨Keyboard operations

1. Use '1' to operate 1 step;
2. Use UP to speed it up;
3. Use DOWN to speed it down;
4. Use LEFT to clear all the lives;
5. Use RIGHT to generate lives randomly.

🕹Button operations

There are some buttons in the surface, you can click all buttons by mouse to implement all functions we mentioned in the Keyboard operations part.

## Developer

📧 E-mail: sc20yl2@leeds.ac.uk | i@bilgin.top

📞 We-Chat: Bilgin_L

