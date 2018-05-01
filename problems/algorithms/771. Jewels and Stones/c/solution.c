#include <stdio.h>

int numJewelsInStones(char* J, char* S) {
    char j_letters[256] = { 0 };  // initialize an array to store letters in J
    char c;
    for (int i = 0; (c = J[i]) != '\0'; ++i) {
        j_letters[c] = 1;  // set j_letters[c] = 1 means c appears in J
    }
    int jewel_number = 0;  // number of jewels
    for (int i = 0; (c = S[i]) != '\0'; ++i) {
        jewel_number += j_letters[c];  // if c appears in J, then we add a number
    }
    return jewel_number;
}

int main() {
    /* We use the example to test the algorithm */
    char *J = "aA";
    char *S = "aAAbbbb";
    printf("%d\n", numJewelsInStones(J, S));
    return 0;
}
