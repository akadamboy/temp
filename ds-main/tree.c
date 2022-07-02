#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *init_node(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void preorder(struct Node *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void insert(struct Node *root, int data) {
    struct Node *itr = root;
    struct Node *prev = NULL;
    if (!root) {
        root = init_node(data);
        return;
    }
    while (itr) {
        prev = itr;
        if (itr->data > data)
            itr = itr->left;
        else if (itr->data < data)
            itr = itr->right;
    }
    if (prev->data > data)
        prev->left = init_node(data);
    else
        prev->right = init_node(data);
}

int main() {
    struct Node *root = init_node(10);
    insert(root, 100);
    insert(root, 50);
    insert(root, 75);
    insert(root, 7);
    insert(root, 30);
    insert(root, 0);

    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");

    return 0;
}
