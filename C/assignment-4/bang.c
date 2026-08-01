#include<stdio.h>
int bang(int x) {
    return ((x | -x) >> 31) + 1;
}
int main() {
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);
    printf("%d",bang( number));
    return 0;
}