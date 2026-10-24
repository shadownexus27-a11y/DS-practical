#include <stdio.h>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue: a = %d, b = %d\n", a, b);
}

void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Inside swapByReference: a = %d, b = %d\n", *a, *b);
}

int main() {
    int choice;
    int a, b;
    int x = 10;
    int *ptr = &x;

    while (1) {
        printf("\n--- Practical 1: Pointers and Functions ---\n");
        printf("1. Pointer Basics\n");
        printf("2. Call by Value\n");
        printf("3. Call by Reference\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("\nValue of x: %d\n", x);
                printf("Address of x (&x): %p\n", (void *)&x);
                printf("Value stored in ptr: %p\n", (void *)ptr);
                printf("Value pointed to by ptr (*ptr): %d\n", *ptr);
                *ptr = 25;
                printf("After *ptr = 25, value of x: %d\n", x);
                x = 10; /* reset */
                break;

            case 2:
                printf("\nEnter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("Before swapByValue: a = %d, b = %d\n", a, b);
                swapByValue(a, b);
                printf("After swapByValue in main: a = %d, b = %d\n", a, b);
                break;

            case 3:
                printf("\nEnter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("Before swapByReference: a = %d, b = %d\n", a, b);
                swapByReference(&a, &b);
                printf("After swapByReference in main: a = %d, b = %d\n", a, b);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
