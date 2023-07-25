#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct  TreeNode
{
    int data ;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* createNode(int data) 
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insertion
TreeNode* insertNode(TreeNode* root, int data) 
{
    if (root == NULL) 
    {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to write the tree nodes to a file (inorder traversal)
void writeTreeToFile(struct TreeNode* root, FILE* file) {
    if (root != NULL) {
        writeTreeToFile(root->left, file);
        fprintf(file, "%d ", root->data);
        writeTreeToFile(root->right, file);
    }
}

int main()
{
    TreeNode *root = NULL ;
    srand(time(0));
    int size ;
    printf("How many random numbers do you need to generate ? ");
    scanf("%d",&size);
    int numbers[size];
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 100;
    }

    FILE *fptr,*file;
    fptr = fopen("random_nos.txt","w");
    if(fptr== NULL)
    {
        printf("Error opening a file.");
        return 1 ;
    }
// Reading random numbers to a file 
    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "%d\n", numbers[i]);
    }
    fclose(fptr);

// Insertion 
    for (int i = 0; i < size ; i++) 
    {
        root = insertNode(root, numbers[i]);
    }
// Delete a particular node from the tree
    int key;
    printf("Enter the node to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);
    printf("Node %d deleted from the tree.\n", key);

    // Write the updated tree to a file
    file = fopen("updated_tree.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    writeTreeToFile(root, file);
    fclose(file);
    printf("Updated tree written to 'updated_tree.txt' file.\n");

    return 0;
}