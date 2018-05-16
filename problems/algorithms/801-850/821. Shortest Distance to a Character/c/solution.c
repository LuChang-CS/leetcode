#include <stdio.h>
#include <stdlib.h>

int* shortestToChar(char* S, char C, int* returnSize) {
    char c;
    int str_length = 0;
    int positions[10000];
    int count = 0;
    // find the positions of specified character
    for (int i = 0; (c = S[i]) != '\0'; ++i) {
        if (c == C) positions[count++] = i;
        ++str_length;
    }
    int *result = (int *)malloc(str_length * sizeof(int));
    int start = 0, end;
    for (int i = 0; i < count - 1; ++i) {
        int position = positions[i];
        end = (position + positions[i + 1]) / 2;
        // range from the previous middle boundary to the next one
        for (int k = start; k <= end; ++k) {
            int diff = k - position;
            result[k] = diff < 0 ? -diff : diff;
        }
        start = end + 1;
    }
    end = str_length - 1;
    int position = positions[count - 1];
    // remaining element
    for (int k = start; k <= end; ++k) {
        int diff = k - position;
        result[k] = diff < 0 ? -diff : diff;
    }
    *returnSize = str_length;
    return result;
}

int main() {
    int returnSize;
    char *S = "loveleetcode";
    char C = 'e';
    int *result = shortestToChar(S, C, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    getchar();
    return 0;
}
