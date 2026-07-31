#include<stdio.h>
int fitBits(int x, int n) {
    int shift = 32 + (~n + 1);
    return !(((x << shift) >> shift) ^ x);
}
int main() {
    int number1, number2;
    printf("Enter 2 numbers : ");
    scanf("%d %d", &number1, &number2);
    printf("%d",fitBits(number1, number2));
    return 0;
}