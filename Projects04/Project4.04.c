#include <stdio.h>

int main() {
    int x, oct0, oct1, oct2, oct3, oct4;

    printf("Enter an integer between 0 and 32767: ");
    scanf("%d", &x);

    oct0 = x % 8; x/= 8;
    oct1 = x % 8; x/= 8;
    oct2 = x % 8; x/= 8;
    oct3 = x % 8; x/= 8;
    oct4 = x % 8;

    printf("In octal, your number is: %d%d%d%d%d", oct4, oct3, oct2, oct1, oct0);

    return 0;
}