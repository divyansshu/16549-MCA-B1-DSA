#include <stdio.h>

#define MAX_SIZE 100 // Define the maximum size of the tree array

// Declare the array to store the binary tree elements
int binaryTree[MAX_SIZE];

// Track the current number of elements in the binary tree
int currentSize = 0;

// Function to insert a node in the binary tree array
void insert(int value)
{
    if (currentSize >= MAX_SIZE)
    {
        printf("Binary Tree is full. Cannot insert more elements.\n");
        return;
    }
    binaryTree[currentSize] = value;
    printf("Inserted %d at index %d\n", value, currentSize);
    currentSize++;
}

// Function to display the binary tree elements in level order
void displayTree()
{
    if (currentSize == 0)
    {
        printf("The binary tree is empty.\n");
        return;
    }
    printf("Binary Tree in level order:\n");
    for (int i = 0; i < currentSize; i++)
    {
        printf("%d ", binaryTree[i]);
    }
    printf("\n");
}

// Helper functions to find the index of left and right children
int leftChild(int index)
{
    int leftIndex = 2 * index + 1;
    return (leftIndex < currentSize) ? binaryTree[leftIndex] : -1;
}

int rightChild(int index)
{
    int rightIndex = 2 * index + 2;
    return (rightIndex < currentSize) ? binaryTree[rightIndex] : -1;
}

// Function to display the children of each node
void displayChildren()
{
    if (currentSize == 0)
    {
        printf("The binary tree is empty.\n");
        return;
    }
    printf("Children of each node:\n");
    for (int i = 0; i < currentSize; i++)
    {
        printf("Node %d: Left Child = %d, Right Child = %d\n",
               binaryTree[i], leftChild(i), rightChild(i));
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display Tree\n");
        printf("3. Display Children of Each Node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            displayTree();
            break;
        case 3:
            displayChildren();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
