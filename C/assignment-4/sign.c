#include<stdio.h>
int sign(int x) {
    return (x >> 31) | (!!x);
}
int main() {
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);
    printf("%d",sign( number));
    return 0;
}