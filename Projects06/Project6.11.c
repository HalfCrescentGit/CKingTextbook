#include <stdio.h>

int main() {
    float e, denom;
    int n, i;

    printf("Enter an accuracy number: ");
    scanf("%d", &n);

    for (e = 1; n > 0; n--) {
        for (i = n, denom = 1; i > 0; i--)
            denom = denom * i;
        e += (1 / denom);
    }

    printf("e is approximately: %f", e);

    return 0;
}