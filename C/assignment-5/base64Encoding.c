#include <stdio.h>
#include <string.h>
void base64Encoding (char input[]) {
    char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int len = strlen(input);
    for (int i = 0; i < len; i += 3) {
        int a = input[i];
        int b = (i + 1 < len) ? input[i + 1]: 0;
        int c = (i + 2 < len) ? input[i + 2]: 0;

        int first = a >> 2;
        int second = ((a & 3) << 4) | (b >> 4);
        int third = ((b & 15) << 2) | (c >> 6);
        int fourth = c & 63;

        printf("%c", base64[first]);
        printf("%c", base64[second]);
        if (i + 1 < len) printf("%c", base64[third]);
        else printf("=");
        if (i + 2 < len) printf("%c", base64[fourth]);
        else printf("=");
    }
}
int main() {
    char input[100];
    printf("Enter a string to encode in Base64: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
    base64Encoding(input);
    return 0;
}