#include <stdio.h>
#define LEN 50

int main() {
    char term, sentence[LEN];
    char *p;
    int space, len;

    printf("Enter a sentence: ");

    for (p = sentence; p - sentence < LEN; p++) {
        scanf("%c", p);
        if ((*p == '.') || (*p == '?') || (*p == '!')) {
            term = *p;
            break;
        }
    }

    len = p - sentence;

    printf("Reversal of sentence:");

    for (p--; p >= sentence; p--) {
        if ((*p == ' ') || (p == sentence)) {
            if (p == sentence)
                printf(" ");
            for (space = p - sentence; space < len; space++)
                printf("%c", sentence[space]);
            len = p - sentence;
        }
    }
    printf("%c", term);

    return 0;
}