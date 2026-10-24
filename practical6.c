#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int countNodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtBeginning(int val) {
    struct Node *newNode = createNode(val);
    if (newNode == NULL) return;

    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning.\n", val);
}

void insertAtEnd(int val) {
    struct Node *newNode = createNode(val);
    struct Node *temp;
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
        printf("%d inserted at the end.\n", val);
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d inserted at the end.\n", val);
}

/* 1-based position */
void insertAtPosition(int val, int pos) {
    int total = countNodes();
    int i;
    struct Node *temp, *newNode;

    if (pos < 1 || pos > total + 1) {
        printf("Invalid position! Enter between 1 and %d.\n", total + 1);
        return;
    }

    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }

    newNode = createNode(val);
    if (newNode == NULL) return;

    temp = head;
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", val, pos);
}

void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList() {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n--- Practical 6: Singly Linked List Insertion ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specified Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(val, pos);
                break;

            case 4:
                display();
                break;

            case 5:
                freeList();
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    freeList();
    return 0;
}
