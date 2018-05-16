#include <stdio.h>
#include <string.h>

char* reverseString(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; ++i) {
        // swap
        char t = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = t;
    }
    return s;
}

int main() {
    char s[] = "hello";
    printf("%s\n", reverseString(s));
    return 0;
}