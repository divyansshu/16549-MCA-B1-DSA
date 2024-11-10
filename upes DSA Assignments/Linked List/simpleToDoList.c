#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node
struct Task
{
    char description[100];
    struct Task *next;
};

struct Task *head = NULL; // Initialize the head of the list to NULL

// Function to add a task to the list
void addTask(char *description)
{
    struct Task *newTask = (struct Task *)malloc(sizeof(struct Task)); // Allocate memory for the new task
    if (newTask == NULL)
    {
        printf("Memory allocation failed. Cannot add task.\n");
        return;
    }
    strcpy(newTask->description, description); // Set the description of the new task
    newTask->next = NULL;

    if (head == NULL)
    { // If the list is empty, the new task becomes the head
        head = newTask;
    }
    else
    {
        struct Task *temp = head;
        while (temp->next != NULL)
        { // Traverse to the end of the list
            temp = temp->next;
        }
        temp->next = newTask; // Add the new task at the end
    }
    printf("Task added: %s\n", description);
}

// Function to complete (remove) the first task from the list
void completeTask()
{
    if (head == NULL)
    {
        printf("No tasks to complete!\n");
        return;
    }
    struct Task *temp = head; // Temporary pointer to store the head task
    head = head->next;        // Move head to the next task
    printf("Task completed: %s\n", temp->description);
    free(temp); // Free the memory of the completed task
}

// Function to display all tasks in the list
void displayTasks()
{
    if (head == NULL)
    {
        printf("No tasks in the list!\n");
        return;
    }
    struct Task *temp = head;
    printf("To-Do List:\n");
    while (temp != NULL)
    {
        printf("- %s\n", temp->description);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    char description[100];

    while (1)
    {
        printf("\n1. Add Task\n2. Complete Task\n3. Display Tasks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        switch (choice)
        {
        case 1:
            printf("Enter the task description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0'; // Remove the newline character
            addTask(description);
            break;

        case 2:
            completeTask();
            break;

        case 3:
            displayTasks();
            break;

        case 4:
            exit(0); // Exit the program

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
