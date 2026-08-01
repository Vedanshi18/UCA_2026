#include <stdio.h>
int conditional(int x, int y, int z) {
    int mask = ~!!x + 1;
    return (y & mask) | (z & ~mask);
}
int main() {
    int x, y, z;
    printf("Enter three numbers (x, y, z): ");
    scanf("%d %d %d", &x, &y, &z);
    printf("%d", conditional(x, y, z));
    return 0;
}