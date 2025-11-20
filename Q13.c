#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->prev = n->next = NULL;
    return n;
}

void create(int val) {
    struct Node* n = createNode(val);
    if (!head) head = n;
    else {
        struct Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }
}

void display() {
    struct Node* t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void insertBegin(int val) {
    struct Node* n = createNode(val);
    if (!head) head = n;
    else {
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void insertEnd(int val) {
    create(val);
}

void insertPos(int val, int pos) {
    struct Node* n = createNode(val);
    if (pos == 1) {
        insertBegin(val);
        return;
    }
    struct Node* t = head;
    for (int i = 1; i < pos - 1 && t; i++)
        t = t->next;
    if (!t) return;
    n->next = t->next;
    if (t->next) t->next->prev = n;
    t->next = n;
    n->prev = t;
}

void deleteBegin() {
    if (!head) return;
    struct Node* t = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(t);
}

void deleteEnd() {
    if (!head) return;
    struct Node* t = head;
    if (!t->next) {
        free(t);
        head = NULL;
        return;
    }
    while (t->next) t = t->next;
    t->prev->next = NULL;
    free(t);
}

void deletePos(int pos) {
    if (pos == 1) {
        deleteBegin();
        return;
    }
    struct Node* t = head;
    for (int i = 1; i < pos && t; i++)
        t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

void reverse() {
    struct Node *c = head, *temp = NULL;
    while (c) {
        temp = c->prev;
        c->prev = c->next;
        c->next = temp;
        c = c->prev;
    }
    if (temp) head = temp->prev;
}

struct Node* merge(struct Node* h1, struct Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;
    struct Node* t = h1;
    while (t->next) t = t->next;
    t->next = h2;
    h2->prev = t;
    return h1;
}

int findMiddle() {
    struct Node *s = head, *f = head;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
    }
    return s->data;
}

void sort() {
    struct Node *i, *j;
    for (i = head; i; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
}

int detectLoop() {
    struct Node *s = head, *f = head;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
        if (s == f) return 1;
    }
    return 0;
}

int sum() {
    int s = 0;
    struct Node* t = head;
    while (t) {
        s += t->data;
        t = t->next;
    }
    return s;
}

void printOddEven() {
    struct Node* t = head;
    printf("Odd: ");
    while (t) {
        if (t->data % 2 != 0) printf("%d ", t->data);
        t = t->next;
    }
    printf("\nEven: ");
    t = head;
    while (t) {
        if (t->data % 2 == 0) printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, val, pos;

    while (1) {
        printf("\n1.Create 2.Display 3.InsertBegin 4.InsertEnd 5.InsertPos\n");
        printf("6.DeleteBegin 7.DeleteEnd 8.DeletePos 9.Reverse 10.Sort\n");
        printf("11.Find Middle 12.Sum 13.Odd-Even 14.Detect Loop 0.Exit\n");
        scanf("%d", &ch);

        if (ch == 0) break;

        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d",&val); create(val); break;
            case 2: display(); break;
            case 3: printf("Enter value: "); scanf("%d",&val); insertBegin(val); break;
            case 4: printf("Enter value: "); scanf("%d",&val); insertEnd(val); break;
            case 5: printf("Enter value & pos: "); scanf("%d%d",&val,&pos); insertPos(val,pos); break;
            case 6: deleteBegin(); break;
            case 7: deleteEnd(); break;
            case 8: printf("Enter pos: "); scanf("%d",&pos); deletePos(pos); break;
            case 9: reverse(); break;
            case 10: sort(); break;
            case 11: printf("Middle = %d\n", findMiddle()); break;
            case 12: printf("Sum = %d\n", sum()); break;
            case 13: printOddEven(); break;
            case 14: printf(detectLoop() ? "Loop Found\n" : "No Loop\n"); break;
        }
    }

    return 0;
}

