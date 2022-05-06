#ifndef THEGAMEOFLIFE_WINDOW_H
#define THEGAMEOFLIFE_WINDOW_H

typedef struct {
    unsigned char ** array;
    unsigned char ** array_next;
    int width;
    int height;
    int delay;
} window_t;

#endif //THEGAMEOFLIFE_WINDOW_H