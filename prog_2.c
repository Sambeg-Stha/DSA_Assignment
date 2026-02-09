#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push operation
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->items[++(s->top)] = c;
    }
}

// Pop operation
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

// Peek at top element
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

// Check if character is an operand
int isOperand(char c) {
    return isalnum(c);
}

// Get precedence of operators
int precedence(char c) {
    switch(c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Convert infix to postfix
void infixToPostfix(char *exp, char *postfix) {
    Stack stack;
    initStack(&stack);  // Initialize an empty stack
    
    int i = 0, j = 0;
    
    // For each character c in exp
    while (exp[i] != '\0') {
        char c = exp[i];
        
        // Skip whitespace
        if (isspace(c)) {
            i++;
            continue;
        }
        
        // If c is an operand
        if (isOperand(c)) {
            postfix[j++] = c;  // Concatenate to postfix
        }
        // If c is an open parenthesis
        else if (c == '(') {
            push(&stack, c);  // Push into stack
        }
        // If c is a closed parenthesis
        else if (c == ')') {
            // Pop until open parenthesis
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);  // Remove the open parenthesis
        }
        // If c is an operator
        else {
            // Pop operators with higher or equal precedence
            while (!isEmpty(&stack) && 
                   peek(&stack) != '(' && 
                   precedence(c) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            // Push current operator
            push(&stack, c);
        }
        
        i++;
    }
    
    // Pop remaining operators from stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    
    postfix[j] = '\0';  // Null-terminate the string
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    
    // Remove newline if present
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}