#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top < SIZE - 1) {
        top++;
        stack[top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int checkParenthesis(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return 0;

            char open = pop();
            if (!isMatchingPair(open, ch)) return 0;
        }
    }

    if (top == -1) return 1;
    return 0;
}

int main() {
    char exp[100];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (checkParenthesis(exp))
        printf("Parentheses are Balanced\n");
    else
        printf("Parentheses are NOT Balanced\n");

    return 0;
}

