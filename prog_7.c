#include <stdio.h>   
#include <stdlib.h>  
#include <limits.h>  // For INT_MAX constant
#include <stdbool.h> // For boolean data type

#define MAX_VERTICES 100 

typedef struct {
    int vertices;                      // Number of vertices in the graph
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];  // Adjacency matrix to store weights
} Graph;

//shortest path results

typedef struct {
    int distance[MAX_VERTICES];   // Shortest distance from source to each vertex
    int parent[MAX_VERTICES];     // Parent vertex in shortest path
    bool visited[MAX_VERTICES];   // Whether vertex has been processed
} PathInfo;

//Initializes a graph with given number of vertices
void initGraph(Graph *g, int v) {
    int i, j;
    g->vertices = v;
    
    // Initialize all edges to 0 (no direct connection)
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

//Adds a weighted edge to the graph
void addEdge(Graph *g, int src, int dest, int weight) {
    // Add edge from source to destination
    g->adjMatrix[src][dest] = weight;
    // Add edge from destination to source (undirected graph)
    g->adjMatrix[dest][src] = weight;
}

//Finds the vertex with minimum distance that hasn't been visited yet
int findMinDistance(PathInfo *info, int vertices) {
    int min = INT_MAX;  // Initialize with maximum possible value
    int minIndex = -1;   // Index of vertex with minimum distance
    int v;
    
    // Search through all vertices
    for (v = 0; v < vertices; v++) {
        // If vertex not visited and has smaller distance
        if (!info->visited[v] && info->distance[v] < min) {
            min = info->distance[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

//Implements Dijkstra's algorithm to find shortest paths
void dijkstra(Graph *g, int source, PathInfo *info) {
    int i, v;
    
    //Initialize distances and visited array
    for (i = 0; i < g->vertices; i++) {
        info->distance[i] = INT_MAX;  // Set all distances to infinity
        info->visited[i] = false;      // Mark all vertices as unvisited
        info->parent[i] = -1;          // No parent initially
    }
    
    // Distance from source to itself is 0
    info->distance[source] = 0;
    
    //Process all vertices
    for (i = 0; i < g->vertices - 1; i++) {
        // Find vertex with minimum distance from unvisited vertices
        int u = findMinDistance(info, g->vertices);
        
        // If no reachable vertex found, break
        if (u == -1) break;
        
        // Mark the selected vertex as visited
        info->visited[u] = true;
        
        //Update distances of adjacent vertices
        for (v = 0; v < g->vertices; v++) {
            // Check if edge exists and vertex not visited
            if (g->adjMatrix[u][v] != 0 && !info->visited[v]) {
                // Calculate new distance through u
                int newDistance = info->distance[u] + g->adjMatrix[u][v];
                
                // If new distance is shorter, update it
                if (newDistance < info->distance[v]) {
                    info->distance[v] = newDistance;
                    info->parent[v] = u;  // Update parent
                }
            }
        }
    }
}


//Prints the path from source to a destination vertex

void printPath(PathInfo *info, int vertex) {
    // Base case: reached source vertex (parent is -1)
    if (info->parent[vertex] == -1) {
        printf("%d", vertex);
        return;
    }
    
    // Recursively print path to parent
    printPath(info, info->parent[vertex]);
    printf(" -> %d", vertex);
}


//Displays the shortest path results

void displayResults(PathInfo *info, int source, int vertices) {
    int i;
    
    printf("\n========== SHORTEST PATH RESULTS ==========\n");
    printf("Source Vertex: %d\n\n", source);
    printf("Destination\tDistance\tPath\n");
    printf("-------------------------------------------\n");
    
    for (i = 0; i < vertices; i++) {
        printf("%d\t\t", i);
        
        // Check if vertex is reachable
        if (info->distance[i] == INT_MAX) {
            printf("INF\t\tNo path exists\n");
        } else {
            printf("%d\t\t", info->distance[i]);
            printPath(info, i);
            printf("\n");
        }
    }
    printf("===========================================\n");
}

//Displays the adjacency matrix of the graph
void displayGraph(Graph *g) {
    int i, j;
    
    printf("\n========== GRAPH ADJACENCY MATRIX ==========\n");
    printf("   ");
    for (i = 0; i < g->vertices; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    
    for (i = 0; i < g->vertices; i++) {
        printf("%2d ", i);
        for (j = 0; j < g->vertices; j++) {
            printf("%3d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("============================================\n");
}

int main() {
    Graph graph;
    PathInfo pathInfo;
    int vertices, edges;
    int src, dest, weight;
    int source;
    int i;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Must be between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }
    
    initGraph(&graph, vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    if (edges < 0) {
        printf("Invalid number of edges.\n");
        return 1;
    }
    
    // Step 4: Input all edges with weights
    printf("\nEnter edges (source destination weight):\n");
    for (i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        
        // Validate vertices
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("Invalid vertex. Vertices must be between 0 and %d.\n", vertices - 1);
            i--;  // Retry this edge
            continue;
        }
        
        // Validate weight
        if (weight <= 0) {
            printf("Invalid weight. Weight must be positive.\n");
            i--;  // Retry this edge
            continue;
        }
        
        // Add edge to graph
        addEdge(&graph, src, dest, weight);
    }
    
    // Display the graph
    displayGraph(&graph);
    
    //get source vertex
    printf("\nEnter the source vertex: ");
    scanf("%d", &source);
    
    // Validate source vertex
    if (source < 0 || source >= vertices) {
        printf("Invalid source vertex.\n");
        return 1;
    }
    
    //Run Dijkstra's algorithm
    printf("\nRunning Dijkstra's algorithm...\n");
    dijkstra(&graph, source, &pathInfo);
    
    //Display results
    displayResults(&pathInfo, source, vertices);
    
    return 0;  // Program completed successfully
}