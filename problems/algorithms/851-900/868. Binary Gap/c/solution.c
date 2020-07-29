#include <stdio.h>
#include <stdlib.h>

int binaryGap(int N) {
    while ((N & 1) == 0) N >>= 1;
    N >>= 1;
    int max_gap = 0;
    int current_gap = 0;
    while (N > 0) {
        current_gap += 1;
        if (N & 1) {
            if (current_gap > max_gap) {
                max_gap = current_gap;
            }
            current_gap = 0;
        }
        N >>= 1;
    }
    return max_gap;
}

int main() {
    int N = 22;
    int max_gap = binaryGap(N);
    printf("%d\n", max_gap);
    return 0;
}

