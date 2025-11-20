#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int x) {
    if (top < SIZE - 1)
        stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Binary: 0\n");
        return 0;
    }

    while (num > 0) {
        push(num % 2);
        num /= 2;
    }

    printf("Binary: ");
    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}

