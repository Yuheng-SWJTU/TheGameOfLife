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

#endif //THEGAMEOFLIFE_WINDOW_H