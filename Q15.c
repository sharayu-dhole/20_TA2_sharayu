#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Print values in the range [L, R]
void printRange(struct Node* root, int L, int R) {
    if (root == NULL)
        return;


    if (root->data > L)
        printRange(root->left, L, R);


    if (root->data >= L && root->data <= R)
        printf("%d ", root->data);


    if (root->data < R)
        printRange(root->right, L, R);
}

int main() {
    struct Node* root = NULL;
    int arr[] = {50, 30, 20, 40, 70, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    int L, R;
    printf("Enter range L and R: ");
    scanf("%d %d", &L, &R);

    printf("Values in range [%d, %d]: ", L, R);
    printRange(root, L, R);

    return 0;
}

