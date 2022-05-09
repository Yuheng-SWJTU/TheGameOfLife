#ifndef THEGAMEOFLIFE_WINDOW_H
#define THEGAMEOFLIFE_WINDOW_H

#include <SDL.h>

typedef struct {
    int width_num;
    int height_num;
    int width;
    int height;
    int point_size;
    char * background_color;
    char * cell_color;
    int delay;
    unsigned char ** array;
    unsigned char ** array_next;
} window_t;

void plot_game(window_t *game, SDL_Renderer *renderer);

#endif //THEGAMEOFLIFE_WINDOW_H