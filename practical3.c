#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", val);
        return;
    }
    top++;
    stack[top] = val;
    printf("%d pushed onto stack.\n", val);
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    printf("Popped element: %d\n", stack[top]);
    top--;
}

/* Position i is 1-based from the top of the stack */
void peep(int i) {
    int index = top - i + 1;
    if (top < 0) {
        printf("Stack is empty.\n");
        return;
    }
    if (i <= 0 || index < 0) {
        printf("Invalid position from top.\n");
        return;
    }
    printf("Element at position %d from top is: %d\n", i, stack[index]);
}

/* Change the i-th element from the top of the stack */
void change(int i, int newVal) {
    int index = top - i + 1;
    if (top < 0) {
        printf("Stack is empty.\n");
        return;
    }
    if (i <= 0 || index < 0) {
        printf("Invalid position from top.\n");
        return;
    }
    printf("Element %d at position %d changed to %d.\n", stack[index], i, newVal);
    stack[index] = newVal;
}

void display() {
    int i;
    if (top < 0) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n--- Practical 3: Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep (from top)\n");
        printf("4. Change (from top)\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Enter position from top (1 for top element): ");
                scanf("%d", &pos);
                peep(pos);
                break;

            case 4:
                printf("Enter position from top: ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &val);
                change(pos, val);
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
