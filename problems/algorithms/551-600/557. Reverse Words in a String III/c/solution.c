#include <stdio.h>

char* reverseWords(char* s) {
    char word[100];
    char c;
    int word_len = 0;
    int s_len = 0;
    for (int i = 0; (c = s[i]) != '\0'; ++i) {
        if (c == ' ') {  // found space
            for (int k = word_len - 1; k >= 0; --k) {
                // reverse word
                s[s_len++] = word[k];
            }
            s[s_len++] = ' ';
            word_len = 0;
        }
        else {
            word[word_len++] = c;
        }
    }
    // remaining word
    for (int k = word_len - 1; k >= 0; --k) {
        s[s_len++] = word[k];
    }
    return s;
}

int main() {
    char s[] = "Let's take LeetCode contest";
    printf("%s", reverseWords(s));
    return 0;
}
