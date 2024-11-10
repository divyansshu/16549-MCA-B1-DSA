#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct Node
{
    int data;
    struct Node *next;
};

// Initialize front and rear pointers to NULL
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to check if the queue is empty
int isEmpty()
{
    return (front == NULL && rear == NULL);
}

// Function to add an element to the queue
void enqueue(int data)
{
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL)
    {
        printf("queue overflow: unable to allocate memory\n");
        return;
    }
    else
    {
        // Assign data to the new node and set its next pointer to NULL
        newNode->data = data;
        newNode->next = NULL;
        printf("%d is added to queue", data);

        // If the queue is empty, both front and rear will point to the new node
        if (isEmpty())
        {
            front = rear = newNode;
            return;
        }
        else
        {
            // Otherwise, add the new node at the end and update the rear pointer
            rear->next = newNode;
            rear = newNode;
            return;
        }
    }
}

// Function to remove an element from the queue
void dequeue()
{
    // Check if the queue is empty
    if (isEmpty())
    {
        printf("queue underflow\n");
        return;
    }
    else
    {
        // Store the front node in a temporary variable
        struct Node *temp = front;
        // Move the front pointer to the next node
        front = temp->next;
        printf("%d removed from queue", temp->data);
        // Free the memory of the dequeued node
        free(temp);

        // If the queue becomes empty after dequeue, set rear to NULL
        if (front == NULL)
        {
            rear = NULL;
        }
    }
}

// Function to peek at the front element of the queue
void peek()
{
    // Check if the queue is empty
    if (isEmpty())
    {
        printf("queue underflow\n");
        return;
    }

    // Print the front element of the queue
    printf("top element of queue is: %d\n", front->data);
}

// Function to display the elements of the queue
void display()
{
    // Check if the queue is empty
    if (isEmpty())
    {
        printf("queue underflow\n");
        return;
    }
    else
    {
        // Traverse the queue and print each element
        struct Node *temp = front;
        printf("Queue Elements:\n");
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function to drive the program
int main()
{
    int choice, value;

    printf("Queue implementation using linked list\n");

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue \n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Enqueue an element
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            // Dequeue an element
            dequeue();
            break;

        case 3:
            // Peek top element of queue
            peek();
            break;

        case 4:
            // Display queue elements
            display();
            break;

        case 5:
            // Exit the program
            exit(0);
            break;

        default:
            // Handle invalid choices
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}