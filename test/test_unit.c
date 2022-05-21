#include "../game.h"
#include "../CUnit/Basic.h"
#include "../utilities.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program is to test the functions in TheGameOfLife
 * CONTAINS:
 *  - game.c
 *  - utilities.c
 *  - window.c
 *  --------------------------------------------------
 *  All of the information will be demonstrated in the
 *  console.
 *  -------------------------------------------------
 *  CUnit is used to as the testing framework.
 *  -------------------------------------------------
 *  Expected output:
 *  Total suites: 1
 *  Total tests: 24
 *  Total asserts: 78
 *  Total passed: 78
 *  Total failed: 0
 */

window_t * init_structure (void){
    // Allocate memory for the test_struct
    window_t * test = malloc(sizeof(window_t));
    // Initialize the test_struct
    test->width_num = 10;
    test->height_num = 10;
    test->width = 100;
    test->height = 100;
    test->point_size = 10;
    test->R_bac = 255;
    test->G_bac = 255;
    test->B_bac = 255;
    test->R_cell = 255;
    test->G_cell = 255;
    test->B_cell = 255;
    test->background_color = "white";
    test->cell_color = "black";
    test->delay = 1;
    test->array = malloc(sizeof(unsigned char *) * test->height_num);
    test->array_next = malloc(sizeof(unsigned char *) * test->height_num);
    for (int i = 0; i < test->height_num; i++) {
        test->array[i] = malloc(sizeof(unsigned char) * test->width_num);
        test->array_next[i] = malloc(sizeof(unsigned char) * test->width_num);
    }
    // Initialize the test_struct
    for (int i = 0; i < test->height_num; i++) {
        for (int j = 0; j < test->width_num; j++) {
            test->array[i][j] = 0;
            test->array_next[i][j] = 0;
        }
    }
    return test;
}

void free_memory(window_t * test){
    // Free the memory
    for (int i = 0; i < test->height_num; i++) {
        free(test->array[i]);
        free(test->array_next[i]);
    }
    free(test->array);
    free(test->array_next);
    free(test);
}

static void test_detect_neighbors(void)
{
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(detect_neighbours(test), 0);
    CU_ASSERT_EQUAL(detect_neighbours(NULL), -1);
    // Free the memory
    free_memory(test);

}

static void test_clear_screen(void)
{
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(clear_screen(test), 0);
    CU_ASSERT_EQUAL(clear_screen(NULL), -1);
    // Free the memory
    free_memory(test);
}

static void test_random(void)
{
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(random(test), 0);
    CU_ASSERT_EQUAL(random(NULL), -1);
    // Free the memory
    free_memory(test);
}

static void test_end_game(void)
{
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(end_game(test), 0);
    CU_ASSERT_EQUAL(end_game(NULL), -1);
}

static void test_save_game(void)
{
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(save_game(test), 0);
    CU_ASSERT_EQUAL(save_game(NULL), -1);
    // Free the memory
    free_memory(test);
}

static void test_check_init(void)
{
    char * line = "123456789";
    char * line2 = "123abc";

    CU_ASSERT_STRING_EQUAL(check_init(NULL), "-1");
    CU_ASSERT_STRING_EQUAL(check_init(line), line);
    CU_ASSERT_STRING_EQUAL(check_init(line2), "Error");
}

static void test_choose_width(void){
    char * test1 = "0000000000";
    char * test2 = "aaaaaaaaaa";
    char result1 [] = "00000";
    int width1 = 5;
    int width2 = 0;
    int width3 = -1;

    CU_ASSERT_STRING_EQUAL(choose_width(NULL, width1), "-1");
    CU_ASSERT_STRING_EQUAL(choose_width(NULL, width2), "-1");
    CU_ASSERT_STRING_EQUAL(choose_width(NULL, width3), "-1");
    CU_ASSERT_STRING_EQUAL(choose_width(test2, width2), "-1");
    CU_ASSERT_STRING_EQUAL(choose_width(test2, width3), "-1");
    CU_ASSERT_STRING_EQUAL(choose_width(test1, width1), result1);
}

static void test_plot_game(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();

    CU_ASSERT_EQUAL(plot_game(NULL, NULL), -1);
    CU_ASSERT_EQUAL(plot_game(NULL, renderer), -1);
    CU_ASSERT_EQUAL(plot_game(test, NULL), -1);
    CU_ASSERT_EQUAL(plot_game(test, renderer), 0);

    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_setting_colors(void){
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(setting_colors(test), 0);
    CU_ASSERT_EQUAL(setting_colors(NULL), -1);
    // Free the memory
    free_memory(test);
}

static void test_PauseButton(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(PauseButton(NULL, NULL), -1);
    CU_ASSERT_EQUAL(PauseButton(NULL, test), -1);
    CU_ASSERT_EQUAL(PauseButton(renderer, NULL), -1);
    // Free the memory
    free_memory(test);

    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_isPauseOnButton(void){
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(isPauseOnButton(0, 0, test), 0);
    CU_ASSERT_EQUAL(isPauseOnButton(0, 0, NULL), -1);
    CU_ASSERT_EQUAL(isPauseOnButton(-1, 0, NULL), -1);
    CU_ASSERT_EQUAL(isPauseOnButton(0, -1, NULL), -1);
    CU_ASSERT_EQUAL(isPauseOnButton(-1, -1, NULL), -1);
    // Free the memory
    free_memory(test);
}

static void test_speedDownButton(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(speedDownButton(NULL, NULL), -1);
    CU_ASSERT_EQUAL(speedDownButton(NULL, test), -1);
    CU_ASSERT_EQUAL(speedDownButton(renderer, NULL), -1);
    // Free the memory
    free_memory(test);

    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_isSpeedDownOnButton(void){
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(isSpeedDownOnButton(0, 0, test), 0);
    CU_ASSERT_EQUAL(isSpeedDownOnButton(0, 0, NULL), -1);
    CU_ASSERT_EQUAL(isSpeedDownOnButton(-1, 0, NULL), -1);
    CU_ASSERT_EQUAL(isSpeedDownOnButton(0, -1, NULL), -1);
    CU_ASSERT_EQUAL(isSpeedDownOnButton(-1, -1, NULL), -1);
    // Free the memory
    free_memory(test);
}

static void test_speedUpButton(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(speedUpButton(NULL, NULL), -1);
    CU_ASSERT_EQUAL(speedUpButton(NULL, test), -1);
    CU_ASSERT_EQUAL(speedUpButton(renderer, NULL), -1);
    // Free the memory
    free_memory(test);

    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_isSpeedUpOnButton(void){
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(isSpeedUpOnButton(0, 0, test), 0);
    CU_ASSERT_EQUAL(isSpeedUpOnButton(0, 0, NULL), -1);
    CU_ASSERT_EQUAL(isSpeedUpOnButton(-1, 0, NULL), -1);
    CU_ASSERT_EQUAL(isSpeedUpOnButton(0, -1, NULL), -1);
    CU_ASSERT_EQUAL(isSpeedUpOnButton(-1, -1, NULL), -1);
    // Free the memory
    free_memory(test);
}

static void test_clearButton(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(clearButton(NULL, NULL), -1);
    CU_ASSERT_EQUAL(clearButton(NULL, test), -1);
    CU_ASSERT_EQUAL(clearButton(renderer, NULL), -1);
    // Free the memory
    free_memory(test);

    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_isClearOnButton(void){
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(isClearOnButton(0, 0, test), 0);
    CU_ASSERT_EQUAL(isClearOnButton(0, 0, NULL), -1);
    CU_ASSERT_EQUAL(isClearOnButton(-1, 0, NULL), -1);
    CU_ASSERT_EQUAL(isClearOnButton(0, -1, NULL), -1);
    CU_ASSERT_EQUAL(isClearOnButton(-1, -1, NULL), -1);
    // Free the memory
    free_memory(test);
}

static void test_randomButton(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(randomButton(NULL, NULL), -1);
    CU_ASSERT_EQUAL(randomButton(NULL, test), -1);
    CU_ASSERT_EQUAL(randomButton(renderer, NULL), -1);
    // Free the memory
    free_memory(test);

    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_isRandomOnButton(void){
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(isRandomOnButton(0, 0, test), 0);
    CU_ASSERT_EQUAL(isRandomOnButton(0, 0, NULL), -1);
    CU_ASSERT_EQUAL(isRandomOnButton(-1, 0, NULL), -1);
    CU_ASSERT_EQUAL(isRandomOnButton(0, -1, NULL), -1);
    CU_ASSERT_EQUAL(isRandomOnButton(-1, -1, NULL), -1);
    // Free the memory
    free_memory(test);
}

static void test_showGeneration(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Run the test
    CU_ASSERT_EQUAL(showGeneration(NULL), -1);

    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_showDelay(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(showDelay(NULL, NULL), -1);
    CU_ASSERT_EQUAL(showDelay(NULL, test), -1);
    CU_ASSERT_EQUAL(showDelay(renderer, NULL), -1);
    // Free the memory
    free_memory(test);
    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_showDelayNum(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(showDelayNum(NULL, NULL), -1);
    CU_ASSERT_EQUAL(showDelayNum(NULL, test), -1);
    CU_ASSERT_EQUAL(showDelayNum(renderer, NULL), -1);
    // Free the memory
    free_memory(test);
    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_showPause(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(showPause(NULL, NULL), -1);
    CU_ASSERT_EQUAL(showPause(NULL, test), -1);
    CU_ASSERT_EQUAL(showPause(renderer, NULL), -1);
    // Free the memory
    free_memory(test);
    SDL_DestroyWindow(windows);
    SDL_Quit();
}

static void test_showLives(void){
    // Window initialization
    SDL_Window *windows = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
    if(windows == NULL){
        printf("\n[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    // Renderer initialization
    SDL_Renderer *renderer = SDL_CreateRenderer(windows, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        printf("\n[!] Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
    window_t * test = init_structure();
    // Run the test
    CU_ASSERT_EQUAL(showLives(NULL, NULL), -1);
    CU_ASSERT_EQUAL(showLives(NULL, test), -1);
    CU_ASSERT_EQUAL(showLives(renderer, NULL), -1);
    // Free the memory
    free_memory(test);
    SDL_DestroyWindow(windows);
    SDL_Quit();
}

int main(int argc, char * argv[]){
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Register suites
    CU_pSuite pSuite = CU_add_suite("Test Suite", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add tests to the suite
    if ((NULL == CU_add_test(pSuite, "test_detect_neighbors", test_detect_neighbors)) ||
        (NULL == CU_add_test(pSuite, "test_clear_screen", test_clear_screen)) ||
        (NULL == CU_add_test(pSuite, "test_random", test_random)) ||
        (NULL == CU_add_test(pSuite, "test_end_game", test_end_game)) ||
        (NULL == CU_add_test(pSuite, "test_save_game", test_save_game)) ||
        (NULL == CU_add_test(pSuite, "test_check_init", test_check_init)) ||
        (NULL == CU_add_test(pSuite, "test_choose_width", test_choose_width)) ||
        (NULL == CU_add_test(pSuite, "test_plot_game", test_plot_game)) ||
        (NULL == CU_add_test(pSuite, "test_setting_colors", test_setting_colors)) ||
        (NULL == CU_add_test(pSuite, "test_PauseButton", test_PauseButton)) ||
        (NULL == CU_add_test(pSuite, "test_isPauseOnButton", test_isPauseOnButton)) ||
        (NULL == CU_add_test(pSuite, "test_speedDownButton", test_speedDownButton)) ||
        (NULL == CU_add_test(pSuite, "test_isSpeedDownOnButton", test_isSpeedDownOnButton)) ||
        (NULL == CU_add_test(pSuite, "test_speedUpButton", test_speedUpButton)) ||
        (NULL == CU_add_test(pSuite, "test_isSpeedUpOnButton", test_isSpeedUpOnButton)) ||
        (NULL == CU_add_test(pSuite, "test_clearButton", test_clearButton)) ||
        (NULL == CU_add_test(pSuite, "test_isClearOnButton", test_isClearOnButton)) ||
        (NULL == CU_add_test(pSuite, "test_randomButton", test_randomButton)) ||
        (NULL == CU_add_test(pSuite, "test_isRandomOnButton", test_isRandomOnButton)) ||
        (NULL == CU_add_test(pSuite, "test_showGeneration", test_showGeneration)) ||
        (NULL == CU_add_test(pSuite, "test_showDelay", test_showDelay)) ||
        (NULL == CU_add_test(pSuite, "test_showDelayNum", test_showDelayNum)) ||
        (NULL == CU_add_test(pSuite, "test_showPause", test_showPause)) ||
        (NULL == CU_add_test(pSuite, "test_showSpeed", test_showLives))
        ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Clean up registry and return
    CU_cleanup_registry();
    return CU_get_error();
}
