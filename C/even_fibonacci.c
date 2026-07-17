#include <stdio.h>
//Brute Force : O(n) Time and O(1) Space
int bruteForceEvenFibonacci (int n) {
    int a = 0, b = 1, c;
    int sum = 0;
    while (a <= n) {
        if (a % 2 == 0) {
            sum += a;
        }
        c = a + b;
        a = b;
        b = c;
    }
    return sum;
}

//Optimised Approach : O(log n) Time and O(1) Space
int optimizedEvenFibonacci (int n) {
    if ( n < 2) {
        return 0;
    }
    int e1 = 2, e2 = 8, e3, sum = 0;
    while (e1 <= n) {
        sum += e1;
        e3 = 4 * e2 + e1;
        e1 = e2;
        e2 = e3;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter n : ");
    scanf("%d", &n);

    printf("Brute Force Sum = %d\n", bruteForceEvenFibonacci(n));
    printf("Optimized Sum = %d\n", optimizedEvenFibonacci(n));

    return 0;
}