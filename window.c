#include "window.h"

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

void plot_game(window_t *game, SDL_Renderer *renderer) {
    // Plot the game
    for (int i = 0; i < game->height_num; i ++) {
        for (int j = 0; j < game->width_num; j ++) {
            if (game->array[i][j] == '1') {
                SDL_Rect rec;
                rec.w = game->point_size;
                rec.h = game->point_size;
                rec.y = i * game->point_size;
                rec.x = j * game->point_size;
                SDL_RenderFillRect(renderer, &rec);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 200);
                SDL_RenderDrawRect(renderer, &rec);
                SDL_SetRenderDrawColor(renderer, game->R_cell, game->G_cell, game->B_cell, 1);
            }
        }
    }
}

int setting_colors(window_t * game){
    if (strcmp(game->background_color, "white\n") == 0) {
        game->R_bac = 255;
        game->G_bac = 255;
        game->B_bac = 255;
    } else if (strcmp(game->background_color, "black\n") == 0) {
        game->R_bac = 0;
        game->G_bac = 0;
        game->B_bac = 0;
    } else if (strcmp(game->background_color, "red\n") == 0) {
        game->R_bac = 188;
        game->G_bac = 0;
        game->B_bac = 45;
    } else if (strcmp(game->background_color, "green\n") == 0) {
        game->R_bac = 131;
        game->G_bac = 138;
        game->B_bac = 45;
    } else if (strcmp(game->background_color, "blue\n") == 0) {
        game->R_bac = 145;
        game->G_bac = 180;
        game->B_bac = 147;
    } else if (strcmp(game->background_color, "yellow\n") == 0) {
        game->R_bac = 221;
        game->G_bac = 210;
        game->B_bac = 59;
    } else{
        printf("\n[!] Warning: We cannot find the color you set in background."
               "\n[!] We have set the default background color for you!\n");
        game->R_bac = 196;
        game->G_bac = 183;
        game->B_bac = 215;
    }

    if (strcmp(game->cell_color, "white\n") == 0) {
        game->R_cell = 255;
        game->G_cell = 255;
        game->B_cell = 255;
    } else if (strcmp(game->cell_color, "black\n") == 0) {
        game->R_cell = 0;
        game->G_cell = 0;
        game->B_cell = 0;
    } else if (strcmp(game->cell_color, "red\n") == 0) {
        game->R_cell = 188;
        game->G_cell = 0;
        game->B_cell = 45;
    } else if (strcmp(game->cell_color, "green\n") == 0) {
        game->R_cell = 131;
        game->G_cell = 138;
        game->B_cell = 45;
    } else if (strcmp(game->cell_color, "blue\n") == 0) {
        game->R_cell = 145;
        game->G_cell = 180;
        game->B_cell = 147;
    } else if (strcmp(game->cell_color, "yellow\n") == 0) {
        game->R_cell = 221;
        game->G_cell = 210;
        game->B_cell = 59;
    } else{
        printf("\n[!] Warning: We cannot find the color you set in cell."
               "\n[!] We have set the default cell color for you!\n");
        game->R_cell = 112;
        game->G_cell = 86;
        game->B_cell = 151;
    }
    return 0;
}

int PauseButton(Uint32 ButtonMode, SDL_Renderer *ButtonRender, window_t *game){
    SDL_Surface *ButtonSur = NULL;
    SDL_Texture *ButtonText = NULL;
    SDL_Rect ButtRect;
    ButtRect.x = game->width / 2 - 20;
    ButtRect.y = game->height + 10;
    ButtRect.w = 40;
    ButtRect.h = 40;
    const char* buttonPausePlayFile[] = {"images/button_pause_0.png"};
    const char * OpenButton = buttonPausePlayFile[ButtonMode];
    ButtonSur = IMG_Load(OpenButton);
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

int isPauseOnButton(Uint32 x, Uint32 y, window_t *game){
    if (x >= game->width / 2 - 20 && x <= game->width / 2 + 20)
        if (y >= game->height + 10 && y <= game->height + 50) return 1;
    return 0;
}

int speedDownButton(SDL_Renderer *ButtonRender, window_t *game){
    SDL_Surface *ButtonSur = NULL;
    SDL_Texture *ButtonText = NULL;
    SDL_Rect ButtRect;
    ButtRect.x = game->width / 2 - 70;
    ButtRect.y = game->height + 15;
    ButtRect.w = 30;
    ButtRect.h = 30;
    const char* buttonPausePlayFile[] = {"images/button_speed_down.png"};
    const char * OpenButton = buttonPausePlayFile[0];
    ButtonSur = IMG_Load(OpenButton);
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

int isSpeedDownOnButton(Uint32 x, Uint32 y, window_t *game){
    if (x >= game->width / 2 - 70 && x <= game->width / 2 - 40)
        if (y >= game->height + 15 && y <= game->height + 45) return 1;
    return 0;
}

int speedUpButton(SDL_Renderer *ButtonRender, window_t *game){
    SDL_Surface *ButtonSur = NULL;
    SDL_Texture *ButtonText = NULL;
    SDL_Rect ButtRect;
    ButtRect.x = game->width / 2 + 40;
    ButtRect.y = game->height + 15;
    ButtRect.w = 30;
    ButtRect.h = 30;
    const char* buttonPausePlayFile[] = {"images/button_speed_up.png"};
    const char * OpenButton = buttonPausePlayFile[0];
    ButtonSur = IMG_Load(OpenButton);
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

int isSpeedUpOnButton(Uint32 x, Uint32 y, window_t *game){
    if (x >= game->width / 2 + 40 && x <= game->width / 2 + 70)
        if (y >= game->height + 15 && y <= game->height + 45) return 1;
    return 0;
}

int clearButton(SDL_Renderer *ButtonRender, window_t *game){
    SDL_Surface *ButtonSur = NULL;
    SDL_Texture *ButtonText = NULL;
    SDL_Rect ButtRect;
    ButtRect.x = 10;
    ButtRect.y = game->height + 15;
    ButtRect.w = 30;
    ButtRect.h = 30;
    const char* buttonPausePlayFile[] = {"images/button_clear.png"};
    const char * OpenButton = buttonPausePlayFile[0];
    ButtonSur = IMG_Load(OpenButton);
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

int isClearOnButton(Uint32 x, Uint32 y, window_t *game){
    if (x >= 10 && x <= 40)
        if (y >= game->height + 15 && y <= game->height + 45) return 1;
    return 0;
}

int randomButton(SDL_Renderer *ButtonRender, window_t *game){
    SDL_Surface *ButtonSur = NULL;
    SDL_Texture *ButtonText = NULL;
    SDL_Rect ButtRect;
    ButtRect.x = game->width - 40;
    ButtRect.y = game->height + 15;
    ButtRect.w = 30;
    ButtRect.h = 30;
    const char* buttonPausePlayFile[] = {"images/button_random.png"};
    const char * OpenButton = buttonPausePlayFile[0];
    ButtonSur = IMG_Load(OpenButton);
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

int isRandomOnButton(Uint32 x, Uint32 y, window_t *game){
    if (x >= game->width - 40 && x <= game->width - 10)
        if (y >= game->height + 15 && y <= game->height + 45) return 1;
    return 0;
}