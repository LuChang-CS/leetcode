#include <stdio.h>
#include <stdlib.h>

int arrayPairSum(int* nums, int numsSize) {
    int distinct_nums[20001] = { 0 };
    for (int i = 0; i < numsSize; ++i) {
        ++distinct_nums[nums[i] + 10000];
    }
    int result = 0;
    // flag to record the count of element is odd or even
    int flag = 0;
    // previous element
    int prev;
    for (int i = 0, x = -10000; i <= 20000; ++i, ++x) {
        int count = distinct_nums[i];
        if (count == 0) continue;
        // last count is even
        if (flag == 0) {
            result += x * (count >> 1);
            // remaining element
            if ((count & 1) == 1) {
                flag = 1;
                prev = x;
            } else {
                flag = 0;
            }
        } else {  // last count is odd
            int a = count & 1;
            result += x * ((count - 1) >> 1) + prev;
            // remaining element
            if ((count & 1) == 0) {
                flag = 1;
                prev = x;
            } else {
                flag = 0;
            }
        }
    }
    return result;
}

int main() {
    int nums[] = { 1, 2, 3, 2 };
    arrayPairSum(nums, 4);
    getchar();
    return 0;
}
