#include <stdio.h>
#include <stdbool.h>

bool judgeCircle(char* moves) {
    int x = 0, y = 0;
    char move;
    for (int i = 0; (move = moves[i]) != '\0'; ++i) {
        switch (move) {
        case 'U':
            y += 1;
            break;
        case 'D':
            y -= 1;
            break;
        case 'R':
            x += 1;
            break;
        case 'L':
            x -= 1;
            break;
        default:
            break;
        }
    }
    return (x == 0 && y == 0);
}

int main() {
    char *moves = "UD";
    printf("%d", judgeCircle(moves));
    return 0;
}
