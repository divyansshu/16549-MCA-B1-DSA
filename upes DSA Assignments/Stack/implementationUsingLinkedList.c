#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node
{
    int data;
    struct Node *next;
};

// Initialize the top of the stack as NULL
struct Node *top = NULL;

// Function to check if the stack is empty
int isEmpty(struct Node *top)
{
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node **top, int data)
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
        // Set the data for the new node
        newNode->data = data;
        printf("pushed %d into the stack", newNode->data);

        // If the stack is empty, set the new node as the top
        if (isEmpty(*top))
        {
            *top = newNode;
            return;
        }

        // Otherwise, link the new node to the current top and update the top
        newNode->next = *top;
        *top = newNode;
    }
}

// Function to pop an element from the stack
void pop(struct Node **top)
{
    // Check if the stack is empty
    if (isEmpty(*top))
    {
        printf("stack underflow\n");
        return;
    }
    else
    {
        // Remove the top element and update the top
        struct Node *temp = *top;
        *top = temp->next;
        printf("popped %d from stack", temp->data);
        free(temp);
    }
}

// Function to peek at the top element of the stack without removing it
void peek(struct Node **top)
{
    // Check if the stack is empty
    if (isEmpty(*top))
    {
        printf("stack underflow\n");
        return;
    }
    // Print the top element of the stack
    printf("top element of stack is: %d\n", (*top)->data);
}

// Function to display the elements of the stack
void display(struct Node *top)
{
    // Check if the stack is empty
    if (isEmpty(top))
    {
        printf("stack underflow\n");
        return;
    }
    else
    {
        printf("stack elements\n");
        struct Node *temp = top;
        // Traverse the stack and print each element
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    // Infinite loop to keep the program running until the user chooses to exit
    while (1)
    {
        printf("\n1. Push\n2. Pop \n3. Peek \n4. Display \n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Push an element onto the stack
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);
            push(&top, value);
            break;

        case 2:
            // Pop an element from the stack
            pop(&top);
            break;

        case 3:
            //peek top element from stack
            peek(&top);
            break;

        case 4:
            // Display the elements of the stack
            display(top);
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
}