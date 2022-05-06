#ifndef THEGAMEOFLIFE_GAME_H
#define THEGAMEOFLIFE_GAME_H

#include "window.h"

window_t * init_game(char * settings_file, char * map_file);
void detect_neighbours(window_t * game);

#endif //THEGAMEOFLIFE_GAME_H