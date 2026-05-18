#include <stdio.h>

void payAmount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main() {
    int money, twenties, tens, fives, ones;
    int *p = &twenties; int *q = &tens; int *r = &fives; int *s = &ones;
    
    printf("Enter a dollar amount: ");
    scanf("%d", &money);
    payAmount(money, p, q, r, s);

    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", twenties, tens, fives, ones);

    return 0;
}

void payAmount(int money, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = money / 20;
    money -= *twenties * 20;
    *tens = money / 10;
    money -= *tens * 10;
    *fives = money / 5;
    money -= *fives * 5;
    *ones = money;
}