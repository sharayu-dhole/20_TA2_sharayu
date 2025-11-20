#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[100], prefix[100], temp[100];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    int len = strlen(infix);

    for (i = 0; i < len; i++)
        temp[i] = infix[len - i - 1];
    temp[len] = '\0';


    for (i = 0; i < len; i++) {
        if (temp[i] == '(') temp[i] = ')';
        else if (temp[i] == ')') temp[i] = '(';
    }


    for (i = 0; i < len; i++) {
        char ch = temp[i];

        if (isalnum(ch)) {
            prefix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                prefix[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && precedence(stack[top]) > precedence(ch))
                prefix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        prefix[j++] = pop();

    prefix[j] = '\0';


    int k, m = strlen(prefix);
    for (k = 0; k < m / 2; k++) {
        char t = prefix[k];
        prefix[k] = prefix[m - k - 1];
        prefix[m - k - 1] = t;
    }

    printf("Prefix: %s\n", prefix);

    return 0;
}

