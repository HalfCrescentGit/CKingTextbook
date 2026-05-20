#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LEN 100

int main(void) {
    char message[LEN], ch;
    int length;
    char *p = message, *q;
    bool palindrome = true;

    printf("Enter a message: ");
    while(ch != '\n') {
        ch = tolower(getchar());

        if (('a' <= ch) && (ch <= 'z'))
            *p++ = ch;
    }

    length = p - message;
    char reverse[length];
    p--;
    q = reverse;

    while(q - reverse < length) {
        *q++ = *p--;
    }

    for (p = message, q = reverse; p - message < length; p++, q++) {
        if (*p != *q) {
            palindrome = false;
        }
    }

    if (palindrome)
        printf("Palindrome");
    else
        printf("Not a palindrome");
}
