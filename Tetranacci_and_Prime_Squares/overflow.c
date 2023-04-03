#include "overflow.h"
#include <stdio.h>
#include <stdint.h>

uint64_t max_tetranacci() {
    int i = 4;
    uint64_t tn_1 = 0;
    uint64_t tn_2 = 0;
    uint64_t tn_3 = 0;
    uint64_t tn_4 = 1;
    
    while (1) {
        uint64_t tn = tn_1 + tn_2 + tn_3 + tn_4;
        tn_1 = tn_2;
        tn_2 = tn_3;
        tn_3 = tn_4;
        tn_4 = tn;
        if (tn > UINT64_MAX / 2) { // check for overflow
            /*printf("Overflow at n = %llu\n", n);*/
            return i;
        }
        i = i + 1;
    }
}
