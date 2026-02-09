# Undirected Graph Traversal Program Documentation

## Data Structures

The program makes use of an adjacency matrix to represent an undirected graph:

Adjacency Matrix - It is a 2D array where the element at position [i][j] in the array is 1 if there is an edge between vertex i and vertex j, otherwise 0. It is symmetric for an undirected graph, i.e., graph[i][j] == graph[j][i].

Queue Structure - For BFS traversal, it contains:

items[MAX] - An array of integers that holds queue elements.

front - An integer to keep track of the front of the queue.

rear - This will be an integer to keep track of the position of the "rear" of the queue.

## Functions

initQueue - Initializes an empty queue by setting front and rear to -1.

isQueueEmpty - It verifies whether the queue is empty or not. It does this by checking whether its front element is -1.

enqueue - Adds a vertex to the rear of the queue. If the queue is empty, sets front to 0.

dequeue – Removes and returns the front element from the queue. Adjusts front and rear pointers accordingly.

BFS: It implements the Breadth-First Search traversal technique. It uses a queue for traversal; hence, neighbors of the visited node are visited before moving to the next level. It also marks the visited node to avoid visiting the node twice.

DFSUtil - It is a helper function for DFS that contains its recursive implementation. It is used to mark the visited vertex, print it, and make all unvisited adjacent vertices visited.

DFS - Implements the Depth First Search traversal. Initializes the visited array and calls DFSUtil to perform recursive traversal. Explores as deeply as it can go before backtracking.

displayGraph - This method displays the representation of the adjacency matrix in a structured table to show the connections between each vertex in the graph.

## Main Method Organization

The main method demonstrates the graph traversal operations using the following sequence:

Variable Declaration - It declares the number of vertices and creates an adjacency matrix initialized with zeros.

Graph Creation - This method simply adds edges to create an example of an undirected graph. Both graph[i][j], and graph[j][i] are set to 1 in each pair of edges.

Display Graph Information - Prints out the number of vertices and all edges in the given graph.

Display Adjacency Matrix - Uses displayGraph to display the adjacency matrix form of the given graph.

BFS Traversal - This method calls the BFS function, considering vertex 0 as the root, and displays the order of traversal.

DFS Traversal
The given code calls the DFS function with vertex 0 as the starting vertex and prints the DFS traversal order.
## Algorithm

### BFS Algorithm

- Initialize a queue and a visited array.
- Mark the start vertex as visited and add to the queue.
- While the queue is not empty do:
- Dequeue a vertex from the queue and print it.
- For all adjacent vertices of the dequeued vertex:
- If the adjacent vertex has not been visited, mark it visited and add it to the queue.
- End while.


### DFS Algorithm

- Initialize the array visited.
- Call the function DFSUtil with the starting vertex.
- In DFSUtil:
– Get the current vertex and mark it visited, then print the current vertex.
- For each adjacent vertex:
- If the adjacent vertex is not visited, DFSUtil is called.
## Sample Output

=== Undirected Graph Traversal ===

Example Graph with 6 vertices (0 to 5)

Edges:
0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5

Adjacency Matrix:
  0 1 2 3 4 5 
0 0 1 1 0 0 0 
1 1 0 0 1 1 0 
2 1 0 0 0 1 0 
3 0 1 0 0 0 1 
4 0 1 1 0 0 1 
5 0 0 0 1 1 0 

Starting from vertex 0:
BFS Traversal: 0 1 2 3 4 5 
DFS Traversal: 0 1 3 5 4 2 
