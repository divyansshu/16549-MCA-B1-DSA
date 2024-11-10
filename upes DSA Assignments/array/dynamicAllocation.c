#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *arr;      // Pointer to hold the dynamically allocated memory
    int sum = 0;   // Variable to store the sum of elements
    float average; // Variable to store the average of elements

    // Step 1: Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Allocate memory dynamically using malloc
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    { // Check if memory allocation was successful
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 3: Input n elements into the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i]; // Accumulate the sum
    }

    // Step 4: Calculate the sum and average of the elements
    average = (float)sum / n;

    // Display the sum and average
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", average);

    // Step 5: Release the memory using free
    free(arr);

    return 0;
}
