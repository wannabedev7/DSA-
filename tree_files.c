#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct NODE
{
	int data;
	struct NODE *left;
	struct NODE *right;
	int height;
}Node;
FILE *fp,*pre;

int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
int max(int a, int b)
{
	return (a > b)? a : b;
}

Node* newNode(int key)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;  
	return(node);
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;
	return x;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;


	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	return y;
}

int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* root, int key)
{
	
	if (root == NULL)
		return(newNode(key));

	if (key < root->data)
		root->left = insert(root->left, key);
	else if (key > root->data)
		root->right = insert(root->right, key);
	else 
		return root;

	root->height = 1 + max(height(root->left),
						height(root->right));


	int balance = getBalance(root);

	if (balance > 1 && key < root->left->data)
		return rightRotate(root);

    if (balance < -1 && key > root->right->data)
		return leftRotate(root);


	if (balance > 1 && key > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	
	if (balance < -1 && key < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}


void preOrder(Node *root)
{
	if(root == NULL){
        return ;
    }
	else{
          fprintf(pre,"%d\n",root->data);
		printf("%d->", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}


int main()
{
    Node *root = NULL;
    pre=fopen("pre.txt","w+");

    srand(time(NULL));
    fp=fopen("insert.txt","w+");
    int n,val;
    printf("Enter the number of random numbers\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        val=(rand()%100)+1;
        fprintf(fp,"%d\n",val);
}
     rewind(fp);
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&val);
        root=insert(root,val);
    }
preOrder(root);
return 0;
}
