#include <stdio.h>

int main() {
    int digit0, digit1, digit2;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &digit2, &digit1, &digit0);

    printf("The reversal is: %d%d%d", digit0, digit1, digit2);

    return 0;
}