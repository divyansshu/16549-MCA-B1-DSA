#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the linked list
void insertAtFront(struct Node **head , int data) {
    struct Node* newNode = createNode(data);

    if(*head == NULL) {
      *head = newNode;
      return; 
    }
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node **head, int data) {
    struct Node* newNode = createNode(data);

    if(*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific index in the linked list
void insertAtIndex(struct Node **head, int data, int pos) {
    struct Node* newNode = createNode(data);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

   struct Node* temp = *head;
   for(int i = 1; temp != NULL && i < pos-1; i++) {
    temp = temp->next;
   }
   if(temp == NULL) {
    printf("position is out of range of linked list\n");
    free(newNode);
    return;
   }
        newNode->next = temp->next;
        temp->next = newNode;
    }

// Function to delete the node at the front of the linked list
void deleteAtFront(struct Node** head) {
    if(*head == NULL) {
        printf("Linked List is empty\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the node at the end of the linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    struct Node* curr = *head;

    if(curr->next == NULL) {
        free(curr);
        *head = NULL;
        return;
    }

    while(curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

// Function to delete a node at a specific index in the linked list
void deleteAtIndex(struct Node** head, int index) {
    int i = 0;
    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    if(index == 1) {
        deleteAtFront(head);
        return;
    }

    struct Node* temp = *head;
    for(int i = 1; temp!= NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL) {
        printf("index out of range\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;     
}

// Function to print the linked list
void print(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* head = NULL;

    printf("Linked list implementation in C language\n");
    insertAtFront(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    print(head);

    printf("Linked list after inserting the node:20 at the end \n");
    insertAtEnd(&head, 20);
    print(head);

    printf("Linked list after inserting the node:5 at the end \n");
    insertAtEnd(&head, 5);
    print(head);

    printf("Linked list after inserting the node:30 at the end \n");
    insertAtEnd(&head, 30);
    print(head);

    printf("Linked list after inserting the node:15 at position 4 \n");
    insertAtIndex(&head, 15, 4);
    print(head);

    printf("Linked list after deleting the first node: \n");
    deleteAtFront(&head);
    print(head);

    printf("Linked list after deleting the last node: \n");
    deleteAtEnd(&head);
    print(head);

    printf("Linked list after deleting the node at position 1: \n");
    deleteAtIndex(&head, 1);
    print(head);

    return 0;
}