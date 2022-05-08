#include "window.h"
#include "game.h"

#include <SDL.h>

void plot_game(window_t *game, SDL_Renderer *renderer) {
    // Plot the game
    for (int i = 0; i < game->height_num; i ++) {
        for (int j = 0; j < game->width_num; j ++) {
            if (game->array[i][j] == '1') {
                SDL_Rect rec;
                rec.x = j * POINT_SIZE;
                rec.y = i * POINT_SIZE;
                rec.w = POINT_SIZE;
                rec.h = POINT_SIZE;
                SDL_RenderFillRect(renderer, &rec);
            }
        }
    }
}
