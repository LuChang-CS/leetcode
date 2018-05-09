#include <stdio.h>
#include <stdlib.h>

int countBattleships(char** board, int boardRowSize, int boardColSize) {
    int count = 0;
    for (int m = 0; m < boardRowSize; ++m) {
        for (int n = 0; n < boardColSize; ++n) {
            if ((board[m][n] == 'X')  // the point is an element of a ship
                && (m == 0 || board[m - 1][n] != 'X')  // and it is the head
                && (n == 0 || board[m][n - 1] != 'X')) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    char **board = (char **)malloc(3 * 4 * sizeof(char));
    board[0] = "X..X";
    board[1] = "...X";
    board[2] = "...X";
    printf("%d\n", countBattleships(board, 3, 4));
    return 0;
}
