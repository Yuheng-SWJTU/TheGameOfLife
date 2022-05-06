#include "utilities.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * choose_width(const char * temp, int width){
    char *result = (char *)malloc(sizeof(char) * width);
    for (int i = 0; i < width; i ++) {
        result[i] = temp[i];
    }
    return result;
}
