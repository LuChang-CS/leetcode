#include <stdio.h>
#include <stdlib.h>

int* countBits(int num, int* returnSize) {
    int size = num + 1;
    int *result = (int *)malloc(size * sizeof(int));
    result[0] = 0;
    for (int i = 1; i <= num; ++i) {
        // the last bit and right shift
        result[i] = (i & 1) + result[i >> 1];
    }
    *returnSize = size;
    return result;
}

int main() {
    int returnSize;
    int *result = countBits(5, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    return 0;
}
