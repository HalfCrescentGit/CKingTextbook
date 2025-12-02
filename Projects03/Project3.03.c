#include <stdio.h>

int main() {
    int GS1, groupId, pubCode, itemNo, check;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &GS1, &groupId, &pubCode, &itemNo, &check);

    printf("GS1 prefix: %d\n", GS1);
    printf("Group identifier: %d\n", groupId);
    printf("Publisher code: %d\n", pubCode);
    printf("Item number: %d\n", itemNo);
    printf("Check digit: %d\n", check);

    return 0;
}