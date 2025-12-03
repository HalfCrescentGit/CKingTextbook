#include <stdio.h>

int main() {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    printf("The reversal is: ");

    do {
        printf("%d", x % 10);
        x /= 10;
    } while (x > 0);
    
    return 0;
}