#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TreeNode *createNode(int data);
void insertLevelOrder(struct TreeNode **, int);
void levelOrderTraversal(struct TreeNode *root);
int getHeight(struct TreeNode *node);
void printLevel(struct TreeNode *node, int level);

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert an element in level order
void insertLevelOrder( struct TreeNode **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }

    struct TreeNode *temp = createNode(data);
    struct TreeNode *node;
    int isInserted = 0;

    while (!isInserted)
    {
        if ((*root)->left == NULL)
        {
            (*root)->left = temp;
            isInserted = 1;
        }
        else if ((*root)->right == NULL)
        {
            (*root)->right = temp;
            isInserted = 1;
        }
        else
        {
            if ((*root)->left != NULL)
            {
                node = (*root)->left;
                isInserted = insertLevelOrder(&node, data);
            }
            if (!isInserted && (*root)->right != NULL)
            {
                node = (*root)->right;
                isInserted = insertLevelOrder(&node, data);
            }
        }
    }
}

void levelOrderTraversal(struct TreeNode *root)
{
    int height = getHeight(root);
    int i;
    for (i = 1; i <= height; i++)
    {
        printLevel(root, i);
    }
}

// Function to get the height of a tree
int getHeight(struct TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1 ;
        }
        else
        {
            return rightHeight + 1 ;
        }
    }
}

void printLevel(struct TreeNode *node, int level)
{
    if (node == NULL)
    {
        return;
    }
    if (level == 1)ata);
    }
    else if (level > 1)
    {
        printLevel(node->left, lev
    {
        printf("%d ", node->del - 1);
        printLevel(node->right, level - 1);
    }
}

int main()
{
    FILE *file = fopen("random_numbers.txt", "w");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    srand(time(NULL));  

    int i, num;
    for (i = 0; i < 10; i++)
    {                                
        num = rand() % 100;          
        fprintf(file, "%d\n", num);  
    }
    struct TreeNode *root = NULL;
    while (fscanf(file, "%d", &num) != EOF)
    {
        insertLevelOrder(&root, num);
    }

    printf("Level Order Traversal of the tree: ");
    levelOrderTraversal(root);
    return 0;
}



