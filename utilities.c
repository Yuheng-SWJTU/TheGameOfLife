#include "utilities.h"
#include <string.h>
#include <stdlib.h>

char * choose_width(char * temp, int width){
    char *result = (char *)malloc(sizeof(char) * width);
    for (int i = 0; i < width; i ++) {
        if(temp[i] != '0' && temp[i] != '1'){
            temp[i] = '0';
        }
        result[i] = temp[i];
    }
    return result;
}

char * check_init(char * line){
    for (int i = 0; i < strlen(line); i ++) {
        if (line[i] == '\n'){
            continue;
        }
        if (line[i] < '0' || line[i] > '9') {
            return "Error";
        }
    }
    return line;
}
