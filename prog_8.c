
#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>    

// Structure to hold sorting statistics
typedef struct {
    int comparisons;  // Counter for element comparisons
    int swaps;        // Counter for element swaps/moves
} Stats;

// Global statistics variable accessible by all sorting functions
Stats stats;

//swap
void swap(int *a, int *b) {
    int temp = *a;      // Store first value temporarily
    *a = *b;            // Assign second value to first
    *b = temp;          // Assign stored value to second
    stats.swaps++;      // Increment swap counter
}

//Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
    int i, j;
    // Outer loop: controls number of passes
    for (i = 0; i < n - 1; i++) {
        // Inner loop: compares adjacent elements
        for (j = 0; j < n - i - 1; j++) {
            stats.comparisons++;  // Count this comparison
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);  // Swap if out of order
            }
        }
    }
}

//Selection Sort Algorithm

void selectionSort(int arr[], int n) {
    int i, j, minIdx;
    // Outer loop: moves boundary of sorted/unsorted portions
    for (i = 0; i < n - 1; i++) {
        minIdx = i;  // Assume current position has minimum
        // Inner loop: finds actual minimum in unsorted portion
        for (j = i + 1; j < n; j++) {
            stats.comparisons++;  // Count this comparison
            if (arr[j] < arr[minIdx]) {
                minIdx = j;  // Update minimum index
            }
        }
        // Swap minimum element to its correct position
        if (minIdx != i) {
            swap(&arr[i], &arr[minIdx]);
        }
    }
}


//Insertion Sort Algorithm
void insertionSort(int arr[], int n) {
    int i, j, key;
    // Start from second element (first is considered sorted)
    for (i = 1; i < n; i++) {
        key = arr[i];  // Element to be inserted
        j = i - 1;
        // Shift elements greater than key to the right
        while (j >= 0) {
            stats.comparisons++;  // Count this comparison
            if (arr[j] > key) {
                arr[j + 1] = arr[j];  // Shift element right
                stats.swaps++;        // Count as a swap/move
                j--;
            } else {
                break;  // Found correct position
            }
        }
        arr[j + 1] = key;  // Insert key at correct position
    }
}

//Merge Function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;     // Size of right subarray
    
    // Allocate temporary arrays for left and right subarrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    int i, j, k;
    
    // Copy data to temporary left array
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    
    // Copy data to temporary right array
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge temporary arrays back into original array
    i = 0;  // Initial index of left subarray
    j = 0;  // Initial index of right subarray
    k = left;  // Initial index of merged array
    
    // Compare and merge elements from both subarrays
    while (i < n1 && j < n2) {
        stats.comparisons++;  // Count this comparison
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements from left subarray if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy remaining elements from right subarray if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    // Free temporary arrays
    free(L);
    free(R);
}

//Merge Sort Helper Function
void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find middle point
        mergeSortHelper(arr, left, mid);      // Sort left half
        mergeSortHelper(arr, mid + 1, right); // Sort right half
        merge(arr, left, mid, right);         // Merge sorted halves
    }
}

//Merge Sort Algorithm Entry Point
void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);  // Call helper with full array bounds
}

//Generates random integers in range [1, 1000]
void generateRandomArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;  // Random number between 1 and 1000
    }
}

//Prints all elements of an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);  // Print each element
    }
    printf("\n");  // New line after array
}

//Copies elements from source array to destination array

void copyArray(int source[], int dest[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        dest[i] = source[i];  // Copy each element
    }
}

int main() {
    int n, choice;
    
    // Seed random number generator with current time
    srand(time(NULL));
    
    printf("Enter the number of random integers to generate (N): ");
    scanf("%d", &n);
    
    // Validate input
    if (n <= 0) {
        printf("Invalid input. N must be positive.\n");
        return 1;
    }
    
    int *original = (int *)malloc(n * sizeof(int));  // Original random array
    int *arr = (int *)malloc(n * sizeof(int));       // Working array for sorting
    
    if (original == NULL || arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    //Generate random numbers
    generateRandomArray(original, n);
    
    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    //Copy original array to working array
    copyArray(original, arr, n);
    
    //Reset statistics counters
    stats.comparisons = 0;
    stats.swaps = 0;
    
    //Display array before sorting
    printf("\nNumbers before sorting:\n");
    printArray(arr, n);
    
    //Execute chosen sorting algorithm
    switch (choice) {
        case 1:
            printf("\nUsing Bubble Sort...\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("\nUsing Selection Sort...\n");
            selectionSort(arr, n);
            break;
        case 3:
            printf("\nUsing Insertion Sort...\n");
            insertionSort(arr, n);
            break;
        case 4:
            printf("\nUsing Merge Sort...\n");
            mergeSort(arr, n);
            printf("Note: Merge Sort does not count swaps.\n");
            break;
        default:
            printf("Invalid choice.\n");
            free(original);  // Clean up memory
            free(arr);
            return 1;
    }
    
    // Display sorted array
    printf("\nNumbers after sorting:\n");
    printArray(arr, n);
    
    //Display sorting statistics
    printf("\nStatistics:\n");
    printf("Total Comparisons: %d\n", stats.comparisons);
    if (choice != 4) {
        printf("Total Swaps: %d\n", stats.swaps);
    }
    
    //Free allocated memory
    free(original);
    free(arr);
    
    return 0;
}