#include<stdio.h>
int fitBits(int x, int n) {
    int shift = 32 + (~n + 1);
    return !(((x << shift) >> shift) ^ x);
}
int main() {
    int number, bits;
    printf("Enter number and bits : ");
    scanf("%d %d", &number, &bits);
    printf("%d",fitBits(number, bits));
    return 0;
}