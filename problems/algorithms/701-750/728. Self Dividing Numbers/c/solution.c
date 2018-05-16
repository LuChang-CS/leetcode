#include <stdio.h>
#include <stdlib.h>

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int *results = (int *)malloc((right - left + 1) * sizeof(int));
    int count = 0;
    for (int i = left; i <= right; ++i) {
        int number = i;
        int flag = 1;
        while (number > 0) {
            // fetch each digits
            int digit = number % 10;
            // contains 0 or cannot be divided
            if (digit == 0 || i % digit != 0) {
                flag = 0;
                break;
            }
            // shift right in hex mode
            number /= 10;
        }
        if (flag == 1) {
            results[count++] = i;
        }
    }
    *returnSize = count;
    return results;
}

int main() {
    int returnSize = 0;
    int *result = selfDividingNumbers(1, 22, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    return 0;
}
