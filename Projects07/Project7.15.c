#include <stdio.h>

int main() {
    //short n, factorial = 1;       //n gives valid n! value up to n = 7
    int n, factorial = 1;       //n gives valid n! value up to n = 12
    //long n, factorial = 1;     //n gives valid n! value up to n = 12
    //long long n, factorial = 1;     //n gives valid n! value up to n = 21
    //float n, factorial = 1;     //n gives valid n! value up to n = 34 (only approx. + beyond n = 34 gives inf value)
    //double n, factorial = 1;     //n gives valid n! value up to n = 170 (only approx. + beyond n = 170 gives inf value)
    //long double n, factorial = 1;     //n gives valid n! value up to n = 1754 (only approx. + beyond n = 170 gives inf value) 
                                        //also, long doubles don't seem to work, think its fault of mingw compiler.

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (int i = n; i > 0; i--) {
        factorial *= i;
    }

    printf("Factorial of %d: %d", n, factorial);

    return 0;
}