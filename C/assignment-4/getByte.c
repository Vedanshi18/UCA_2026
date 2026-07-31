#include<stdio.h>
int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}
int main() {
    int number, byte;
    printf("Enter number and byte : ");
    scanf("%x %d", &number, &byte);
    printf("%x",getByte(number, byte));
    return 0;
}