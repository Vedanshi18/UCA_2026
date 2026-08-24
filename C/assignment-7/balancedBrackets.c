#include <stdio.h>
#include <string.h>
int isBalanced(char expression[]) {
    char stack[100];
    int top = -1;
    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return 0;
            char topChar = stack[top--];
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
                return 0;
        }
    }
    return top == -1;
}
int main() {
    char expression[100];
    scanf("%s", expression);
    if (isBalanced(expression))
        printf("true");
    else
        printf("false");
    return 0;
}