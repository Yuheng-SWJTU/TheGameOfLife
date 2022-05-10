#include "utilities.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define MAX_WIDTH 1200
# define MAX_HEIGHT 720

char * choose_width(const char * temp, int width){
    char *result = (char *)malloc(sizeof(char) * width);
    for (int i = 0; i < width; i ++) {
        result[i] = temp[i];
    }
    return result;
}

int check_resolution(int width_num, int height_num, int point_size){
    if (width_num < 9 || height_num < 9){
        return 1;
    } else if (point_size < 1){
        return 2;
    } else if (width_num * point_size > MAX_WIDTH){
        return 3;
    } else if (height_num * point_size > MAX_HEIGHT){
        return 4;
    } else {
        return 0;
    }
}
