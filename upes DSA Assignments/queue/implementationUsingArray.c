#include <stdio.h>
#include <stdlib.h>

#define Max 5 // Define the maximum size of the queue

int queue[Max]; // Array to store queue elements
int front = -1; // Index of the front element
int rear = -1;  // Index of the rear element

// Function to check if the queue is full
int isFull()
{
    return rear == Max - 1;
}

// Function to check if the queue is empty
int isEmpty()
{
    return (front == -1 || front > rear);
}

// Function to add an element to the queue
void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0; // Initialize front if queue was empty
    }
    rear++;
    queue[rear] = data;
    printf("Enqueue the %d element into the queue\n", data);
}

// Function to remove an element from the queue
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        printf("Dequeued the %d element from the queue\n", queue[front]);
        front++;

        // Reset front and rear if the queue becomes empty
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

// Function to get the front element of the queue without removing it
void peek()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Top element of queue is: %d\n", queue[front]);
}

// Function to display the elements of the queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        // Display menu options
        printf("\n1. Enqueue\n2. Dequeue \n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Enqueue operation
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            // Dequeue operation
            dequeue();
            break;

        case 3:
            // peek top element of queue
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
