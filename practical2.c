#include <stdio.h>

#define MAX 50

void display(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int *n, int val, int pos) {
    int i;
    if (*n >= MAX) {
        printf("Array is full.\n");
        return 0;
    }
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position! Enter between 1 and %d.\n", *n + 1);
        return 0;
    }

    for (i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    (*n)++;
    return 1;
}

int deleteElement(int arr[], int *n, int pos) {
    int i, deleted;
    if (*n <= 0) {
        printf("Array is empty.\n");
        return -1;
    }
    if (pos < 1 || pos > *n) {
        printf("Invalid position! Enter between 1 and %d.\n", *n);
        return -1;
    }

    deleted = arr[pos - 1];
    for (i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return deleted;
}

int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[MAX];
    int n = 0, choice, val, pos, res, i;

    printf("Enter number of initial elements: ");
    if (scanf("%d", &n) == 1 && n > 0) {
        if (n > MAX) n = MAX;
        printf("Enter %d elements: ", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
    }

    while (1) {
        printf("\n--- Practical 2: Array Operations ---\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search (Requires sorted array)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                display(arr, n);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);
                if (insertElement(arr, &n, val, pos)) {
                    printf("Element inserted successfully.\n");
                }
                break;

            case 3:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                res = deleteElement(arr, &n, pos);
                if (res != -1) {
                    printf("Deleted element: %d\n", res);
                }
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &val);
                res = linearSearch(arr, n, val);
                if (res != -1) {
                    printf("Element found at position %d (index %d).\n", res + 1, res);
                } else {
                    printf("Element not found.\n");
                }
                break;

            case 5:
                printf("Enter element to search: ");
                scanf("%d", &val);
                res = binarySearch(arr, n, val);
                if (res != -1) {
                    printf("Element found at position %d (index %d).\n", res + 1, res);
                } else {
                    printf("Element not found.\n");
                }
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
