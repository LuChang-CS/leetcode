#include <stdio.h>

int distributeCandies(int* candies, int candiesSize) {
    char cats[200001] = { 0 };
    int cat_number = 0;
    int max = candiesSize >> 1;
    for (int i = 0; i < candiesSize; ++i) {
        int cat = candies[i] + 100000;
        if (cats[cat] == 0) {
            cats[cat] = '1';
            ++cat_number;
            if (cat_number >= max) return max;
        }
    }
    return cat_number;
}

int main() {
    int candies[] = { 1, 1, 2, 2, 3, 3 };
    printf("%d\n", distributeCandies(candies, 6));
    return 0;
}
