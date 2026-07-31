#include<stdio.h>
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}
int main() {
    int number1, number2;
    printf("Enter 2 numbers : ");
    scanf("%d %d", &number1, &number2);
    printf("%d",bitAnd(number1, number2));
    return 0;
}