#include <stdio.h>

int main() {
    int y, m, d, itemNo;
    float price;

    printf("Enter item number: ");
    scanf("%d", &itemNo);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    printf("Item\tUnit\tPurchase\n\tPrice\tDate\n%d\t$ %.2f\t%.2d/%.2d/%4d\n", itemNo, price, m, d, y);

    return 0;
}