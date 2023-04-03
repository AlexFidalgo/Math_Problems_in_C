#include <stdio.h>
#include <stdint.h>

uint64_t tetranacci(uint64_t n) {
    if (n == 0 || n == 1 || n == 2) {
        return 0;
    }
    if (n == 3) {
        return 1;
    }
    uint64_t tn_1 = 0;
    uint64_t tn_2 = 0;
    uint64_t tn_3 = 0;
    uint64_t tn_4 = 1;
    for (uint64_t i = 4; i <= n; i++) {
        uint64_t tn = tn_1 + tn_2 + tn_3 + tn_4;
        tn_1 = tn_2;
        tn_2 = tn_3;
        tn_3 = tn_4;
        tn_4 = tn;
        if (tn > UINT64_MAX / 2) { // check for overflow
            printf("Overflow at n = %llu\n", n);
            return UINT64_MAX;
        }
    }
    return tn_4;
}

int main() {
    uint64_t n = 0;
    while (tetranacci(n) <= UINT64_MAX / 2) {
        n++;
    }
    printf("The smallest n whose tetranacci does not exceed 2^64-1 is %llu\n", n);
    return 0;
}
