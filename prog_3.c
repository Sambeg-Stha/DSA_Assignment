#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end of the list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Forward traversal to display the list
void displayForward(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse traversal using recursion
void reverseTraversal(Node* head) {
    if (head == NULL) {
        return;
    }
    
    // Recursively traverse to the end
    reverseTraversal(head->next);
    
    // Print while returning from recursion
    printf("%d ", head->data);
}

// Display reverse traversal
void displayReverse(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Reverse: ");
    reverseTraversal(head);
    printf("\n");
}

// Free the entire list
void freeList(Node** head) {
    Node* current = *head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}

int main() {
    Node* head = NULL;
    int n, value;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }
    
    printf("\n");
    displayForward(head);
    displayReverse(head);
    
    freeList(&head);
    
    return 0;
}