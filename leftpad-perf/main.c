#include <stdio.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#include "leftpad.h"

int main(int arcg, char** argv) {
    clock_t t;
    double time_taken;

    char* strings[5];
    strings[0] = (char*) calloc(1, 2);
    strings[1] = (char*) calloc(1, 11);
    strings[2] = (char*) calloc(1, 101);
    strings[3] = (char*) calloc(1, 1001); // KB string
    strings[4] = (char*) calloc(1, 1000001); // MB string
    
    memset(strings[0], 'A', 1);
    memset(strings[1], 'A', 10);
    memset(strings[2], 'A', 100);
    memset(strings[3], 'A', 1000);
    memset(strings[4], 'A', 1000000);

    int sizes[5];
    sizes[0] = 0;
    sizes[1] = 1;
    sizes[2] = 100;
    sizes[3] = 1000;
    sizes[4] = 1000000;

    for (int i = 0; i < 5; i++) {
        int strsz = strlen(strings[i]);
        for (int j = 0; j < 5; j++) {
            printf("%d", strsz);
            printf(":%d", sizes[j]);
            printf(":ryanmonaghan_leftpad");
            t = clock();
            free(ryanmonaghan_left_pad(strings[i], ' ', strsz + sizes[j]));
            time_taken = ((double) clock() - t) / (CLOCKS_PER_SEC);
            printf(":%f\n", time_taken * 1000); 

            printf("%d", strsz);
            printf(":%d", sizes[j]);
            printf(":npm_leftpad");
            t = clock();
            free(npm_left_pad(strings[i], ' ', strsz + sizes[j]));
            time_taken = ((double) clock() - t) / (CLOCKS_PER_SEC);
            printf(":%f\n", time_taken * 1000); 
            
            printf("%d", strsz);
            printf(":%d", sizes[j]);
            printf(":while_leftpad");
            t = clock();
            free(while_left_pad(strings[i], ' ', strsz + sizes[j]));
            time_taken = ((double) clock() - t) / (CLOCKS_PER_SEC);
            printf(":%f\n", time_taken * 1000); 
            
            printf("%d", strsz);
            printf(":%d", sizes[j]);
            printf(":for_leftpad");
            t = clock();
            free(for_left_pad(strings[i], ' ', strsz + sizes[j]));
            time_taken = ((double) clock() - t) / (CLOCKS_PER_SEC);
            printf(":%f\n", time_taken * 1000); 
        }

        free(strings[i]);
    }

    return 0;
}
