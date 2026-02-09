# Doubly Linked List Program Documentation

## Data Structures

The Node structure is defined for each element in the doubly linked list:

data - The integer value that the node holds.

next - A pointer to the next node on the list. It points to NULL if it's the last node.

prev - Pointer to the previous node on the list. Points to NULL if this is the first node.

This structure allows bidirectional traversal in that each node points to both the next and previous node, forming a doubly linked list.
## Functions

createNode - Allocates a new node with the given value. Dynamically allocates memory for the new node and then initializes next and prev pointers to NULL.

insertAfter - Inserts a new node after a specified node of the doubly linked list. Modifies the next pointer of the specified node to be the new node and modifies the previous pointer of the new node to the specified node. In addition, the previous pointer of the following node, if it exists, is adjusted.

deleteNode - Removes a specified node from the doubly linked list. Modifies the next pointer of the previous node and the previous pointer of the next node to skip the deleted node. Handles special cases if deleting a head node. Frees memory for the removed node.

displayList - This function prints all the elements of the list from start to end. It uses the "next" pointers to traverse the list and prints every node's data one by one.

## Main Method Organization

The main method illustrates the doubly linked list operations in the following order:

Create nodes: Four nodes with values 10, 20, 30, and 40 are created manually.

Link Nodes - Links the nodes manually together by setting their next and prev pointers to a doubly linked list.

Display Initial List - Displays the original list with four nodes.

Insert After Operation - Inserts value 25 after the node with value 20, then displays the updated list.

-Second Insert After. It inserts the value 45 after the node having the value 40 and then prints the updated list.

Delete Node Operation Deletes the node containing the value 30 and then displays the revised list.

Program Termination - Returns 0, which signifies that the execution is successful.

## Algorithm

### Insert After Algorithm

- Check if given previous is NULL or not. If it is, then display an error message and return.
- Create a new node with the given data.
- Set the next pointer of the new node to the node that was after the previous node.
- Set the next pointer of the previous node to point to the new node.
- Set the prev pointer of the new node to point at the previous node.
- If the new node is not the last node, make the prev pointer of the next node point to the new node.

### Delete Node Algorithm

- Check if the list is empty or if the node at position index is NULL. If true, write an appropriate error message and terminate.
- If the node to be removed is the head node, the head pointer should be moved to the next node.
- If the node to be deleted is not the last node, make sure that the next node’s prev pointer is changed to bypass the deleted node.
- If the node to be deleted is not the first node, the next pointer of the previous node is updated to skip over the deleted node.
- Release the memory of the deleted node.

## Sample Output

Initial list: 10 20 30 40

Inserting 25 after node with value 20
List: 10 20 25 30 40

Inserting 45 after node with value 40
List: 10 20 25 30 40 45

Deleting node with value 30
List: 10 20 25 40 45

