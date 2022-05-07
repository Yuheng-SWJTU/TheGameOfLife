#include "window.h"
#include "game.h"
#include <SDL.h>
#include <stdio.h>

int point_size = 4;

void plot_game(window_t *game, SDL_Renderer *renderer) {
    // Plot the game
    for (int i = 0; i < game->height; i ++) {
        for (int j = 0; j < game->width; j ++) {
            if (game->array[i][j] == '1') {
                SDL_Rect rec;
                rec.x = i * point_size;
                rec.y = j * point_size;
                rec.w = point_size;
                rec.h = point_size;
                SDL_RenderFillRect(renderer, &rec);
            }
        }
    }
}
