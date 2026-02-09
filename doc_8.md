# Sorting Algorithm Program Documentation

This program creates a list of random integers and sorts the elements of the list using one of four different sorts chosen by the user. The number of comparisons and swaps is also tracked and displayed for each sort method.

## Data Structures

### Stats Structure

A structure that holds statistical information about the sorting process.

- comparisons: An integer that stores how many comparisons are performed between elements during the sort

- swaps: This integer keeps track of the number of item movements during the sort process

### Arrays

Stores the initial randomly generated numbers before sorting begins.

arr: This will be a working copy of the original array and will be sorted based on the algorithm used. Both arrays are dynamically allocated based on the size entered by the user.

## Functions
swap: Points to two integers which are to be swapped.

bubbleSort: This function sorts the array using the bubble sort algorithm. Here, the function repeatedly iterates through the array and swaps elements if they are in the wrong order. This process continues until no more swaps are needed. In each comparison, the count is incremented.

selectionSort: Implements a selection sort on a given list. Separates the list into sorted and unsorted elements. Repeatedly finds the least element in the unsorted part and puts it at the beginning of the unsorted list. By keeping track of all comparison done to find each minimum.

insertionSort: Sorts an array using the insertion sort. The function constructs a new sorted array by inserting each element individually into the correct place relative to the other already sorted items. This includes counting both comparisons and movements of items as swaps.

merge: Merges two sorted sub-arrays and stores them as a single sorted list. It creates temporary arrays to hold the left and right portions of the list. It compares elements of both portions and stores them in sorted order within the original list. Dynamic storage is used.

mergeSortHelper: A helper function to divide the array into smaller arrays recursively.

mergeSort: The entry point for the merge sort algorithm.

generateRandomArray: This method generates random numbers between one and one thousand, filling the array with them.

printArray: Displays all elements of an array on the screen.

copyArray: Creates an identical copy of one array into another.


## Main Method Organization

Seeds the random number generator using the current time. This is to ensure different random numbers are produced every time.

Prompts the user to input the number of random integers to generate. Validates that the input is positive.

Dynamically allocates memory for two arrays: one for the original values and another for sorting. It verifies whether the allocation is successful.

Fills the original array with random integers that range from one to one thousand.

Shows a menu of four different sorting algorithms and asks a user to select a particular one by typing a number from one to four.

Copies the original array to the working array, thereby maintaining the original array for referencing purposes.

Sets the counters used for comparing and swapping sets to zero before the sorting process commences.

Prints all the numbers in their original random order.

Uses a switch statement to choose the right sorting function according to user choice. Indicates what algorithm is being used.

Prints all the numbers in their sorted order.

Displays the total number of comparisons done. Displays the total number of swaps made, except for merge sort.

Frees the memory allocated to both arrays. This should be done before the program terminates.

## Algorithm Descriptions

### Bubble Sort Algorithm
1. Start at the beginning of the array
2. Compare each pair of adjacent elements
3. If the first element is greater than the second, swap them
4. Move to the next pair and repeat
5. After each full pass, the largest unsorted element moves into its correct position
6. Repeat the process for remaining unsorted elements
7. Stop if no swaps occur during a complete pass

### Selection Sort Algorithm
1. Divide the array into sorted and unsorted sections
2. Find the smallest element in the unsorted portion
3. Replace it with the first element from the unsorted section.
4. Advance the Unsorted/Sidebar boundary one column to the right
5. Repeat until the entire array is sorted

### Insertion Sort Algorithm
1. Assume first element is already sorted
2. Take the next element from the unsorted part
3. Compare it with elements in the sorted portion moving from right to left
4. Shift larger elements one position to the right
5. Insert the element into its correct position 6. Repeat for all elements in the array

### Merge Sort Algorithm
1.  Divide the array into two halves
2. Divide each half recursively into individual elements.
3. Merging pairs of single elements into sorted pairs
4. Merge two or more sorted subarrays into larger sorted subarrays
5. Continue merging until the entire array is sorted.

## Sample Output

Enter the number of random integers to generate (N): 10

Choose a sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter your choice (1-4): 1

Numbers before sorting:
456 123 789 234 567 890 345 678 901 12

Numbers after sorting:
12 123 234 345 456 567 678 789 890 901

Statistics:
Total Comparisons: 45
Total Swaps: 23

