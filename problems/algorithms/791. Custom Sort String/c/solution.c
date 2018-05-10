#include <stdio.h>
#include <stdlib.h>

char* customSortString(char* S, char* T) {
    int appearance[26] = { 0 };
    int counts[26] = { 0 };
    char extra_letters[200];
    int extra_letters_count = 0;
    char c;
    // find which letters appear in S
    for (int i = 0; (c = S[i]) != '\0'; ++i) {
        appearance[c - 'a'] = 1;
    }
    // count the frequency of T
    for (int i = 0; (c = T[i]) != '\0'; ++i) {
        if (appearance[c - 'a'] == 0) extra_letters[extra_letters_count++] = c;
        else ++counts[c - 'a'];
    }
    int len = 0;
    // reconstruct T according to the order in S
    for (int i = 0; (c = S[i]) != '\0'; ++i) {
        int count = counts[c - 'a'];
        for (int k = 0; k < count; ++k) {
            T[len++] = c;
        }
    }
    // append the letters not appeared in S
    for (int i = 0; i < extra_letters_count; ++i) {
        T[len++] = extra_letters[i];
    }
    return T;
}

int main() {
    char S[] = "cba";
    char T[] = "abcd";
    printf("%s\n", customSortString(S, T));
    return 0;
}
