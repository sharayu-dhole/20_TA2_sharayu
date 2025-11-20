#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* root = NULL;

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* node, int val) {
    if (!node) return createNode(val);
    if (val < node->data)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);
    return node;
}

void inorder(struct Node* node) {
    if (!node) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(struct Node* node) {
    if (!node) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void bfs(struct Node* node) {
    if (!node) return;
    struct Node* q[100];
    int f = 0, r = 0;
    q[r++] = node;
    while (f < r) {
        struct Node* t = q[f++];
        printf("%d ", t->data);
        if (t->left) q[r++] = t->left;
        if (t->right) q[r++] = t->right;
    }
}

void mirror(struct Node* node) {
    if (!node) return;
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}

struct Node* find(struct Node* node, int val) {
    if (!node || node->data == val) return node;
    if (val < node->data) return find(node->left, val);
    return find(node->right, val);
}

struct Node* parent(struct Node* node, int val) {
    if (!node) return NULL;
    if ((node->left && node->left->data == val) ||
        (node->right && node->right->data == val))
        return node;
    if (val < node->data) return parent(node->left, val);
    return parent(node->right, val);
}

void children(int val) {
    struct Node* n = find(root, val);
    if (!n) return;
    if (n->left) printf("Left child: %d\n", n->left->data);
    if (n->right) printf("Right child: %d\n", n->right->data);
}

void sibling(int val) {
    struct Node* p = parent(root, val);
    if (!p) return;
    if (p->left && p->left->data == val && p->right)
        printf("Sibling: %d\n", p->right->data);
    else if (p->right && p->right->data == val && p->left)
        printf("Sibling: %d\n", p->left->data);
}

void grandparent(int val) {
    struct Node* p = parent(root, val);
    if (!p) return;
    struct Node* gp = parent(root, p->data);
    if (gp) printf("Grandparent: %d\n", gp->data);
}

void uncle(int val) {
    struct Node* p = parent(root, val);
    if (!p) return;
    struct Node* gp = parent(root, p->data);
    if (!gp) return;
    if (gp->left && gp->left->data == p->data && gp->right)
        printf("Uncle: %d\n", gp->right->data);
    else if (gp->right && gp->right->data == p->data && gp->left)
        printf("Uncle: %d\n", gp->left->data);
}

int main() {
    int ch, val;

    while (1) {
        printf("\n1.Insert 2.Inorder 3.Preorder 4.Postorder 5.BFS 6.Mirror");
        printf(" 7.Children 8.Sibling 9.Parent 10.GP 11.Uncle 0.Exit\n");
        scanf("%d", &ch);

        if (ch == 0) break;

        switch (ch) {
            case 1: printf("Value: "); scanf("%d",&val); root = insert(root,val); break;
            case 2: inorder(root); printf("\n"); break;
            case 3: preorder(root); printf("\n"); break;
            case 4: postorder(root); printf("\n"); break;
            case 5: bfs(root); printf("\n"); break;
            case 6: mirror(root); break;
            case 7: printf("Value: "); scanf("%d",&val); children(val); break;
            case 8: printf("Value: "); scanf("%d",&val); sibling(val); break;
            case 9: printf("Value: "); scanf("%d",&val);
                    struct Node* p = parent(root,val);
                    if(p) printf("Parent: %d\n", p->data);
                    break;
            case 10: printf("Value: "); scanf("%d",&val); grandparent(val); break;
            case 11: printf("Value: "); scanf("%d",&val); uncle(val); break;
        }
    }
    return 0;
}

