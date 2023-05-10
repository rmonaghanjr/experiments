#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>

void fill(long int* buffer, int buf_size) {
    free(buffer);
    buffer = (long int*) malloc(buf_size * sizeof(long int));
    
    for (int i = 0; i < buf_size; i++) {
        buffer[i] = 1; 
    } 
}

int main(int argc, char** argv) {
    int buf_size = 0;
    
    while (*argv[1]) {
        if (*argv[1] - '0' >= 0) {
            buf_size *= 10;
            buf_size += (*argv[1]++ - '0');
        } else {
            break;
        }
    }

    __uint128_t strb = *(__uint128_t*) "\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64\x21\x0a\x00\x00\x00";
    char* p_buff = (char*) malloc(buf_size * sizeof(char));
    long int* buffer = (long int*) malloc(buf_size * sizeof(long int));
    int max_writes = 14; 
    int writes = 0;
    int offset = 0;

    fill(buffer, buf_size);

    while (max_writes - writes) {
        if (!buffer[127]) {
            fill(buffer, buf_size);
        }

        for (int i = 0; i < sizeof(long int); ++i) {
            if ((((long int) &buffer[offset] >> i) & 0xff) == (*(((char*) &strb) + writes))) {
                printf("0x%02x address 0x%016lx (shifted %d to 0x%016lx)\n", (unsigned char) (((long int) &buffer[offset] >> i) & 0xff), (long int) &buffer[offset], i, (long int) &buffer[offset] >> i); 
                *(p_buff + writes) = ((long int) &buffer[offset] >> i) & 0xff; 
                buffer[offset] = 0;
                ++writes;
                break;
            }
        }

        ++offset;
        offset %= buf_size;
    }

    free(buffer);
    printf("%s", p_buff);
    free(p_buff);

    return 0;
}
