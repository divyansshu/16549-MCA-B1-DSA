#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node with given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the doubly linked list
void insertAtFront(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    printf("\n%d is inserted at front of doubly linked list", newNode->data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    printf("\n%d is inserted at end of doubly linked list", newNode->data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node at a specified position in the doubly linked list
void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (position == 1)
    {
        insertAtFront(head, data);
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("\n%d is inserted at position %d of doubly linked list", newNode->data, position);
}

// Function to delete a node from the front of the doubly linked list
void deleteFromFront(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    printf("\n%d is deleted from front of list", temp->data);
    free(temp);
}

// Function to delete a node from the end of the doubly linked list
void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    printf("\n%d is deleted from end of list", temp->data);
    free(temp);
}

// Function to delete a node from a specified position in the doubly linked list
void deleteFromPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    if (position == 1)
    {
        deleteFromFront(head);
        return;
    }
    for (int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    printf("\n%d is deleted from postion %d front of list", temp->data, position);
    free(temp);
}

// Function to display the doubly linked list
void display(struct Node *head)
{
    printf("\ndisplaying list\n");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the doubly linked list
void reverse(struct Node **head)
{
    struct Node *temp = NULL;
    struct Node *current = *head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtFront(&head, 5);
    insertAtPosition(&head, 15, 3);
    printf("\n");
    display(head); // Output: 5 10 15 20 30

    deleteFromFront(&head);
    display(head); // Output: 10 15 20 30

    deleteFromEnd(&head);
    display(head); // Output: 10 15 20

    deleteFromPosition(&head, 2);
    display(head); // Output: 10 20

    reverse(&head);
    display(head); // Output: 20 10

    return 0;
}