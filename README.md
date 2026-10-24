# Data Structures (DS) Lab Practicals

A complete collection of 10 Data Structures lab practicals implemented in C.

---

## List of Practicals

| Practical | Filename | Aim |
|---|---|---|
| **Practical 1** | `practical1.c` | Demonstrate Pointers, Call by Value, and Call by Reference. |
| **Practical 2** | `practical2.c` | Implement Array operations: insertion, deletion, searching (Linear & Binary), and traversal. |
| **Practical 3** | `practical3.c` | Implement a Stack using an array: PUSH, POP, PEEP, CHANGE, and DISPLAY. |
| **Practical 4** | `practical4.c` | Convert an infix expression to a postfix expression using a stack. |
| **Practical 5** | `practical5.c` | Implement a Linear Queue using an array: INSERT, DELETE, and DISPLAY. |
| **Practical 6** | `practical6.c` | Implement a Singly Linked List with insertion at beginning, end, and specified position. |
| **Practical 7** | `practical7.c` | Implement a Singly Linked List with deletion from beginning, end, and specified position. |
| **Practical 8** | `practical8.c` | Implement a Doubly Linked List with insertion and deletion at beginning, end, and specified position. |
| **Practical 9** | `practical9.c` | Create a Binary Search Tree (BST) and perform insertion, search, and inorder traversal. |
| **Practical 10** | `practical10.c` | Create a General Binary Tree explicitly and perform Inorder, Preorder, and Postorder traversals. |

---

## How to Compile and Run

### On Linux / macOS
```bash
gcc practical1.c -o practical1
./practical1
```

### On Windows (MinGW GCC)
```powershell
gcc practical1.c -o practical1.exe
.\practical1.exe
```

---

## Sample Inputs and Outputs

### Practical 1: Pointers, Call by Value and Call by Reference
```text
Enter two numbers: 10 20
Before swapByReference: a = 10, b = 20
Inside swapByReference: a = 20, b = 10
After swapByReference in main: a = 20, b = 10
```

### Practical 2: Array Operations
```text
Enter number of initial elements: 3
Enter 3 elements: 10 30 40

1. Display Array
2. Insert Element
3. Delete Element
...
Enter your choice: 2
Enter value to insert: 20
Enter position (1 to 4): 2
Element inserted successfully.
```

### Practical 3: Stack Operations
```text
1. Push
2. Pop
3. Peep (from top)
4. Change (from top)
5. Display
...
Enter your choice: 1
Enter value to push: 50
50 pushed onto stack.
```

### Practical 4: Infix to Postfix Conversion
```text
Enter infix expression: (A+B)*C-(D-E)
Postfix expression: AB+C*DE--
```

### Practical 5: Queue Operations
```text
1. Insert
2. Delete
3. Display
...
Enter your choice: 1
Enter value to insert: 25
25 inserted into queue.
```

### Practical 6: Singly Linked List Insertion
```text
1. Insert at Beginning
2. Insert at End
3. Insert at Specified Position
...
Enter your choice: 1
Enter value: 15
15 inserted at the beginning.
```

### Practical 7: Singly Linked List Deletion
```text
1. Insert Element (at end)
2. Delete from Beginning
3. Delete from End
4. Delete from Specified Position
...
Enter your choice: 2
Deleted 15 from beginning.
```

### Practical 8: Doubly Linked List Operations
```text
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display List
...
Doubly Linked List: NULL <-> 10 <-> 20 <-> 30 <-> NULL
```

### Practical 9: Binary Search Tree
```text
1. Insert
2. Search
3. Inorder Traversal
...
Enter value to insert: 50
50 inserted into BST.
Inorder traversal: 20 30 40 50 70
```

### Practical 10: Binary Tree Traversals
```text
Build tree (enter -1 when there is no child):
Enter data (-1 for no node): 1
Enter left child of 1:
Enter data (-1 for no node): 2
...
Preorder traversal: 1 2 4 5 3 6 7
Inorder traversal: 4 2 5 1 6 3 7
Postorder traversal: 4 5 2 6 7 3 1
```
