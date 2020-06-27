#include <stdio.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for (int* s = nums + 1; s < nums + numsSize; s += 1) {
        *s += *(s - 1);
    }
    return nums;
}

int main() {
    int nums[] = { 1, 2, 3, 4 };
    int returnSize;
    int *result = runningSum(nums, 4, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
}
