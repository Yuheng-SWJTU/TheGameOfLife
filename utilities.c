#include "utilities.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char * choose_width(char * temp, int width){
    if (width <= 0){
        printf("[!] Error: width must be greater than 0\n");
        return "-1";
    }
    if (temp == NULL){
        printf("[!] Error: pointer is NULL\n");
        return "-1";
    }
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
    if (line == NULL){
        printf("\n[!] Error: the 'line' pointer is NULL!\n");
        return "-1";
    }
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
