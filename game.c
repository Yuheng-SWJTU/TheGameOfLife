#include "game.h"
#include "window.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to initial the game
void init_game(window_t *game) {
    // Read the settings.txt file
    FILE *settings = fopen("settings.txt", "r");
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

}