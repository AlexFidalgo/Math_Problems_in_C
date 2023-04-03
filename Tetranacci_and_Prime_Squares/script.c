#include "overflow.h"
#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int tetranacci_dynamic_programming(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return 0;
    }
    if (n == 3) {
        return 1;
    }
    int tetra[n+1];
    tetra[0] = tetra[1] = tetra[2] = 0;
    tetra[3] = 1;
    for (int i = 4; i <= n; i++) {
        tetra[i] = tetra[i-1] + tetra[i-2] + tetra[i-3] + tetra[i-4];
    }
    return tetra[n];
}

int main() {
    int n;
    uint64_t n_uint64_t;
    printf("Enter the number: ");
    scanf("%d", &n);
    n_uint64_t = (uint64_t) n;
    while (n != 0) {
        int count = 0;
        int end = 0;
        int v[4];
        int found = 0;
        for (int i = 2; end < sqrt(n); i++) {
            if (is_prime(i)) {
                v[count] = i;
                count++;
            }
            if (count == 4) {
                if (round(pow(v[0], 2)) + round(pow(v[1], 2)) + round(pow(v[2], 2)) + round(pow(v[3], 2)) ==  n) {
                    printf("%d = %d^2 + %d^2 + %d^2 + %d^2\n", n, v[0], v[1], v[2], v[3]);
                    if (n_uint64_t <= max_tetranacci()) {
                        printf("Tetranacci of %d = %d\n", n, tetranacci_dynamic_programming(n));
                    }
                    else {
                        printf("Tetrannci of %d is too large to be calculated\n", n);
                    }
                    found = 1;
                    break;
                }
                v[0] = v[1];
                v[1] = v[2];
                v[2] = v[3];
                count--;
            }
            end ++;
        }
        if (found == 0) {
            printf("There are no 4 consecutive prime numbers whose squared values equal %d\n", n);
            if (n_uint64_t <= max_tetranacci()) {
                printf("Tetranacci of %d = %d\n", n, tetranacci_dynamic_programming(n));
            }
            else {
                printf("Tetrannci of %d is too large to be calculated\n", n);
            }
        }
        printf("Enter the number: ");
        scanf("%d", &n);
        n_uint64_t = (uint64_t) n;
    }
    printf("Bye\n");
    return 0;
}

/* To run from the terminal (assuming the file with the main function is called play.c): 
gcc -o play play.c overflow.c (-o specifies the output file name for the compiled program (play in this case))
play.exe (or .\play.exe)
*/
