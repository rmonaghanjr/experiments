#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {

    clock_t start, end;
    double cpu_time_used;
    int r = 0;
    // standard division
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        printf("\rsd: running test %d...", i);
        fflush(stdout);

        r = i / 10;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\rstandard division: %f(s)\n", cpu_time_used);

    // floating point multiplication
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        printf("\rfp: running test %d...", i);
        fflush(stdout);

        r = i * 0.1;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\rfloating point mul: %f(s)\n", cpu_time_used);

    // fast division
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        printf("\rfd: running test %d...", i);
        fflush(stdout);

        r = (int) (((long int) 0x1999999A * i) >> 32);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\rfast division: %f(s)\n", cpu_time_used);

    return 0;
}
