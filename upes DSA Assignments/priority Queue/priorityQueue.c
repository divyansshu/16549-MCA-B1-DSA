#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the priority queue
#define MAX_SIZE 100

// Structure to represent an element with its priority
typedef struct
{
    int data;
    int priority;
} Element;

// Array to store the heap
Element priorityQueue[MAX_SIZE];
int currentSize = 0;

// Function to swap two elements
void swap(Element *a, Element *b)
{
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index `i`
void heapify(int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Compare left child with root
    if (left < currentSize && priorityQueue[left].priority > priorityQueue[largest].priority)
        largest = left;

    // Compare right child with largest so far
    if (right < currentSize && priorityQueue[right].priority > priorityQueue[largest].priority)
        largest = right;

    // If largest is not root, swap and recursively heapify
    if (largest != i)
    {
        swap(&priorityQueue[i], &priorityQueue[largest]);
        heapify(largest);
    }
}

// Function to insert an element into the priority queue
void insert(int data, int priority)
{
    if (currentSize >= MAX_SIZE)
    {
        printf("Priority Queue Overflow! Cannot insert more elements.\n");
        return;
    }

    // Add the new element at the end
    int i = currentSize;
    priorityQueue[i].data = data;
    priorityQueue[i].priority = priority;
    currentSize++;

    // Move the element up to maintain heap property
    while (i != 0 && priorityQueue[(i - 1) / 2].priority < priorityQueue[i].priority)
    {
        swap(&priorityQueue[i], &priorityQueue[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("Inserted element: %d with priority: %d\n", data, priority);
}

// Function to remove and return the element with the highest priority
void removeHighestPriority()
{
    if (currentSize == 0)
    {
        printf("Priority Queue Underflow! No elements to remove.\n");
        return;
    }

    // The root element is the highest priority
    Element highestPriorityElement = priorityQueue[0];
    printf("Removed element: %d with priority: %d\n", highestPriorityElement.data, highestPriorityElement.priority);

    // Move the last element to the root and reduce size
    priorityQueue[0] = priorityQueue[currentSize - 1];
    currentSize--;

    // Re-heapify to restore heap property
    heapify(0);
}

// Function to display the elements in the priority queue
void displayQueue()
{
    if (currentSize == 0)
    {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements (data, priority):\n");
    for (int i = 0; i < currentSize; i++)
    {
        printf("(%d, %d) ", priorityQueue[i].data, priorityQueue[i].priority);
    }
    printf("\n");
}

int main()
{
    int choice, data, priority;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Remove the highest priority element\n");
        printf("3. Display the priority queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            insert(data, priority);
            break;
        case 2:
            removeHighestPriority();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
