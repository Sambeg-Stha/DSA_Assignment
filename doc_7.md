# Dijkstra's Shortest Path Algorithm Documentation
This program is based on the concept of Dijkstra's algorithm. The algorithm helps to find a short path from a source node to all other nodes in a graph. An adjacency matrix is used to represent the graph. Short distances and actual paths can be viewed.

## Data Structures

### Graph Structure

A data structure that implements a weighted graph using the adjacency matrix method of graph representation.


- vertices: An integer to hold the total number of vertices present in the graph - adjMatrix: It is a two-dimensional integer array of size MAX_VERTICES by MAX_VERTICES. It is used to store the weight of edges between vertices. If an edge exists between vertices i and j and its weight is w, then adjMatrix[i][j] holds this weight. If an edge does not exist between vertices i and j, then adjMatrix[i][j] is 0.
### PathInfo Structure
A data structure that maintains shortest path information computed by Dijkstra's algorithm.

- distance: An integer array that holds the shortest distance from the source vertex to each vertex. Initially set to infinity (INT_MAX) for all vertices except the source.
- parent: An array of integers holding the predecessor vertex in the shortest path to each vertex. To be used when reconstructing the actual path. A value of negative one implies no parent (for the source vertex or unreachable vertices).


- visited: a boolean array to mark if a vertex has been processed by the algorithm. Once a vertex is visited, its shortest distance will be fixed. MAX_VERTICES: The maximum number of vertices the graph may have is 100. This limits the size of the adjacency matrix.

### Functions

initGraph: Initializes a structure that represents a graph with a given number of vertices, with all edges weighted at zero.

addEdge: This function adds a weighted edge between two vertices in the graph.

findMinDistance: Returns the unvisited vertex with the minimum distance value.

dijkstra: Applies Dijkstra's algorithm to calculate the shortest paths from a source vertex to all other vertices.

- First, it initializes all distances to infinity, assigns all vertices to unvisited status, and sets all parents to negative one. It then sets the distance to the source vertex to zero.

-  Then, picks the unvisited vertex with minimum distance; marks as visited.

- For every neighbor of the selected node, calculate the distance from the source through the selected node. If this new distance is shorter than the previously known distance to the node, change the distance and parent accordingly.

- Continues until all reachable vertices have been visited.

printPath: Recursively prints the path from source to a given destination vertex.

displayResults: Displays a table with the shortest distance and path from source to all vertices.

displayGraph: Displays the graph's adjacency matrix in a readable table format.

## Main Method Organization
Asks the user to input the number of vertices to the current graph. Validates that the input is positive and not greater than MAX_VERTICES.

Calls initGraph to establish an empty graph with a specified number of vertices, with all edge weights initialized to zero.

Prompts the user to specify the number of edges to add to the graph. It also checks if the number is non-negative.

Loops to collect information for each edge. For each edge, it asks for the source vertex, destination vertex, and weight. Verifies that the vertices are within the valid range and that the weight is positive. Then calls addEdge to add the valid edges to the graph.


The function calls displayGraph, allowing users to check that their graph has been constructed correctly by displaying the adjacency matrix.


It prompts the user to enter the vertex for the starting point of all shortest paths calculations. It validates whether the entered vertex number falls within the valid range.


Calls dijkstra function, passing the graph, source vertex, and path information structure, to find all shortest paths.


It calls displayResults, which displays the shortest distance and path from the source vertex to every other vertex in a formatted table.

## Algorithm Description

### Dijkstra's Algorithm

1. Set the distance of the source vertex to zero and all other vertices to infinity. Mark all vertices as unvisited. Set all parent pointers to indicate no parent.

2. Select any vertex that has not been visited yet and has the minimum distance. The shortest path for this vertex is now finalized.

3. Calculate distance from source to the selected vertex through the all unvisited neighbor vertices of the selected vertex. If this calculated distance is less than the source's currently known distance to the neighbour update the neighbor's distance and parent.

4. Repeat steps 2 and 3 until all vertices are marked as visited or all remaining unvisited vertices have a distance of infinity, that is, unreachable.

5. Work backwards from any destination vertex to the source using the parent array to yield the true shortest path.

## Sample Output

Enter the number of vertices in the graph: 6
Enter the number of edges: 9

Enter edges (source destination weight):
Edge 1: 0 1 4
Edge 2: 0 2 3
Edge 3: 1 2 1
Edge 4: 1 3 2
Edge 5: 2 3 4
Edge 6: 2 4 5
Edge 7: 3 4 1
Edge 8: 3 5 6
Edge 9: 4 5 2

========== GRAPH ADJACENCY MATRIX ==========
     0   1   2   3   4   5 
 0   0   4   3   0   0   0 
 1   4   0   1   2   0   0 
 2   3   1   0   4   5   0 
 3   0   2   4   0   1   6 
 4   0   0   5   1   0   2 
 5   0   0   0   6   2   0 


Enter the source vertex: 0

Running Dijkstra's algorithm...

========== SHORTEST PATH RESULTS ==========
Source Vertex: 0

Destination	Distance	Path
-------------------------------------------
0		0		0
1		4		0 -> 1
2		3		0 -> 2
3		6		0 -> 1 -> 3
4		7		0 -> 1 -> 3 -> 4
5		9		0 -> 1 -> 3 -> 4 -> 5
===========================================
