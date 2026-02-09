# Linked List Reverse Traversal Program Documentation

## Data Structures

The program uses a Node structure to represent each element in the linked list:

data - This integer type variable stores the value of the node.

next - Pointer to the next node in the list. Points to NULL if it's the last node.

Such a structure enables nodes to be linked together in a chain, creating a singly linked list, where every node includes a link to the next.

## Functions

createNode - This function makes a new node and inserts the data into it. It dynamically allocates memory for this node and also sets the next pointer to NULL.

insertEnd - This function inserts a new node at the end of the linked list. If the list is empty, the new node is set as the head. Otherwise, it traverses the list and reaches the end, attaching the new node at the end.

displayForward - Displays all elements in the list from beginning to end. This function walks down the list from the head, printing the data in each node.

reverseTraversal - The main function that implements reverse traversal by calling itself until it reaches the end of the list and then starts printing values by returning from its calls.

displayReverse** - A wrapper function that calls reverseTraversal and adds additional formatting. This function prints "Reverse:" followed by the reversed list.

freeList - Frees all the memory that is allocated to the linked list. It traverses the list, freeing all nodes to prevent any memory leak.

## Main Method Organization

The main method follows this sequence:

Variable Declaration - A pointer for the head of the list and variables for user input are declared.

User Input - This will prompt the user to enter the number of elements they wish to include.

List Creation - Uses a loop to ask for input from the user for each element in the list and appends it to the end by calling the function insertEnd.

Display Output - Calls displayForward to show the list in normal order, then calls displayReverse to show the list in reverse order.

Memory Cleanup - Calls freeList to free all nodes and prevent memory leakage.

Program Termination - Return 0 to indicate successful program execution.

## Algorithm

The algorithm for reverse traversal employs recursion to achieve the aim of printing the elements in the linked list in reverse order:

Check if the current node is NULL, then return immediately-base case.

Recursively call the function reverseTraversal on the next node until the last node (or the node before the last, depending on language and implementation) is reached.

Print data of current node after recursive call returns.

The key principle is that recursion naturally reverses the order. When we make recursive calls going forward through the list, the print statements execute in reverse order as the recursion unwinds.

For a list containing 10, 20, 30, 40:

Yet, this function does call itself four times, moving forward through the list.

When it reaches NULL after 40, it starts returning.

As it returns, it prints: 40, then 30, then 20, then 10.

The algorithm has the time complexity O(n) where n is the number of nodes as each node is visited exactly once. The Space complexity is also O(n) due to the recursion call stack that will store one frame for each node in the worst case.

## Sample Output
Enter the number of elements: 5
Enter 5 elements:
10
20
30
40
50

Forward: 10 20 30 40 50
Reverse: 50 40 30 20 10


