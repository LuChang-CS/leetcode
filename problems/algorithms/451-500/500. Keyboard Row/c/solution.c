#include <stdio.h>
#include <stdlib.h>

char** findWords(char** words, int wordsSize, int* returnSize) {
    // row table of each letter from a to z
    int positions[] = { 1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2 };
    char **result = (char **)malloc(wordsSize * sizeof(char *));
    int count = 0;
    for (int i = 0; i < wordsSize; ++i) {
        char *word = words[i];
        char c = word[0];
        if (c < 'a') c += 32;  // uppercase
        int pos = positions[c - 'a'];
        for (int k = 1; (c = word[k]) != '\0'; ++k) {
            if (c < 'a') c += 32;
            // check if any letter is not in the same row as the first letter
            if (positions[c - 'a'] != pos) break;
        }
        if (c == '\0') result[count++] = word;
    }
    *returnSize = count;
    return result;
}

int main() {
    char **words = (char **)malloc(sizeof(char *) * 4);
    words[0] = (char *)"Hello";
    words[1] = (char *)"Alaska";
    words[2] = (char *)"Dad";
    words[3] = (char *)"Peace";
    int returnSize;
    char **result = findWords(words, 4, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s ", result[i]);
    }
    return 0;
}
