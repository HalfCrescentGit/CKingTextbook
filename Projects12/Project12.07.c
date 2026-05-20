#include <stdio.h>

#define N 10

void maxMin(int a[], int n, int *max, int *min);

int main(void) {
    int b[N], *p, big, small;

    printf("Enter %d numbers: ", N);
    for (p = b; p < b + N; p++)
        scanf("%d", p);

    maxMin(b, N, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);
}

void maxMin(int a[], int n, int *max, int *min) {
    int *p;

    for (*max = *min = *a, p = a + 1; p < a + n; p++) {
        if (*p > *max)
            *max = *p;
        else if (*p < *min)
            *min = *p;
    }
}