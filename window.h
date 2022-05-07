#ifndef THEGAMEOFLIFE_WINDOW_H
#define THEGAMEOFLIFE_WINDOW_H

#include <SDL.h>

typedef struct {
    unsigned char ** array;
    unsigned char ** array_next;
    int width;
    int height;
    int delay;
} window_t;

void creat_window(window_t * game);
void plot_game(window_t *game, SDL_Renderer *renderer);

#endif //THEGAMEOFLIFE_WINDOW_H