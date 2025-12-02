#include <stdio.h>

int main() {
    int x, digit0, digit1;

    printf("Enter a two-digit number: ");
    scanf("%d", &x);

    digit0 = x % 10;
    digit1 = x / 10;

    printf("The reversal is: %d%d", digit0, digit1);

    return 0;
}