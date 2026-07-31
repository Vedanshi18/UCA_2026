#include<stdio.h>
int logicalShift(int x, int n) {
    int mask = ~(~0 << (33 + ~n));
    return (x >> n) & mask;
}
int main() {
    int number, bits;
    printf("Enter number and bits : ");
    scanf("%x %d", &number, &bits);
    printf("0x%x",logicalShift(number, bits));
    return 0;
}