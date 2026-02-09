# Min and Max Heap Construction Program Documentation

## Data Structures

The program utilizes arrays to represent heaps:

Array Representation - A heap can be kept in an array such that for any element in the array at position i:
- Left child is at index 2 * i + 1
- Right child is located at position 2*i + 2
- Parent (i-1)/2 

Max Heap - A complete binary tree in which each parent always has a greater value than or equal to its children. The largest element is present at the root (index 0). 

Min Heap - This is a complete binary tree in which the parent node is less than or equal to the child node. Here, a parent node is at index 0.

## Functions

swap - Swap the values of two integer-type variables using a temp variable.

maxHeapify - This function maintains the max heap property for the tree rooted at index i. It compares the node with its left and right children, determines the largest value among the three, and swaps accordingly. It also performs recursive maxHeapify operation.

buildMaxHeap - This function builds a max heap from any unsorted array. It begins from the last non-leaf node and goes up to the root node, calling maxHeapify for each node.

minHeapify - Enforces the min-heap property on a subtree rooted at index i. Here, a node is compared with its left and right children. The smallest of these children is selected and swapped with the node, and a recursive call is made.

buildMinHeap - This method is used to create a min heap from a given unsorted array. It starts from the last non-leaf node, and the minHeapify method is called on each element moving upwards to the root.

displayArray - This function prints all elements of the array.

## Main Method Organization

The main method shows an example of heap construction via the following sequence:

Data Initialization - Constructs an unsorted array with some data and determines its size.

Display Original Array - Prints the original array before constructing the heap.

Max Heap Construction - The original array is copied to a new array. buildMaxHeap function is called to build the max heap. The max heap is displayed.

Min Heap Construction - It creates another array by copying the original array and then calls buildMinHeap to create the min heap and display it.

## Algorithm

### Build Max Heap Algorithm

- Start from the last non-leaf node, i.e., from n/2 - 1.
- For each node from this position down to the root (index 0) do:
- Call maxHeapify on the current node.
- End for.

### Max Heapify Algorithm

- Let largest = current node index i.
- Calculate left child index = 2*i + 1.
- Calculate right child index = 2*i + 2.
- If the left child exists and is greater than the node at largest, set largest = left child index.
- If the right child exists and is larger than the node at largest, set largest = right child index.
- If largest != i:
- Swap elements at index i with the largest.
- Recursively call maxHeapify on the largest index.

### Build Min Heap Algorithm

- Start from the last node that is not a leaf node, which is located at n/2 - 1.
- For each node from this position down to the root (index 0) do:
- Again, call minHeapify on the current node.
- End for.

### Min Heapify Algorithm

- Let smallest = current node index i.
- Calculate left child index: 2*i + 1.
- Calculate right child index = 2*i + 2.
- If left child exists and left child < node at smallest, then assign smallest = left child index.
- If the right child exists and is less than the node at smallest, assign smallest = right child index.
- If smallest is NOT equal to i:
- Swap elements at index i and smallest. - Recursively call minHeapify on the smallest index.
## Sample Output

=== Min and Max Heap Construction ===

Original Array: 12 11 13 5 6 7 15 9 8 10 

Max Heap: 15 12 13 9 11 7 5 6 8 10 

Min Heap: 5 6 7 8 10 13 15 9 12 11 