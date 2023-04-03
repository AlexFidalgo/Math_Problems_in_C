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

int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
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
        }
        printf("Enter the number: ");
        scanf("%d", &n);
    }
    printf("Bye\n");
    return 0;
}
