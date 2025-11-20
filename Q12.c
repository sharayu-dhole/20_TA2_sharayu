#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertBegin(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void insertPos(int value, int pos) {
    struct Node* newNode = createNode(value);
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteBegin() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}


void deletePos(int pos) {
    if (head == NULL) return;
    if (pos == 1) {
        deleteBegin();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) return;

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Merge two linked lists
struct Node* mergeLists(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeLists(a->next, b);
    } else {
        result = b;
        result->next = mergeLists(a, b->next);
    }
    return result;
}


void findMiddle() {
    struct Node *slow = head, *fast = head;
    if (head == NULL) return;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element = %d\n", slow->data);
}

// Sort linked list (Bubble sort)
void sortList() {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


int detectLoop() {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}


int sumList() {
    int sum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

void printOddEven() {
    struct Node* temp = head;

    printf("Odd elements: ");
    while (temp != NULL) {
        if (temp->data % 2 != 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }

    temp = head;
    printf("\nEven elements: ");
    while (temp != NULL) {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertEnd(10);
    insertEnd(5);
    insertEnd(20);
    insertEnd(3);
    insertEnd(15);

    printf("List: ");
    display();

    insertBegin(100);
    insertPos(50, 3);
    deleteEnd();
    deletePos(2);

    printf("Updated List: ");
    display();

    printf("Reversed: ");
    reverseList();
    display();

    sortList();
    printf("Sorted: ");
    display();

    findMiddle();

    printf("Sum of nodes = %d\n", sumList());

    printOddEven();

    if (detectLoop())
        printf("Loop detected\n");
    else
        printf("No loop detected\n");

    return 0;
}

