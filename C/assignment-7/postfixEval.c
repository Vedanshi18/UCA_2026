#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char expression[100];
    int stack[100];
    int top = -1;

    fgets(expression, sizeof(expression), stdin);
    char *token = strtok(expression, " \n");
    while (token != NULL) {
        if (token[0] >= '0' && token[0] <= '9') {
            stack[++top] = atoi(token);
        }
        else {
            int b = stack[top--];
            int a = stack[top--];
            switch (token[0]) {
                case '+':
                    stack[++top] = a + b;
                    break;
                case '-':
                    stack[++top] = a - b;
                    break;
                case '*':
                    stack[++top] = a * b;
                    break;
                case '/':
                    stack[++top] = a / b;
                    break;
            }
        }
        token = strtok(NULL, " \n");
    }
    printf("%d\n", stack[top]);
}
