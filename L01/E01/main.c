#include <stdio.h>
int main(void)
{
    int x, y;
    float z;
    printf("Insert an integer number:");
    scanf("%d", &x);
    y = 6;
    z = (float)(x)/y;
    printf("%d/%d=%.4f\n", x, y, z);
    return 0;
}