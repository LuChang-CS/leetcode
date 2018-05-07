#include <stdio.h>
#include <stdlib.h>

int* partitionLabels(char* S, int* returnSize) {
    int letter_last_pos[26];
    char c;
    // record each letter's last position
    for (int i = 0; (c = S[i]) != '\0'; ++i) {
        letter_last_pos[c - 'a'] = i;
    }
    int end;
    int *result = (int *)malloc(26 * sizeof(int));
    int size = 0;
    for (int i = 0; (c = S[i]) != '\0';) {
        // i is the start part, we need to find the end of this part
        end = letter_last_pos[c - 'a'];
        // compare the end of each letter with current end
        for (int j = i + 1; j < end; ++j) {
            int new_end = letter_last_pos[S[j] - 'a'];
            if (new_end > end) end = new_end;
        }
        result[size++] = end - i + 1;
        // move to next part
        i = end + 1;
    }
    *returnSize = size;
    return result;
}

int main() {
    int returnSize;
    char *S = "ababcbacadefegdehijhklij";
    int *result = partitionLabels(S, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    return 0;
}
