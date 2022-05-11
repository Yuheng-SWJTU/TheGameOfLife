#include "game.h"
#include "utilities.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

// A function to initial the game
window_t * init_game( char * init_file ){
    // Allocate memory for the window_t
    window_t * game = malloc(sizeof(window_t));

    // Read the settings.txt file
    FILE * init = fopen(init_file, "r");
    if (init == NULL) {
        printf("\n[!] Error: settings.txt not found\n");
        exit(1);
    }
    // Read the first line of the file
    char line[100];
    fgets(line, 100, init);
    if (strcmp(check_init(line), "Error") == 0) {
        printf("\n[!] Error: the 'width_num' should be a number!\n");
        exit(1);
    }
    game->width_num = atoi(line);
    // Read the second line of the file
    fgets(line, 100, init);
    if (strcmp(check_init(line), "Error") == 0) {
        printf("\n[!] Error: the 'height_num' should be a number!\n");
        exit(1);
    }
    game->height_num = atoi(line);
    // Read the third line of the file
    fgets(line, 100, init);
    if (strcmp(check_init(line), "Error") == 0) {
        printf("\n[!] Error: the 'point_size' should be a number!\n");
        exit(1);
    }
    game->point_size = atoi(line);
    // Read the fourth line of the file
    fgets(line, 100, init);
    // Allocate memory for the background_color
    game->background_color = malloc((strlen(line) + 1) * sizeof(char));
    strcpy(game->background_color, line);
    // Read the fifth line of the file
    fgets(line, 100, init);
    // Allocate memory for the point_color
    game->cell_color = malloc((strlen(line) + 1) * sizeof(char));
    strcpy(game->cell_color, line);
    // Read the sixth line of the file
    fgets(line, 100, init);
    if (strcmp(check_init(line), "Error") == 0) {
        printf("\n[!] Error: the 'delay' should be a number!\n");
        exit(1);
    }
    game->delay = atoi(line);

    game->width = game->width_num * game->point_size;
    game->height = game->height_num * game->point_size;

    // Check point_size
    if (game->point_size < 2) {
        printf("\n[!] Error: the 'point_size' should be at least 2!");
        exit(2);
    }

    // Check width_num
    if (game->width_num < 9 || game->width_num > 210) {
        printf("\n[!] Error: the 'width_num' should be between 9 and 210!");
        exit(2);
    }

    // Check height_num
    if (game->height_num < 9 || game->height_num > 120){
        printf("\n[!] Error: the 'height_num' should be between 9 and 120!");
        exit(2);
    }

    // Check resolution
    if (game->width > 1200 || game->width < 400 || game->height > 720 || game->height < 240) {
        printf("\n[!] Warning: 'width_num' x 'point_size' should be between 400 and 1200!"
               "\n[!] and 'height_num' x 'point_size' should be between 240 and 720!"
               "\n[!] We have set the best resolution for you!\n");
        game->width_num = 100;
        game->height_num = 60;
        game->point_size = 8;
        game->height = game->height_num * game->point_size;
        game->width = game->width_num * game->point_size;
    }

    // Check delay
    if (game->delay < 10 || game->delay > 600) {
        printf("\n[!] Warning: the 'delay' should be between 1 and 100!"
               "\n[!] We have set the best delay for you!\n");
        game->delay = 100;
    }

    setting_colors(game);

    // Allocate memory for the window_t array
    game->array = malloc((game->height_num) * sizeof (unsigned char *));
    game->array_next = malloc((game->height_num) * sizeof (unsigned char *));

    for (int i = 0; i < game->height_num; i++) {
        game->array[i] = malloc((game->width_num) * sizeof (unsigned char));
        game->array_next[i] = malloc((game->width_num) * sizeof (unsigned char));
        // Define a char to read the line
        char temp[1024];
        // Read the line
        fgets(temp, 1024, init);
        game->array[i] = (unsigned char *)choose_width(temp, game->width_num);
        game->array_next[i] = (unsigned char *) choose_width(temp, game->width_num);
    }
    return game;
}

void detect_neighbours(window_t * game){
    // Loop through the array
    for (int i = 0; i < game->height_num; i++) {
        for (int j = 0; j < game->width_num; j++) {
            // Define the number of neighbours
            int neighbours = 0;
            // Check the top left corner
            if (i > 0 && j > 0 && game->array[i - 1][j - 1] == '1') {
                neighbours++;
            }
            // Check the top middle
            if (i > 0 && game->array[i - 1][j] == '1') {
                neighbours++;
            }
            // Check the top right corner
            if (i > 0 && j < game->width_num - 1 && game->array[i - 1][j + 1] == '1') {
                neighbours++;
            }
            // Check the left
            if (j > 0 && game->array[i][j - 1] == '1') {
                neighbours++;
            }
            // Check the right
            if (j < game->width_num - 1 && game->array[i][j + 1] == '1') {
                neighbours++;
            }
            // Check the bottom left corner
            if (i < game->height_num - 1 && j > 0 && game->array[i + 1][j - 1] == '1') {
                neighbours++;
            }
            // Check the bottom middle
            if (i < game->height_num - 1 && game->array[i + 1][j] == '1') {
                neighbours++;
            }
            // Check the bottom right corner
            if (i < game->height_num - 1 && j < game->width_num - 1 && game->array[i + 1][j + 1] == '1') {
                neighbours++;
            }
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
    for (int i = 0; i < game->height_num; i ++) {
        memcpy(game->array[i], game->array_next[i], game->width_num * sizeof (unsigned char));
    }
}

void end_game(window_t * game){
    // Free the memory
    for (int i = 0; i < game->height_num; i++) {
        free(game->array[i]);
        free(game->array_next[i]);
    }
    free(game->array);
    free(game->array_next);
    free(game);
}

void save_game(window_t * game){
    // Open the file
    FILE * file = fopen("history.txt", "w");
    // If error, return
    if (file == NULL) {
        printf("[!] Error: saving error!\n");
        exit(3);
    }
    printf("Saving the game...\n");
    // Saving the width and height
    fprintf(file, "%d\n", game->width_num);
    fprintf(file, "%d\n", game->height_num);
    fprintf(file, "%d\n", game->point_size);
    fprintf(file, "%s", game->background_color);
    fprintf(file, "%s", game->cell_color);
    fprintf(file, "%d\n", game->delay);
    // Print the state
    for (int i = 0; i < game->height_num; i ++) {
        for (int j = 0; j < game->width_num; j ++) {
            fprintf(file, "%c", game->array[i][j]);
        }
        fprintf(file, "\n");
    }
    // Close the file
    fclose(file);
}
