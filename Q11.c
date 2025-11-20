#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    int i, a, b;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            push(ch - '0');
        }
        else {
            b = pop();
            a = pop();

            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}

