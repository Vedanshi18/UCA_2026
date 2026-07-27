#include <stdio.h>

// This is a single-line comment

int main()
{
    int a = 10;      // Variable declaration
    int b = 20;
    /* This is a 
    multi-line
       comment */
    printf("Hello World!\n");
    printf("This is not a comment: // Hello\n");
    printf("This is also not a comment: /* Hi */\n");

    char ch = 'A';
    char slash = '/';
    char quote = '\'';
    int c = a / b;

    printf("Result = %d\n", c);

    // End of program
    return 0;
}