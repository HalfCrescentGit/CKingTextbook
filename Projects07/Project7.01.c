#include <stdio.h>

int main() {
    int i, n; //int fails when n/i reaches 46,340. 46340^2 = 2,147,395,600, roughly equal to 2^31, 32-bit signed int.
    //short i, n; //short fails when n/i reaches 181. 181^2 = 32,761, roughly equal to 2^15, 16-bit signed int.
    //long i, n; //long fails when n/i reaches 46,340, same as int, 32-bit singed int.

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        printf("%20d%20d\n", i, i * i);
    }

    return 0;
}