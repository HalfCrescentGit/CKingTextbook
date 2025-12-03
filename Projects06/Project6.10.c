#include <stdio.h>

int main()
{
    int m, d, y, smallM, smallD, smallY;
    m = d = y = 1;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &smallM, &smallD, &smallY);

    for (;;) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &m, &d, &y);
        if (m + d + y == 0)
            break;
        if (y < smallY || (y == smallY && m < smallM) || (y == smallY && m == smallM && d < smallD)) {
            smallY = y;
            smallM = m;
            smallD = d;
        }
    }
    
    printf("%.2d/%.2d/%d is the earliest date", smallM, smallD, smallY);
    
    return 0;
}