#include <stdio.h>
#include <stdlib.h>

// Define a structure for a tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// In-order Traversal: Left -> Root -> Right
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Pre-order Traversal: Root -> Left -> Right
void preorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Post-order Traversal: Left -> Right -> Root
void postorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Level-order Traversal: Level by Level
void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    // Using an array as a queue to store nodes of each level
    struct Node *queue[100];
    int front = 0, rear = 0;

    // Enqueue root node
    queue[rear++] = root;

    while (front < rear)
    {
        struct Node *current = queue[front++];

        // Print current node's data
        printf("%d ", current->data);

        // Enqueue left child
        if (current->left != NULL)
            queue[rear++] = current->left;

        // Enqueue right child
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

// Main function to test the traversal methods
int main()
{
    // Creating a sample binary tree
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Level-order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
