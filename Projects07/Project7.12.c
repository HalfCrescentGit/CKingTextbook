#include <stdio.h>

int main() {
    float expr1, expr2;
    char operand;

    printf("Enter an expression: ");
    scanf("%f", &expr1);

    for (;;) {
        operand = getchar();

        if (operand == '\n')
            break;
        
        scanf("%f", &expr2);

        switch (operand) {
            case '+': expr1 += expr2; break;
            case '-': expr1 -= expr2; break;
            case '*': expr1 *= expr2; break;
            case '/': expr1 /= expr2; break;
        }
    }

    printf("Value of expression: %g", expr1);

    return 0;
}