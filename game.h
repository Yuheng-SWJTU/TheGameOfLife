#ifndef THEGAMEOFLIFE_GAME_H
#define THEGAMEOFLIFE_GAME_H
#define POINT_SIZE 4

#include "window.h"

window_t * init_game(char * settings_file, char * map_file);
void detect_neighbours(window_t * game);
void end_game(window_t * game);

#endif //THEGAMEOFLIFE_GAME_H