#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Queue structure for BFS
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(Queue* q, int value) {
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue operation
int dequeue(Queue* q) {
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// BFS traversal
void BFS(int graph[MAX][MAX], int vertices, int startVertex) {
    Queue q;
    initQueue(&q);
    
    int visited[MAX] = {0};
    
    visited[startVertex] = 1;
    enqueue(&q, startVertex);
    
    printf("BFS Traversal: ");
    
    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// DFS traversal using recursion
void DFSUtil(int graph[MAX][MAX], int vertices, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, vertices, i, visited);
        }
    }
}

// DFS traversal
void DFS(int graph[MAX][MAX], int vertices, int startVertex) {
    int visited[MAX] = {0};
    
    printf("DFS Traversal: ");
    DFSUtil(graph, vertices, startVertex, visited);
    printf("\n");
}

// Display adjacency matrix
void displayGraph(int graph[MAX][MAX], int vertices) {
    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for (int i = 0; i < vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < vertices; i++) {
        printf("%d ", i);
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 6;
    int graph[MAX][MAX] = {0};
    
    // Creating an example undirected graph
    // Adding edges
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][5] = graph[5][3] = 1;
    graph[4][5] = graph[5][4] = 1;
    
    printf("=== Undirected Graph Traversal ===\n");
    printf("\nExample Graph with %d vertices (0 to %d)\n", vertices, vertices - 1);
    printf("\nEdges:\n");
    printf("0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5\n");
    
    displayGraph(graph, vertices);
    
    printf("\nStarting from vertex 0:\n");
    BFS(graph, vertices, 0);
    DFS(graph, vertices, 0);
    
    return 0;
}