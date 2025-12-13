#include <stdio.h>
#include <stdbool.h>

int main() {
    int digit, digit_seen[10] = {0};
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    printf("Digit: \t\t");
    for (digit = 0; digit < 10; digit++)
        printf(" %d", digit);

    printf("\nOccurences: \t");
    for (digit = 0; digit < 10; digit++)
        printf(" %d", digit_seen[digit]);

    return 0;
}