#include "window.h"
#include "game.h"

#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


int main(int argc, char *argv[]){
    int point_size = 4;
    char settings[100] = "settings.txt";
    char map[100] = "init_state.txt";
    window_t * game = init_game(settings, map);
//    printf("height: %d\n", window->height);
//    printf("width: %d\n", window->width);
//    printf("delay: %d\n", window->delay);
//    printf("initial state:\n");
//    for (int i = 0; i < window->height; i ++) {
//        printf("%s\n", window->array[i]);
//    }
    detect_neighbours(game);
//    printf("after detect neighbours:\n");
//    for (int i = 0; i < window->height; i ++) {
//        printf("%s\n", window->array[i]);
//    }
    int quit = 0;
    int pause = 0;
    int mouseLeft = 0;
    int mouseRight = 0;
    // Initialize SDL2
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, game->width * point_size, game->height * point_size, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // SDL event
    SDL_Event event;
    // Main loop
    while(!quit){
        // Event handling
        while(SDL_PollEvent(&event)){
            // Quit
            if(event.type == SDL_QUIT){
                quit = 1;
            }
            // Detect the event of keyboard
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = 1;
                        break;
                    case SDLK_SPACE:
                        pause = !pause;
                        break;
                    case SDLK_UP:
                        game->delay += 100;
                        if (game->delay > 800){
                            game->delay = 800;
                        }
                        break;
                    case SDLK_DOWN:
                        game->delay -= 100;
                        if (game->delay < 1){
                            game->delay = 1;
                        }
                        break;
                }
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    mouseLeft = 1;
                }
                if (event.button.button == SDL_BUTTON_RIGHT){
                    mouseRight = 1;
                }
            }
            if (event.type == SDL_MOUSEBUTTONUP){
                if (event.button.button == SDL_BUTTON_LEFT){
                    mouseLeft = 0;
                }
                if (event.button.button == SDL_BUTTON_RIGHT){
                    mouseRight = 0;
                }
            }
            if (event.type == SDL_MOUSEMOTION){
                int new_x = event.button.x / point_size;
                int new_y = event.button.y / point_size;
                if (new_x < game->width && new_y < game->height){
                    if (mouseLeft == 1){
                        game->array[new_x][new_y] = '1';
                    } else if (mouseRight == 1){
                        game->array[new_x][new_y] = '0';
                    }
                }
            }
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
        if (!pause){
            detect_neighbours(game);
        }
        plot_game(game, renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        SDL_RenderPresent(renderer);
        if (pause){
            SDL_Delay(1);
        } else{
            SDL_Delay(game->delay);
        }
    }

    end_game(game);
    SDL_DestroyWindow(windows);
    SDL_Quit();
}