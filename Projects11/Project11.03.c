#include <stdio.h>

void reduce(int numerator, int denominator, int *reducedNumerator, int *reducedDenominator);

int main(void) {
    int num, denom, numResult, denomResult;
    int *numP = &numResult; int *denomP = &denomResult;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denom);

    reduce (num, denom, numP, denomP);
    
    printf("In lowest terms: %d/%d", numResult, denomResult);
}

void reduce (int numerator, int denominator, int *reducedNumerator, int *reducedDenominator) {
    int x, y, rem;

    for (x = numerator, y = denominator; y > 0; x = y, y = rem)
        rem = x % y;

    *reducedNumerator = numerator / x;
    *reducedDenominator = denominator / x;
}