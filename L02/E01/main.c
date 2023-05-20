#include <stdio.h>

int main() {
    int A, B, temp;
    printf("Enter first positive integer: ");
    scanf(" %d", &A);
    printf("Enter second positive integer: ");
    scanf(" %d",&B);

    while (B != 0) {
        temp = B;
        B = A % B;
        A = temp;
    }

    printf("GCF = %d\n", A);
    return 0;
}
