#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COLS 10
#define N 0
#define E 1
#define S 2
#define W 3

int main() {
    int i, j, direction;
    char board[ROWS][COLS], ch = 'A';

    srand((unsigned) time(NULL));

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            board[i][j] = '.';

    i = 0;
    j = 0;
    board[i][j] = ch;

    for (; ch < 'Z';) {
        if ((board[i - 1][j] != '.' || i == 0) && (board[i][j + 1] != '.' || j == 9) && 
            (board[i + 1][j] != '.' || i == 9) && (board[i][j - 1] != '.' || j == 0))
            break;

        direction = rand() % 4;

        if (direction == N && board[i - 1][j] == '.' && i != 0) {
            board[i - 1][j] = ch + 1; i--; ch++;
        }
        else if (direction == E && board[i][j + 1] == '.' && j != 9) {
            board[i][j + 1] = ch + 1; j++; ch++;
        }
        else if (direction == S && board[i + 1][j] == '.' && i != 9) {
            board[i + 1][j] = ch + 1; i++; ch++;
        }
        else if (direction == W && board[i][j - 1] == '.' && j != 0) {
            board[i][j - 1] = ch + 1; j--; ch++;
        }
        else
            continue;
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
   
    return 0;
}