#include <stdio.h>

int main() {
    int n, i, j, count;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    int square[n][n], rowSums[n], colSums[n], diagSums[2] = {0, 0};

    for (i = 0; i < n; i++) {
        rowSums[i] = 0;
        colSums[i] = 0;
        for (j = 0; j < n; j++)
            square[i][j] = 0;
    }

    i = 0;
    j = n / 2;
    square[i][j] = 1;

    for (count = 2; count <= n * n; count++) {
        if (square[(i - 1 + n) % n][(j + 1) % n] == 0) {
            square[(i - 1 + n) % n][(j + 1) % n] = count;
            i = (i - 1 + n) % n;
            j = (j + 1) % n;
        }
        else if (square[(i + 1) % n][j] == 0) {
            square[(i + 1) % n][j] = count;
            i = (i + 1) % n;
        }
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            rowSums[i] += square[i][j];

    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
            colSums[j] += square[i][j];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            if (i == j)
                diagSums[0] += square[i][j];
            if (i + j == n - 1)
                diagSums[1] += square[i][j];
        }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%5d", square[i][j]);
        printf("\n");
    }
    printf("Row sums:\t");
    for (i = 0; i < n; i++)
        printf("%5d", rowSums[i]);
    printf("\nColumn sums:\t");
    for (i = 0; i < n; i++)
        printf("%5d", colSums[i]);
    printf("\nDiagonal sums:\t");
    for (i = 0; i < 2; i++)
        printf("%5d", diagSums[i]);

    return 0;
}