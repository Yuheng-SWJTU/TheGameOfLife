#include "window.h"
#include "game.h"

#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


int main(int argc, char *argv[]){
    int step = 0;
    int count = 0;
    int quit = 0;
    int pause = 0;
    int mouseLeft = 0;
    int mouseRight = 0;
    int mode = 0;

    if (argc < 3 || argc > 4){
        printf("\n[!] Error! Expected use: ./play [FILENAME] [MODE] [STEPS]\n");
        exit(-1);
    } else {
        if ((strcmp(argv[1], "init_state.txt") != 0) && (strcmp(argv[1], "history.txt") != 0)){
            printf("\n[!] Error! Expected use: 'init_state.txt' or 'history.txt'\n");
            exit(-2);
        }
        if ((strcmp(argv[2], "CUSTOM") == 0)){
            mode = 1;
        }
        if (argc == 3){
            step = -1;
        }
        if (argc == 4){
            if (atoi(argv[2]) < 1){
                printf("\n[!] Error! Expected use: [STEPS] > 0\n");
                exit(-3);
            } else {
                step = atoi(argv[2]);
            }
        }
    }

    printf("\n[+] Initializing the game...\n");

    window_t * game = init_game(argv[1]);

    // Initialize SDL2
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("\n[!] SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, game->width, game->height + 60, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    if (mode == 1){
        clear_screen(game);
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
                        game->delay -= 50;
                        if (game->delay < 10){
                            game->delay = 10;
                        }
                        break;
                    case SDLK_DOWN:
                        game->delay += 50;
                        if (game->delay > 600){
                            game->delay = 600;
                        }
                        break;
                    case SDLK_LEFT:
                        clear_screen(game);
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
                int new_x = event.button.x / game->point_size;
                int new_y = event.button.y / game->point_size;
                if (new_x < game->width_num && new_y < game->height_num){
                    if (mouseLeft == 1){
                        game->array[new_y][new_x] = '1';
                    } else if (mouseRight == 1){
                        game->array[new_y][new_x] = '0';
                    }
                }
            }
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, game->R_cell, game->G_cell, game->B_cell, 1);
        if (pause){
            if (step == -1){
                detect_neighbours(game);
                SDL_Delay(game->delay);
            }else{
                if (count < step){
                    detect_neighbours(game);
                    SDL_Delay(game->delay);
                    count++;
                }
                if (count == step + 1){
                    pause = 0;
                    count ++;
                }
                if (count >= step && pause == 1){
                    detect_neighbours(game);
                    SDL_Delay(game->delay);
                    count++;
                }
            }
        }
        plot_game(game, renderer);
        SDL_SetRenderDrawColor(renderer, game->R_bac, game->G_bac, game->B_bac, 1);
        SDL_RenderPresent(renderer);
//        SDL_Delay(game->delay);
    }

    save_game(game);
    end_game(game);
    SDL_DestroyWindow(windows);
    SDL_Quit();
    return EXIT_SUCCESS;
}