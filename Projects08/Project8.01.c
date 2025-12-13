#include <stdio.h>
#include <stdbool.h>

int main() {
    bool digit_seen[10] = {false}, digit_repeated[10] = {false}, any;
    int digit, i;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit])
            digit_repeated[digit] = true;
        digit_seen[digit] = true;
        n /= 10;
    }

    for (i = 0; i < 10; i++)
        if (digit_repeated[i])
            any = true;

    if (!any)
        printf("No repeated digit\n");
    else
        printf("Repeated digit(s):");

    for (i = 0; i < 10; i++)
        if (digit_repeated[i] == true)
            printf(" %d", i);

    return 0;
}