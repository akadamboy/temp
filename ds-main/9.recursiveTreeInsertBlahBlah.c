#include <stdio.h>
#include <stdlib.h>
#define newW(x) (x*)malloc(sizeof(x))

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* init(int data) {
    struct Node* node = newW(struct Node);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* create() {
    int data;
    printf("enter the data: ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    struct Node* node = init(data);
    printf("Enter the data for left child of %d\n", data);
    node->left = create();
    printf("Enter the data for right child of %d\n", data);
    node->right = create();
    return node;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root;
    root = create();
    printf("\npreorder: \t");
    preorder(root);
    printf("\ninorder: \t");
    inorder(root);
    printf("\npostorder: \t");
    postorder(root);
    printf("\n");
    return 0;
}