# Infix to Postfix Conversion Program Documentation

## Data Structures
The program uses a Stack data structure implemented as a structure containing two components:

stack - an array of character type that holds the elements in the stack and has a maximum capacity of 100 elements.

TOP pointer: This is an integer that keeps track of the index of the top element in the stack. In the case of an empty stack, top is set to -1.

## Algorithm
- 1: Initialize an empty stack
- 2: for each character c in exp do
- 3: if c is an operand then
- 4: Concatenate c to the postfix expression
- 5: else if c is an open parenthesis then
- 6: Push c into the stack
- 7: else if c is a closed parenthesis then
- 8: repeat
- 9: Pop the stack and concatenate the popped character to the postfix expression
- 10: until an open parenthesis is encountered
- 11: else
- 12: while the stack is not empty and precedence of c is less than or equal to that of the top (and the top is not an open parenthesis) do
- 13: Pop the stack and concatenate the popped operator to the postfix expression
- 14: end while
- 15: Push c
- 16: end if
- 17: end for
- 18: while the stack is not empty do
- 19: Pop the stack and concatenate the popped operator to the postfix expression
- 20: end while
- 21: Return the postfix expression
## Functions

initStack - Initializes an empty stack by setting the top index to -1.

isEmpty - Checks whether the stack is empty by verifying if top equals -1.

isFull - Checks whether the stack has reached maximum capacity by comparing top to MAX-1.

push - adds a character onto the top of the stack if not full, incrementing the top index.

pop - Removes and returns the top element from the stack, decrementing the top index. It returns a null character in case of an empty stack.

peek - Returns the top element without removing it. Returns null character if empty.

isOperand - It tells whether a character is alphanumeric

precedence - Returns the precedence level of operators. Exponentiation has precedence 3, multiplication and division have precedence 2 and addition and subtraction have precedence 1.

infixToPostfix - This is the primary conversion routine which will scan each character in the input expression. Sending operands directly to output, pushing opening parentheses onto the stack, popping on closing parentheses and popping remaining operators at the end.

## Main Method Organization

The key method performs the following steps:

Variable Declaration - This part defines two character arrays: one for the input infix expression and the other for the output postfix expression.

User Input - It prompts the user to input an infix expression and reads it through fgets.

Conversion: This operation calls the infixToPostfix function to make the conversion.

Output Display - Prints the resulting postfix expression to the screen.

## Sample Output

Enter infix expression: A+B*C
Postfix expression: ABC*+
