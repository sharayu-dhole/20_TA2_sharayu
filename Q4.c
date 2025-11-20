#include <stdio.h>
#define SIZE 100

int arr[SIZE];
int front1 = -1, rear1 = -1;
int front2 = SIZE, rear2 = SIZE;

void enqueue1(int value) {
    if (rear1 + 1 == rear2) return;
    if (front1 == -1) front1 = 0;
    rear1++;
    arr[rear1] = value;
}

void enqueue2(int value) {
    if (rear2 - 1 == rear1) return;
    if (front2 == SIZE) front2 = SIZE - 1;
    rear2--;
    arr[rear2] = value;
}

void dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        front1 = rear1 = -1;
        return;
    }
    front1++;
    if (front1 > rear1) front1 = rear1 = -1;
}

void dequeue2() {
    if (front2 == SIZE || front2 < rear2) {
        front2 = rear2 = SIZE;
        return;
    }
    front2--;
    if (front2 < rear2) front2 = rear2 = SIZE;
}

void display1() {
    if (front1 == -1) return;
    for (int i = front1; i <= rear1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void display2() {
    if (front2 == SIZE) return;
    for (int i = front2; i >= rear2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    enqueue1(10);
    enqueue1(20);
    enqueue2(100);
    enqueue2(200);
    display1();
    display2();
    dequeue1();
    dequeue2();
    display1();
    display2();
    return 0;
}

