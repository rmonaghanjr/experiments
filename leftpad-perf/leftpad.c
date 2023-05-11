#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// liaugdsoiuagdoisagodi
//               goodbye
//                 hello

// implementations 
char* ryanmonaghan_left_pad(char* str, char pad, size_t width) {
    int len = strlen(str);
    char* padded = (char*) calloc(1, width);
    width = width - len;
    memset(padded, pad, width); // pad string
    strcat(padded, str); // add string
    return padded;
}

// as close as i can get in c
char* npm_left_pad(char* str, char pad, size_t width) {
    int len = strlen(str);
    char* padded = (char*) malloc(width);
    int i = 0;
    if (!pad && pad != 0) pad = ' ';
    width = width - len;
    while (i < width) {
        padded[i++] = pad;
    }
    padded[i] = '\0';
    strcat(padded, str);
    return padded;
}

char* while_left_pad(char* str, char pad, size_t width) {
    int len = strlen(str);
    char* padded = (char*) malloc(width);
    int i = 0;
    memset(padded, 0, width); // clear malloc'd memory
    width = width - len;
    while (i < width) padded[i++] = pad;
    strcat(padded, str);
    return padded;
}

char* for_left_pad(char* str, char pad, size_t width) {
    int len = strlen(str);
    char* padded = (char*) malloc(width);
    memset(padded, 0, width); // clear malloc'd memory
    width = width - len;
    for (int i = 0; i < width; i++) padded[i] = pad;
    strcat(padded, str);
    return padded;
}

