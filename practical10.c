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

/* Builds a general binary tree using recursion */
struct Node* createTree() {
    int val;
    struct Node *newNode;

    printf("Enter data (-1 for no node): ");
    if (scanf("%d", &val) != 1 || val == -1) {
        return NULL;
    }

    newNode = createNode(val);
    if (newNode == NULL) return NULL;

    printf("Enter left child of %d:\n", val);
    newNode->left = createTree();

    printf("Enter right child of %d:\n", val);
    newNode->right = createTree();

    return newNode;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
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
    int choice;

    while (1) {
        printf("\n--- Practical 10: Binary Tree Traversals ---\n");
        printf("1. Create Binary Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                if (root != NULL) {
                    freeTree(root);
                    root = NULL;
                }
                printf("Build tree (enter -1 when there is no child):\n");
                root = createTree();
                printf("Tree created successfully.\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Preorder traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Postorder traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                freeTree(root);
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    freeTree(root);
    return 0;
}
