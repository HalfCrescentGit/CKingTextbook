#include <stdio.h>

int main() {
    int num, denom, numResult, denomResult, x, y, rem;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denom);

    for (x = num, y = denom; y > 0; x = y, y = rem)
        rem = x % y;

    numResult = num / x;
    denomResult = denom / x;
    printf("In lowest terms: %d/%d", numResult, denomResult);

    return 0;
}