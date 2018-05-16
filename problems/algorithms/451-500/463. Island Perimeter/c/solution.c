#include <stdio.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int count = 0;
    for (int i = 0; i < gridRowSize; ++i) {
        int *row = grid[i];
        // not the top edge of matrix
        int not_border_top = i != 0;
        for (int j = 0; j < gridColSize; ++j) {
            if (row[j] == 1) {
                count += 4;
                // joint by the top land
                if (not_border_top && grid[i - 1][j] == 1) count -= 2;
                // joint by the left land
                if (j != 0 && row[j - 1] == 1) count -= 2;
            }
        }
    }
    return count;
}

int main() {
    int r1[] = { 0, 1, 0, 0 };
    int r2[] = { 1, 1, 1, 0 };
    int r3[] = { 0, 1, 0, 0 };
    int r4[] = { 1, 1, 0, 0 };
    int *count[] = { r1, r2, r3, r4 };
    printf("%d\n", islandPerimeter(count, 4, 4));
    return 0;
}
