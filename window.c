#include "window.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

/**
 * @param game a struct containing all the game's data
 * @param renderer the renderer to use
 * @return -1 if an error occurred, 0 otherwise
 */
int plot_game(window_t *game, SDL_Renderer *renderer) {
    if (game == NULL || renderer == NULL) {
        return -1;
    }
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
    return 0;
}

/**
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int setting_colors(window_t * game){
    if (game == NULL) {
        return -1;
    }
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

/**
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int PauseButton(SDL_Renderer *ButtonRender, window_t *game){
    if (game == NULL || ButtonRender == NULL) {
        return -1;
    }
    SDL_Surface *ButtonSur = NULL;
    SDL_Texture *ButtonText = NULL;
    SDL_Rect ButtRect;
    ButtRect.x = game->width / 2 - 20;
    ButtRect.y = game->height + 10;
    ButtRect.w = 40;
    ButtRect.h = 40;
    const char* buttonPausePlayFile[] = {"images/button_pause_0.png"};
    const char * OpenButton = buttonPausePlayFile[0];
    ButtonSur = IMG_Load(OpenButton);
    if (ButtonSur == NULL) {
        printf("\n[!] Error: Cannot load the button image!\n");
        exit(1);
    }
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isPauseOnButton(Uint32 x, Uint32 y, window_t *game){
    if (game == NULL) {
        return -1;
    }
    if (x >= game->width / 2 - 20 && x <= game->width / 2 + 20)
        if (y >= game->height + 10 && y <= game->height + 50) return 1;
    return 0;
}

/**
 *
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int speedDownButton(SDL_Renderer *ButtonRender, window_t *game){
    if (game == NULL || ButtonRender == NULL) {
        return -1;
    }
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
    if (ButtonSur == NULL) {
        printf("\n[!] Error: Cannot load the button image!\n");
        exit(1);
    }
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isSpeedDownOnButton(Uint32 x, Uint32 y, window_t *game){
    if (game == NULL) {
        return -1;
    }
    if (x >= game->width / 2 - 70 && x <= game->width / 2 - 40)
        if (y >= game->height + 15 && y <= game->height + 45) return 1;
    return 0;
}

/**
 *
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int speedUpButton(SDL_Renderer *ButtonRender, window_t *game){
    if(game == NULL || ButtonRender == NULL){
        return -1;
    }
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
    if (ButtonSur == NULL) {
        printf("\n[!] Error: Cannot load the button image!\n");
        exit(1);
    }
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isSpeedUpOnButton(Uint32 x, Uint32 y, window_t *game){
    if (game == NULL){
        return -1;
    }
    if (x >= game->width / 2 + 40 && x <= game->width / 2 + 70)
        if (y >= game->height + 15 && y <= game->height + 45) return 1;
    return 0;
}

/**
 *
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int clearButton(SDL_Renderer *ButtonRender, window_t *game){
    if (game == NULL || ButtonRender == NULL){
        return -1;
    }
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
    if (ButtonSur == NULL) {
        printf("\n[!] Error: Cannot load the button image!\n");
        exit(1);
    }
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isClearOnButton(Uint32 x, Uint32 y, window_t *game){
    if (game == NULL){
        return -1;
    }
    if (x >= 10 && x <= 40)
        if (y >= game->height + 15 && y <= game->height + 45) return 1;
    return 0;
}

/**
 *
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int randomButton(SDL_Renderer *ButtonRender, window_t *game){
    if (game == NULL || ButtonRender == NULL){
        return -1;
    }
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
    if (ButtonSur == NULL) {
        printf("\n[!] Error: Cannot load the button image!\n");
        exit(1);
    }
    ButtonText = SDL_CreateTextureFromSurface(ButtonRender, ButtonSur);
    SDL_RenderCopy(ButtonRender, ButtonText, NULL, &ButtRect);
    return 0;
}

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isRandomOnButton(Uint32 x, Uint32 y, window_t *game){
    if (game == NULL){
        return -1;
    }
    if (x >= game->width - 40 && x <= game->width - 10)
        if (y >= game->height + 15 && y <= game->height + 45) return 1;
    return 0;
}

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showGeneration(SDL_Renderer *renderer){
    if (renderer == NULL){
        return -1;
    }
    if (TTF_Init() == -1) {
        printf("[!] TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 14);
    if (font == NULL) {
        printf("[!] TTF_OpenFont: %s\n", TTF_GetError());
        exit(2);
    }
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, "Generation: ", textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = 10;
    textRect.y = 10;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param count the number of the generation
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showGenerationNum(int count, SDL_Renderer *renderer){
    if (renderer == NULL){
        return -1;
    }
    char str[10];
    if (TTF_Init() == -1) {
        printf("[!] TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 14);
    if (font == NULL) {
        printf("[!] TTF_OpenFont: %s\n", TTF_GetError());
        exit(2);
    }
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, itoa(count, str, 10), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = 90;
    textRect.y = 10;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showDelay(SDL_Renderer *renderer, window_t *game){
    if (renderer == NULL || game == NULL){
        return -1;
    }
    if (TTF_Init() == -1) {
        printf("[!] TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 14);
    if (font == NULL) {
        printf("[!] TTF_OpenFont: %s\n", TTF_GetError());
        exit(2);
    }
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, "Delay: ", textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = game->width - 100;
    textRect.y = 10;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showDelayNum(SDL_Renderer *renderer, window_t *game){
    if (renderer == NULL || game == NULL){
        return -1;
    }
    char str[10];
    if (TTF_Init() == -1) {
        printf("[!] TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 14);
    if (font == NULL) {
        printf("[!] TTF_OpenFont: %s\n", TTF_GetError());
        exit(2);
    }
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, itoa(game->delay, str, 10), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = game->width - 55;
    textRect.y = 10;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showPause(SDL_Renderer *renderer, window_t *game){
    if (renderer == NULL || game == NULL){
        return -1;
    }
    if (TTF_Init() == -1) {
        printf("[!] TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 20);
    if (font == NULL) {
        printf("[!] TTF_OpenFont: %s\n", TTF_GetError());
        exit(2);
    }
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, "P A U S E", textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = game->width / 2 - textSurface->w / 2;
    textRect.y = 10;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showLives(SDL_Renderer *renderer, window_t *game){
    if (renderer == NULL || game == NULL){
        return -1;
    }
    if (TTF_Init() == -1) {
        printf("[!] TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 14);
    if (font == NULL) {
        printf("[!] TTF_OpenFont: %s\n", TTF_GetError());
        exit(2);
    }
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, "Lives:", textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = game->width / 2 - textSurface->w / 2 - 20;
    textRect.y = game->height - 10;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @param lives the number of lives
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showLivesNum(SDL_Renderer *renderer, window_t *game, int lives){
    if (renderer == NULL || game == NULL){
        return -1;
    }
    char str[10];
    if (TTF_Init() == -1) {
        printf("[!] TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    TTF_Font *font = TTF_OpenFont("fonts/arial.ttf", 14);
    if (font == NULL) {
        printf("[!] TTF_OpenFont: %s\n", TTF_GetError());
        exit(2);
    }
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, itoa(lives, str, 10), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = game->width / 2 - textSurface->w / 2 + 10;
    textRect.y = game->height - 10;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
    return 0;
}