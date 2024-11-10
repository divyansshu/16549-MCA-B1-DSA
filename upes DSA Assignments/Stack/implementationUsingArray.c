#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the stack

int stack[MAX]; // Array to hold stack elements
int top = -1; // Initialize top of stack to -1 (indicating stack is empty)

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
     return top == MAX - 1;
}

// Function to push an element onto the stack
void push(int data)
{
     if (isFull())
     {
          printf("Stack overflow\n");
          return;
     }
     else
     {
          top++;
          stack[top] = data;
          printf("pushed %d in the stack\n", data);
     }
}

// Function to pop an element from the stack
int pop()
{
     if (isEmpty())
     {
          printf("stack underflow\n");
          return -1;
     }
     else
     {
          int popped = stack[top];
          top--;
          return popped;
     }
}

// Function to peek the top element of the stack
int peek()
{
     if (isEmpty())
     {
          printf("stack underflow\n");
          return -1;
     }
     else
     {
          return stack[top];
     }
}

// Function to display all elements in the stack
void display()
{
     if (isEmpty())
     {
          printf("stack is empty\n");
          return;
     }
     else
     {
          printf("stack elements:\n");
          for (int i = top; i >= 0; i--)
          {
                printf("%d ", stack[i]);
          }
          printf("\n");
     }
}

int main()
{
     printf("Stack implementation using array\n");

     int choice, value;

     while (1)
     {
         
          printf("1 for push\n");
          printf("2 for pop\n");
          printf("3 for peek\n");
          printf("4 display\n");
          printf("5 exit\n");
          printf("enter the choice: ");
          scanf("%d", &choice);

          switch (choice)
          {
          case 1:
                printf("enter the element to push into stack\n");
                scanf("%d", &value);
                push(value);
                break;

          case 2:
                printf("\npopped value from stack is %d\n", pop());
                break;

          case 3:
                printf("\ntop element from stack %d\n", peek());
                break;

          case 4:
                display();
                break;

          case 5:
                exit(0);
                break;

          default:
                printf("Invalid choice! please try again\n");
          }
     }

     return 0;
}