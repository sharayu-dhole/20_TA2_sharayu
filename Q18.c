#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

struct Trie {
    struct Trie* child[ALPHABET];
    int isEnd;
};

struct Trie* createNode() {
    struct Trie* n = (struct Trie*)malloc(sizeof(struct Trie));
    n->isEnd = 0;
    for (int i = 0; i < ALPHABET; i++)
        n->child[i] = NULL;
    return n;
}

void insert(struct Trie* root, char* word) {
    struct Trie* curr = root;
    while (*word) {
        int index = *word - 'a';
        if (!curr->child[index])
            curr->child[index] = createNode();
        curr = curr->child[index];
        word++;
    }
    curr->isEnd = 1;
}

int search(struct Trie* root, char* word) {
    struct Trie* curr = root;
    while (*word) {
        int index = *word - 'a';
        if (!curr->child[index])
            return 0;
        curr = curr->child[index];
        word++;
    }
    return curr->isEnd;
}

int main() {
    struct Trie* root = createNode();

    insert(root, "apple");
    insert(root, "bat");
    insert(root, "cat");

    printf("Search apple: %s\n", search(root, "apple") ? "Found" : "Not Found");
    printf("Search cap: %s\n", search(root, "cap") ? "Found" : "Not Found");

    return 0;
}

