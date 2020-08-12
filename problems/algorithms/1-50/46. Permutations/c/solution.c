#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* nums, int s, int e) {
    int t = nums[s];
    nums[s] = nums[e];
    nums[e] = t;
}

void fill(int* nums, int s, int numsSize, int** results, int* cur) {
    if (s >= numsSize - 1) {
        // reach the last element.
        memcpy(results[(*cur)++], nums, numsSize * sizeof(int));
    } else {
        // keep the first element and generate the remaining array.
        fill(nums, s + 1, numsSize, results, cur);
        for (int e = s + 1; e < numsSize; ++e) {
            // swap the first with every other element and generate the remaining array.
            swap(nums, s, e);
            fill(nums, s + 1, numsSize, results, cur);
            // swap back
            swap(nums, s, e);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int n = 1;
    for (int i = 1; i <= numsSize; ++i) n *= i;
    *returnSize = n;
    *returnColumnSizes = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) (*returnColumnSizes)[i] = numsSize;
    int** results = (int**) malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        results[i] = (int*) malloc(sizeof(int) * numsSize);
    }
    int cur = 0;
    fill(nums, 0, numsSize, results, &cur);
    return results;
}

int main() {
    int nums[] = { 1, 2, 3, 4, 5 };
    int numsSize = 5;
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int** results = permute(nums, numsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d ", results[i][j]);
        }
        printf("\n");
    }
}
