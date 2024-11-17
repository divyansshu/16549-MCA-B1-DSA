#include <stdio.h>
#include <stdlib.h>

// Node structure for the AVL tree
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Helper function to get the height of a node
int height(struct Node *node)
{
    return node ? node->height : 0;
}

// Helper function to calculate the balance factor
int getBalance(struct Node *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

// Function to create a new node
struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Right rotation
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Left rotation
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Insertion in AVL Tree
struct Node *insert(struct Node *node, int key)
{
    // Perform standard BST insertion
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    // Update height of this ancestor node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // Perform rotations if the node becomes unbalanced

    // Left-Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right-Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left-Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find the node with the minimum value in the subtree
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Deletion in AVL Tree
struct Node *deleteNode(struct Node *root, int key)
{
    // Perform standard BST deletion
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with one child or no child
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        }
        else
        {
            // Node with two children
            struct Node *temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node
    if (root == NULL)
        return root;

    // Update height
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // Get the balance factor
    int balance = getBalance(root);

    // Perform rotations if the node becomes unbalanced

    // Left-Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left-Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right-Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to print the tree in in-order traversal
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Function to display the tree structure
void displayTree(struct Node *root, int level)
{
    if (root == NULL)
        return;

    displayTree(root->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", root->key);
    displayTree(root->left, level + 1);
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display In-Order Traversal\n");
        printf("4. Display Tree Structure\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted %d into AVL tree.\n", value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Deleted %d from AVL tree (if existed).\n", value);
            break;
        case 3:
            printf("In-Order Traversal: ");
            inOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Tree Structure:\n");
            displayTree(root, 0);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
