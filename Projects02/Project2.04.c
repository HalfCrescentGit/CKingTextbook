#include <stdio.h>

int main() {
    float money;

    printf("Enter a dollar and cent amount: ");
    scanf("%f", &money);

    printf("Here it is with 5pc tax added: $%.2f", money * 1.05);

    return 0;
}