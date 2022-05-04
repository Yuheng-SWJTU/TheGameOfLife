#include "window.h"
#include <SDL.h>
#include <stdio.h>

void init_window(){
    // Window initialization
    SDL_Window  *window = NULL;
    // Window surface
    SDL_Surface *surface = NULL;
    // Initialize SDL2
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

}