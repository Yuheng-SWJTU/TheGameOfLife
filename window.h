#ifndef THEGAMEOFLIFE_WINDOW_H
#define THEGAMEOFLIFE_WINDOW_H

#include <SDL.h>

// The struct for the game to contain all the information
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

/**
 * @param game a struct containing all the game's data
 * @param renderer the renderer to use
 * @return -1 if an error occurred, 0 otherwise
 */
int plot_game(window_t *game, SDL_Renderer *renderer);

/**
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int setting_colors(window_t * game);

/**
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int PauseButton(SDL_Renderer *ButtonRender, window_t *game);

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isPauseOnButton(Uint32 x, Uint32 y, window_t *game);

/**
 *
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int speedDownButton(SDL_Renderer *ButtonRender, window_t *game);

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isSpeedDownOnButton(Uint32 x, Uint32 y, window_t *game);

/**
 *
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int speedUpButton(SDL_Renderer *ButtonRender, window_t *game);

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isSpeedUpOnButton(Uint32 x, Uint32 y, window_t *game);

/**
 *
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int clearButton(SDL_Renderer *ButtonRender, window_t *game);

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isClearOnButton(Uint32 x, Uint32 y, window_t *game);

/**
 *
 * @param ButtonRender a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int randomButton(SDL_Renderer *ButtonRender, window_t *game);

/**
 *
 * @param x the x coordinate of the cell
 * @param y the y coordinate of the cell
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int isRandomOnButton(Uint32 x, Uint32 y, window_t *game);

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showGeneration(SDL_Renderer *renderer);

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param count the number of the generation
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showGenerationNum(int count, SDL_Renderer *renderer);

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showDelay(SDL_Renderer *renderer, window_t *game);

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showDelayNum(SDL_Renderer *renderer, window_t *game);

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showPause(SDL_Renderer *renderer, window_t *game);

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showLives(SDL_Renderer *renderer, window_t *game);

/**
 *
 * @param renderer a pointer to the SDL_Renderer
 * @param game a struct containing all the game's data
 * @param lives the number of lives
 * @return -1 if an error occurred, 0 if the pointer is NULL
 */
int showLivesNum(SDL_Renderer *renderer, window_t *game, int lives);

#endif //THEGAMEOFLIFE_WINDOW_H