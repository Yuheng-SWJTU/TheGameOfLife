#ifndef THEGAMEOFLIFE_GAME_H
#define THEGAMEOFLIFE_GAME_H

#include "window.h"

/**
 * @brief Initializes the game.
 *
 * @param game The game to initialize.
 * @return 0 on success, -1 on failure.
 */
window_t * init_game(char * init_file);

/**
 * @brief This function is used to detect the next generation of the game
 * @param game is the game struct
 * @return return 0 if the function is successful, -1 if pointer is NULL
 */
int detect_neighbours(window_t * game);

/**
 * @brief This function is used to free the memory
 * @param game is the game struct
 * @return 0 if the function is successful, -1 if the pointer is NULL
 */
int end_game(window_t * game);

/**
 * @brief This function is used to save the game into a file
 * @param game is the game struct
 * @return 0 if the function is successful, -1 if the pointer is NULL
 */
int save_game(window_t * game);

/**
 * @brief This function is used to clear the screen
 * @param game is the game struct
 * @return 0 if the function is successful, -1 if the pointer is NULL
 */
int clear_screen(window_t * game);

/**
 * @brief This function is used to generate the lives randomly
 * @param game is the game struct
 * @return 0 if the function is successful, -1 if the pointer is NULL
 */
int random(window_t * game);

#endif //THEGAMEOFLIFE_GAME_H