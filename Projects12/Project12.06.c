#include <stdio.h>

#define N 10

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void) {
    int a[N], *low = a, *high;

    printf("Enter %d numbers to be sorted: ", N);
    for (high = a; high < a + N; high++)
        scanf("%d", high);

    quicksort(a, low, high - 1);

    printf("In sorted order: ");
    for (high = a; high < a + N; high++)
        printf("%d ", *high);
    printf("\n");
}

void quicksort(int a[], int *low, int *high) {
    int *middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int *split(int a[], int *low, int *high) {
    int partElement = *low;

    for (;;) {
        while (low < high && partElement <= *high)
            high--;
        if (low >= high) break;
        *low++ = *high;

        while (low < high && *low <= partElement)
            low++;
        if (low >= high) break;
        *high-- = *low;
    }

    *high = partElement;
    return high;
}