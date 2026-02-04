#include <stdio.h>

#define MAX 6

char stack[MAX];
int top = -1;

// Check if stack is full
int isFull() {
    return top == MAX - 1;
}

//Check if stack is empty 
int isEmpty() {
    return top == -1;
}

// Push operation 
void push_stack(char val) {
    if (isFull()) {
        printf("STACK OVERFLOW\n");
    } else {
        stack[++top] = val;
    }
}

//Pop operation 
char pop_stack() {
    if (isEmpty()) {
        return '\0';
    } else {
        return stack[top--];
    }
}

// Match opening and closing brackets 
int match_checking(char open_sided, char close_sided) {
    if (open_sided == '(' && close_sided == ')') return 1;
    if (open_sided == '{' && close_sided == '}') return 1;
    if (open_sided == '[' && close_sided == ']') return 1;
    return 0;
}

// Check balanced parentheses 
void Checking_balance(char exp[]) {
    int balanced = 1;

    printf("EXPRESSION: %s\n", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push_stack(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty()) {
                balanced = 0;
                break;
            }

            char open = pop_stack();
            if (!match_checking(open, exp[i])) {
                balanced = 0;
                break;
            }
        }
    }

    if (balanced && isEmpty()) {
        printf("BALANCED\n\n");
    } else {
        printf("UNBALANCED\n\n");
    }

    //Reset stack for next expression 
    top = -1;
}

int main() {
    char exp1[] = "a+(b-c)*(d";
    char exp2[] = "m+[a-b*(c+d*{m)]";
    char exp3[] = "a+(b-c)";

    Checking_balance(exp1);
    Checking_balance(exp2);
    Checking_balance(exp3);

    return 0;
}
