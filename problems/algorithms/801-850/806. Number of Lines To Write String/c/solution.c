#include <stdio.h>
#include <stdlib.h>

int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
    int current_line_width = 0;
    int line_number = 1;
    char c;
    for (int i = 0; (c = S[i]) != '\0'; ++i) {
        int width = widths[c - 'a'];
        // writing new words
        current_line_width = current_line_width + width;
        if (current_line_width > 100) {
            // break line and put this word to the new line
            current_line_width = width;
            ++line_number;
        }
    }
    *returnSize = 2;
    int *result = (int *)malloc(2 * sizeof(int));
    result[0] = line_number;
    result[1] = current_line_width;
    return result;
}

int main() {
    int widths[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    char S[] = "abcdefghijklmnopqrstuvwxyz";
    int returnSize;
    int *result = numberOfLines(widths, 26, S, &returnSize);
    printf("%d %d", result[0], result[1]);
}
