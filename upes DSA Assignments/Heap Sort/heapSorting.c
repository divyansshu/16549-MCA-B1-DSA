#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index `i` in array `arr` of size `n`
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and recursively heapify
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a max heap from an array
void buildMaxHeap(int arr[], int n)
{
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to perform heap sort
void heapSort(int arr[], int n)
{
    // Step 1: Build max heap
    buildMaxHeap(arr, n);

    printf("Max heap built:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root (maximum element) to end
        swap(&arr[0], &arr[i]);

        // Reduce heap size and re-heapify root
        heapify(arr, i, 0);

        // Print the array after each step
        printf("Heap after extracting element %d:\n", arr[i]);
        for (int j = 0; j < n; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
}

int main()
{
    int n;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Perform heap sort
    heapSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
