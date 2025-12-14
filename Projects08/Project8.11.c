#include <stdio.h>
#include <ctype.h>
#define LEN 15

int main() {
    char number[LEN];
    int i;

    printf("Enter a phone number: ");

    for (i = 0; i < LEN; i++)
        number[i] = toupper(getchar());

    for (i = 0; i < LEN; i++) {
        switch (number[i]) {
            case 'A': case 'B': case 'C': number[i] = '2'; break;
            case 'D': case 'E': case 'F': number[i] = '3'; break;
            case 'G': case 'H': case 'I': number[i] = '4'; break;
            case 'J': case 'K': case 'L': number[i] = '5'; break;
            case 'M': case 'N': case 'O': number[i] = '6'; break;
            case 'P': case 'R': case 'S': number[i] = '7'; break;
            case 'T': case 'U': case 'V': number[i] = '8'; break;
            case 'W': case 'X': case 'Y': number[i] = '9'; break;
        }
    }

    printf("In numeric form: ");
    for (i = 0; i < LEN; i++)
        printf("%c", number[i]);

    return 0;
}