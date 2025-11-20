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
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

int findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    struct Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    printf("Minimum = %d\n", findMin(root));
    printf("Maximum = %d\n", findMax(root));

    return 0;
}

