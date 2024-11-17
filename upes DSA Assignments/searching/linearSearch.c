#include <stdio.h>

// Function to perform linear search
int linearSearch(int array[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return i; // Return the index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int main()
{
    int size, target, index;

    // Input size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Declare the array and input its elements
    int array[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    // Input the target value
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // Perform linear search
    index = linearSearch(array, size, target);

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
