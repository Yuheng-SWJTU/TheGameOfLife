#include "game.h"
#include "window.h"
#include "utilities.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

// A function to initial the game
window_t * init_game(char * settings_file, char * map_file){
    // Allocate memory for the window_t
    window_t * game = malloc(sizeof(window_t));

    // Read the settings.txt file
    FILE *settings = fopen(settings_file, "r");
    if (settings == NULL) {
        printf("Error: settings.txt not found\n");
        exit(1);
    }
    // Read the first line of the file
    char line[100];
    fgets(line, 100, settings);
    game->width = atoi(line);
    // Read the second line of the file
    fgets(line, 100, settings);
    game->height = atoi(line);
    // Read the third line of the file
    fgets(line, 100, settings);
    game->delay = atoi(line);
    // Close the file
    fclose(settings);

    // Read the map.txt file
    FILE *map = fopen(map_file, "r");
    if (map == NULL) {
        printf("Error: init_state.txt not found\n");
        exit(1);
    }

    // Allocate memory for the window_t array
    game->array = malloc((game->height) * sizeof (unsigned char *));
    game->array_next = malloc((game->height) * sizeof (unsigned char *));

    for (int i = 0; i < game->height; i++) {
        game->array[i] = malloc((game->width) * sizeof (unsigned char));
        game->array_next[i] = malloc((game->width) * sizeof (unsigned char));
        // Define a char to read the line
        char temp[1024];
        // Read the line
        fgets(temp, 1024, map);
        game->array[i] = (unsigned char *)choose_width(temp, game->width);
        game->array_next[i] = game->array[i];
    }

    return game;
}

void detect_neighbours(window_t * game){
    // Loop through the array
    for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            // Define the number of neighbours
            int neighbours = 0;
            // Check the top left corner
//            printf("origin: %d, %d, %c\n", i, j, game->array[i][j]);
            if (i > 0 && j > 0 && game->array[i - 1][j - 1] == '1') {
//                printf("top left corner\n");
                neighbours++;
            }
            // Check the top middle
            if (i > 0 && game->array[i - 1][j] == '1') {
//                printf("top middle\n");
                neighbours++;
            }
            // Check the top right corner
            if (i > 0 && j < game->width - 1 && game->array[i - 1][j + 1] == '1') {
//                printf("top right corner\n");
                neighbours++;
            }
            // Check the left
            if (j > 0 && game->array[i][j - 1] == '1') {
//                printf("left\n");
                neighbours++;
            }
            // Check the right
            if (j < game->width - 1 && game->array[i][j + 1] == '1') {
//                printf("right\n");
                neighbours++;
            }
            // Check the bottom left corner
            if (i < game->height - 1 && j > 0 && game->array[i + 1][j - 1] == '1') {
//                printf("bottom left corner\n");
                neighbours++;
            }
            // Check the bottom middle
            if (i < game->height - 1 && game->array[i + 1][j] == '1') {
//                printf("bottom middle\n");
                neighbours++;
            }
            // Check the bottom right corner
            if (i < game->height - 1 && j < game->width - 1 && game->array[i + 1][j + 1] == '1') {
//                printf("bottom right corner\n");
                neighbours++;
            }
//            printf("%d\n", neighbours);
            // Check if the cell is alive
            if (game->array[i][j] == '1') {
                // If the cell is alive and has 2 or 3 neighbours, it stays alive
                if (neighbours == 2 || neighbours == 3) {
                    game->array_next[i][j] = '1';
                } else {
                    // If the cell is alive and has less than 2 or more than 3 neighbours, it dies
                    game->array_next[i][j] = '0';
                }
            } else {
                // If the cell is dead and has 3 neighbours, it becomes alive
                if (neighbours == 3) {
                    game->array_next[i][j] = '1';
                } else {
                    // If the cell is dead and has less than 3 neighbours, it stays dead
                    game->array_next[i][j] = '0';
                }
            }
        }
    }
    // Save the state
    for (int i = 0; i < game->height; i ++) {
        memcpy(game->array[i], game->array_next[i], game->width * sizeof(unsigned char));
//        printf("hhhh:\n");
//        printf("%s\n", game->array[i]);
    }
}

void end_game(window_t * game){
    // Free the memory
    for (int i = 0; i < game->height; i++) {
        free(game->array[i]);
        free(game->array_next[i]);
    }
    free(game->array);
    free(game->array_next);
    free(game);
}
