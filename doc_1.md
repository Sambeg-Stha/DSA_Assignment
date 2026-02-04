# CODE DOCUMENTATION


## Data Structure
The data sturcture used is Stack
A stack of Size 6 is created with a top pointer assigned to -1 by top = -1
The follwing funtion are defiened:
- isEmpty
- isFull
- push
- pop
- match_checking
- balance_checking

## Algorithm
- Create Stack
- Treverse the expression give 
- if ether of the open brackets is found  then push the brackets in to the stack
- if either of the close brackets is found then:
- a.if the stack is empty -> "UNBALANCED"
- b.pop the top element
- c.check if the pop element is corresponing open brackets of the closed; if not then "UNBALANCED"
- After treversing check:
- a. stack is empty -> "BALANCED"
- b. else -> "UNBALANCED"


## FUNCTION IMPLEMENTION
### isEmpty:
if the top pointer in point to position -1 which has no correspondance to the stack than we consider the stack to be empty. This function is used so that we don't pop element of empty stack and in general to check if the stack is no elements

### isFull:
if the stack is completely filled with elements till MAX size , The stack is full and no more elements can be assigned to it. This function helps to avoid case of OverFlow Stack

### push: 
push is a major operation of Stack. Stack works on First in First Out principle (FIFO) so the push function is reponsible for instering elements to the top of the stack. Once the function is called in a Empty Stack the top postion is moved the 0 which represnts the first postion and in each new push the top position is incrsed once

### pop:
pop in another major operation of Stack. pop is responsible for retreving the top most element of stack. After each pop operation the top postion is reduced by one until the stack isEmpty from which pop cannot be done

### matching_checking:
This function is made specifcally for this program . To find if the pop element during expression checking is the corresponding open bracket of the cloded one checked. It has 2 parameter , one for open and another for closed bracket if the either of the three condition are met the condition if true

## balance_checking:
This is the function have parameter of the expression to be evaluated which goes through each element in the expresion and follow ths above mentioned algorithm and at end determine if the expression is balanced or not by checking all the required condintion and utilizing the other function.

## MAIN FUNCTION: 
the main function is as simple as it gets . There are 3 expression to be check which are passed through the balance_checking function which dose all the work for the problem

## OUTPUT
EXPRESSION: a+(b-c)*(d
UNBALANCED

EXPRESSION: m+[a-b*(c+d*{m)]
UNBALANCED

EXPRESSION: a+(b-c)
BALANCED