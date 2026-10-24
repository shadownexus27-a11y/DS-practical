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

void insertEnd(int val) {
    struct Node *newNode = createNode(val);
    struct Node *temp;
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteBeginning() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

void deleteEnd() {
    struct Node *temp, *prev;
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    /* Only one node */
    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

/* 1-based position */
void deletePosition(int pos) {
    int total = countNodes();
    int i;
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if (pos < 1 || pos > total) {
        printf("Invalid position! Enter between 1 and %d.\n", total);
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    temp = head;
    prev = NULL;
    for (i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
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
        printf("\n--- Practical 7: Singly Linked List Deletion ---\n");
        printf("1. Insert Element (at end)\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Specified Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertEnd(val);
                display();
                break;

            case 2:
                deleteBeginning();
                display();
                break;

            case 3:
                deleteEnd();
                display();
                break;

            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePosition(pos);
                display();
                break;

            case 5:
                display();
                break;

            case 6:
                freeList();
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    freeList();
    return 0;
}
