#include <stdio.h>
#define PI 3.14159265358972f

int main() {
    float r, v;

    printf("What is the radius of the sphere? ");
    scanf("%f", &r);

    v = (4.0f / 3.0f) * PI * r * r * r;
    printf("%f", v);

    return 0;
}