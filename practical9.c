#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int val) {
    if (root == NULL) {
        printf("%d inserted into BST.\n", val);
        return createNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    } else {
        printf("Duplicate value %d already exists in BST.\n", val);
    }

    return root;
}

struct Node* search(struct Node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;
    struct Node *found;
    int choice, val;

    while (1) {
        printf("\n--- Practical 9: Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    break;
                }
                printf("Enter value to search: ");
                scanf("%d", &val);
                found = search(root, val);
                if (found != NULL) {
                    printf("%d found in BST.\n", val);
                } else {
                    printf("%d not found in BST.\n", val);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 4:
                freeTree(root);
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    freeTree(root);
    return 0;
}
