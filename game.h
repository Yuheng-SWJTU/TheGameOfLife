#ifndef THEGAMEOFLIFE_GAME_H
#define THEGAMEOFLIFE_GAME_H

#include "window.h"

window_t * init_game(char * init_file);
int detect_neighbours(window_t * game);
int end_game(window_t * game);
int save_game(window_t * game);
int clear_screen(window_t * game);
int random(window_t * game);

#endif //THEGAMEOFLIFE_GAME_H