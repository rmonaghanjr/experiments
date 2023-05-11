#ifndef LEFTPAD_H
#define LEFTPAD_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

// implementations 

char* ryanmonaghan_left_pad(char* str, char pad, size_t count);
char* npm_left_pad(char* str, char pad, size_t count);
char* while_left_pad(char* str, char pad, size_t count);
char* for_left_pad(char* str, char pad, size_t count);

#endif
