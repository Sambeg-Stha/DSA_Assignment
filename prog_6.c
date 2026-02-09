#include <stdio.h>
#include <stdlib.h>

// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify for max heap
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Build max heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Heapify for min heap
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Build min heap
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {12, 11, 13, 5, 6, 7, 15, 9, 8, 10};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("=== Min and Max Heap Construction ===\n\n");
    
    printf("Original Array: ");
    displayArray(data, n);
    
    // Build max heap
    int maxHeapArr[n];
    for (int i = 0; i < n; i++) {
        maxHeapArr[i] = data[i];
    }
    buildMaxHeap(maxHeapArr, n);
    
    printf("\nMax Heap: ");
    displayArray(maxHeapArr, n);
    
    // Build min heap
    int minHeapArr[n];
    for (int i = 0; i < n; i++) {
        minHeapArr[i] = data[i];
    }
    buildMinHeap(minHeapArr, n);
    
    printf("\nMin Heap: ");
    displayArray(minHeapArr, n);
    
    return 0;
}