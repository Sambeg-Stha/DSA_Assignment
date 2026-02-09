#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert after a given node
void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    
    Node* newNode = createNode(data);
    
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

// Delete a node
void deleteNode(Node** head, Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        printf("Cannot delete: List is empty or node is NULL\n");
        return;
    }
    
    // If node to be deleted is head
    if (*head == delNode) {
        *head = delNode->next;
    }
    
    // Change next only if node is not the last node
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    
    // Change prev only if node is not the first node
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    
    free(delNode);
}

// Display the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Creating nodes manually
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);
    Node* fourth = createNode(40);
    
    // Linking nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    
    printf("Initial list: ");
    displayList(head);
    
    // Insert after second node (20)
    printf("\nInserting 25 after node with value 20\n");
    insertAfter(second, 25);
    displayList(head);
    
    // Insert after fourth node (40)
    printf("\nInserting 45 after node with value 40\n");
    insertAfter(fourth, 45);
    displayList(head);
    
    // Delete third node (30)
    printf("\nDeleting node with value 30\n");
    deleteNode(&head, third);
    displayList(head);
    
    return 0;
}