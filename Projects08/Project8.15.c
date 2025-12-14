#include <stdio.h>
#define LEN 80

int main() {
    char msg[LEN], ch;
    int i, n, len;

    printf("Enter message to be encrypted: ");
    for (i = 0, len = 0; i < LEN; i++, len++) {
        ch = getchar();
        if (ch == '\n')
            break;
        msg[i] = ch;
    }

    char encrypt[len];

    for (i = 0; i < len; i++)
        encrypt[i] = msg[i];

    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);

    for (i = 0; i < len; i++) {
        if ((encrypt[i] - 'A' < 26) && (encrypt[i] - 'A' >= 0))
            encrypt[i] = ((encrypt[i] - 'A') + n) % 26 + 'A';
        else if ((encrypt[i] - 'a' < 26) && (encrypt[i] - 'a' >= 0))
            encrypt[i] = ((encrypt[i] - 'a') + n) % 26 + 'a';
    }

    for (i = 0; i < len; i++)
        putchar(encrypt[i]);

    return 0;
}