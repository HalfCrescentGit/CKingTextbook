#include <stdio.h>

#define LEN 100

int main(void) {
    char input[LEN], ch;
    char *p = input;

    printf("Enter a message: ");

    for (;;) {
        ch = getchar();

        if (ch == '\n')
            break;
        else
            *p++ = ch;
    }

    printf("Reversal is: ");

    for (p--; p >= input; p--)
        printf("%c", *p);
}