#include <stdio.h>

// Function to perform binary search
int binarySearch(int array[], int size, int target)
{
    int left = 0, right = size - 1;

    printf("Binary Search Steps:\n");
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Calculate mid-point

        printf("Left: %d, Right: %d, Mid: %d, Value at Mid: %d\n",
               left, right, mid, array[mid]);

        if (array[mid] == target)
        {
            return mid; // Target found
        }
        else if (array[mid] < target)
        {
            left = mid + 1; // Search the right half
        }
        else
        {
            right = mid - 1; // Search the left half
        }
    }

    return -1; // Target not found
}

int main()
{
    int size, target, index;

    // Input size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Declare the array and input its elements
    int array[size];
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    // Input the target value
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // Perform binary search
    index = binarySearch(array, size, target);

    // Output the result
    if (index != -1)
    {
        printf("Target value %d found at index %d.\n", target, index);
    }
    else
    {
        printf("Target value %d not found in the array.\n", target);
    }

    return 0;
}
