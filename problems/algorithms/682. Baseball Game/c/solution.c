#include <stdio.h>
#include <stdlib.h>

int calPoints(char** ops, int opsSize) {
    int round[1000];
    int top = -1;
    int sum = 0;
    for (int i = 0; i < opsSize; ++i) {
        char *operation = ops[i];
        char op = operation[0];
        if ((op >= '0' && op <= '9') || (op == '-')) {
            // string integer to int
            int score = atoi(operation);
            sum += score;
            round[++top] = score;
        } else if (op == '+') {
            // top 2 elements in the stack
            int score = round[top] + round[top - 1];
            sum += score;
            round[++top] = score;
        } else if (op == 'D') {
            // double
            int score = round[top] << 1;
            sum += score;
            round[++top] = score;
        } else {
            // pop
            int score = -round[top--];
            sum += score;
        }
    }
    return sum;
}

int main() {
    char **ops = (char **)malloc(5 * sizeof(char *));
    ops[0] = (char *)"5";
    ops[1] = (char *)"2";
    ops[2] = (char *)"C";
    ops[3] = (char *)"D";
    ops[4] = (char *)"+";
    printf("%d\n", calPoints(ops, 5));
    return 0;
}
