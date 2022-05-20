#ifndef THEGAMEOFLIFE_WINDOW_H
#define THEGAMEOFLIFE_WINDOW_H

#include <SDL.h>

typedef struct {
    int width_num;
    int height_num;
    int width;
    int height;
    int point_size;
    int R_bac;
    int G_bac;
    int B_bac;
    int R_cell;
    int G_cell;
    int B_cell;
    char * background_color;
    char * cell_color;
    int delay;
    unsigned char ** array;
    unsigned char ** array_next;
} window_t;

void plot_game(window_t *game, SDL_Renderer *renderer);
int setting_colors(window_t * game);
int PauseButton(Uint32 ButtonMode, SDL_Renderer *ButtonRender, window_t *game);
int isPauseOnButton(Uint32 x, Uint32 y, window_t *game);
int speedDownButton(SDL_Renderer *ButtonRender, window_t *game);
int isSpeedDownOnButton(Uint32 x, Uint32 y, window_t *game);
int speedUpButton(SDL_Renderer *ButtonRender, window_t *game);
int isSpeedUpOnButton(Uint32 x, Uint32 y, window_t *game);
int clearButton(SDL_Renderer *ButtonRender, window_t *game);
int isClearOnButton(Uint32 x, Uint32 y, window_t *game);
int randomButton(SDL_Renderer *ButtonRender, window_t *game);
int isRandomOnButton(Uint32 x, Uint32 y, window_t *game);
int showGeneration(SDL_Renderer *renderer);
int showGenerationNum(int count, SDL_Renderer *renderer);
int showDelay(SDL_Renderer *renderer, window_t *game);
int showDelayNum(SDL_Renderer *renderer, window_t *game);
int showPause(SDL_Renderer *renderer, window_t *game);
int showLives(SDL_Renderer *renderer, window_t *game);
int showLivesNum(SDL_Renderer *renderer, window_t *game, int lives);

#endif //THEGAMEOFLIFE_WINDOW_H