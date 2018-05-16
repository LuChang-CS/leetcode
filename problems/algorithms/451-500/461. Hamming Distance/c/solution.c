#include <stdio.h>

int hammingDistance(int x, int y) {
    int mask = x ^ y;  // xor operation
    int number = 0;
    while (mask > 0) {
        number += mask & 1;  // fetch the last bit
        mask >>= 1;  // shift operation
    }
    return number;
}

int main() {
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}
