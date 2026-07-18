//Replace spaces in a string with '%20'
#include <stdio.h>
void url_encode(char *str, int true_length) {
    int spaces = 0;
    //Count spaces
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            spaces++;
        }
    }
    // Calculate new length
    int new_length = true_length + spaces * 2;
    // Perform URL encoding
    for (int i = true_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[new_length - 1] = '0';
            str[new_length - 2] = '2';
            str[new_length - 3] = '%';
            new_length -= 3;
        } else {
            str[new_length - 1] = str[i];
            new_length--;
        }
    }
}

int main() {
    char str[] = "Hello World  ";
    printf("Original: %s\n", str);
    url_encode(str, 11);
    printf("Encoded: %s\n", str);
    return 0;
}