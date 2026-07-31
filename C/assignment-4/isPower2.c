#include<stdio.h>
int isPower2(int x) {
    return !(x & (x + ~0)) & !!x & !(x >> 31);
    
    // return (number > 0) && ((number & (number - 1)) == 0);

    // if ((number & (number - 1)) == 0)
    //     return 1;
    // else return 0;
}
int main() {
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);
    printf("%d",isPower2(number));
    return 0;
}