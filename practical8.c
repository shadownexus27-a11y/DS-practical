#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
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
    newNode->prev = NULL;
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

void insertBeginning(int val) {
    struct Node *newNode = createNode(val);
    if (newNode == NULL) return;

    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    printf("%d inserted at the beginning.\n", val);
}

void insertEnd(int val) {
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
    newNode->prev = temp;
    printf("%d inserted at the end.\n", val);
}

/* 1-based position */
void insertPosition(int val, int pos) {
    int total = countNodes();
    int i;
    struct Node *temp, *newNode;

    if (pos < 1 || pos > total + 1) {
        printf("Invalid position! Enter between 1 and %d.\n", total + 1);
        return;
    }

    if (pos == 1) {
        insertBeginning(val);
        return;
    }

    if (pos == total + 1) {
        insertEnd(val);
        return;
    }

    newNode = createNode(val);
    if (newNode == NULL) return;

    temp = head;
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", val, pos);
}

void deleteBeginning() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

void deleteEnd() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    /* Single node */
    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

/* 1-based position */
void deletePosition(int pos) {
    int total = countNodes();
    int i;
    struct Node *temp;

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

    if (pos == total) {
        deleteEnd();
        return;
    }

    temp = head;
    for (i = 1; i < pos; i++) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}

void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
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
        printf("\n--- Practical 8: Doubly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBeginning(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(val, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                freeList();
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    freeList();
    return 0;
}
