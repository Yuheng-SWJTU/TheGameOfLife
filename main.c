#include "window.h"
#include "game.h"

#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


int main(int argc, char *argv[]){
    char settings[100] = "settings.txt";
    char map[100] = "init_state.txt";
    window_t * window = init_game(settings, map);
    printf("height: %d\n", window->height);
    printf("width: %d\n", window->width);
    printf("delay: %d\n", window->delay);
    printf("initial state:\n");
    for (int i = 0; i < window->height; i ++) {
        printf("%s\n", window->array[i]);
    }
    detect_neighbours(window);
    printf("after detect neighbours:\n");
    for (int i = 0; i < window->height; i ++) {
        printf("%s\n", window->array[i]);
    }
}