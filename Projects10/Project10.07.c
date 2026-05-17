#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 10

bool segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};
char digits[3][MAX_DIGITS * 4];

void clearDigitsArray(void);
void processDigit(int digit, int position);
void printDigitsArray(void);

int main(void) {
    int ch, digit, position;

    clearDigitsArray();
    printf("Enter a number: ");

    position = 0;
    while (position < MAX_DIGITS) {
        scanf("%1c", &ch);
        if (ch == '\n')
            break;
        else if (ch >= '0' && ch <= '9') {
            digit = ch - '0';
            position++;
            processDigit(digit, position);
        }
    }

    printDigitsArray();
}

void clearDigitsArray(void) {
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
}

void processDigit(int digit, int position) {
    if (segments[digit][0]) digits[0][position * 4 - 3] = '_';
    if (segments[digit][1]) digits[1][position * 4 - 2] = '|';
    if (segments[digit][2]) digits[2][position * 4 - 2] = '|';
    if (segments[digit][3]) digits[2][position * 4 - 3] = '_';
    if (segments[digit][4]) digits[2][position * 4 - 4] = '|';
    if (segments[digit][5]) digits[1][position * 4 - 4] = '|';
    if (segments[digit][6]) digits[1][position * 4 - 3] = '_';
}

void printDigitsArray(void) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < MAX_DIGITS * 4; j++)
            printf("%c", digits[i][j]);
        printf("\n");
    }
}