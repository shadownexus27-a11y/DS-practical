#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/' || op == '%') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

/* ^ is right-associative */
int isRightAssociative(char op) {
    return (op == '^');
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (c == ' ' || c == '\t') {
            continue;
        }

        if (isalnum((unsigned char)c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top >= 0 && peek() != '(') {
                postfix[k++] = pop();
            }
            if (top >= 0 && peek() == '(') {
                pop(); /* remove '(' */
            }
        } else if (isOperator(c)) {
            while (top >= 0 && peek() != '(') {
                char topOp = peek();
                int topPrec = precedence(topOp);
                int currPrec = precedence(c);

                if ((!isRightAssociative(c) && topPrec >= currPrec) ||
                    (isRightAssociative(c) && topPrec > currPrec)) {
                    postfix[k++] = pop();
                } else {
                    break;
                }
            }
            push(c);
        }
    }

    while (top >= 0) {
        if (peek() != '(') {
            postfix[k++] = pop();
        } else {
            pop();
        }
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("--- Practical 4: Infix to Postfix Conversion ---\n");
    printf("Enter infix expression: ");
    if (fgets(infix, sizeof(infix), stdin) != NULL) {
        infix[strcspn(infix, "\r\n")] = '\0';

        if (strlen(infix) == 0) {
            printf("Empty expression.\n");
            return 0;
        }

        infixToPostfix(infix, postfix);
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}
