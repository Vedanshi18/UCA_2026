#include<stdio.h>
int bitXor(int x, int y) {
    return ~(~(~x & y) & ~(x & ~y));
}
int main() {
    int number1, number2;
    printf("Enter 2 numbers : ");
    scanf("%d %d", &number1, &number2);
    printf("%d",bitXor(number1, number2));
    return 0;
}