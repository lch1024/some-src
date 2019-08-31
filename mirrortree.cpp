#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    Node *left;
    Node *right;
};

int g_value = 1;
void instertNode(Node **pNode, int ndepth, int value)
{
    *pNode = (Node *)malloc(sizeof(Node));
    Node *root = *pNode;
    root->value = value;
    root->left  = NULL;
    root->right = NULL;
    printf("%d ", value);
    if(ndepth)
    {
        
	instertNode(&(root->left), ndepth - 1, ++g_value);
	instertNode(&(root->right), ndepth - 1, ++g_value);
    }
}

Node* deleteNode(Node *root)
{
    if(root == NULL)
    {
        return root;
    }

    deleteNode(root->left);
    deleteNode(root->right);
    free(root);
    root = NULL;
}

Node* floop(Node *root)
{
    if(root == NULL)
    {
        return root;
    }
    
    floop(root->left);
    printf("%d", root->value);
    floop(root->right);	
}

Node* reserve(Node *root)
{
    if(root == NULL)
    {
        return root;
    }
 
    Node *tmp = reserve(root->left);
    root->left = reserve(root->right);
    root->right = tmp;
}

int main()
{

    Node *root = NULL;
    instertNode(&root, 2, g_value);
    printf("\r\n");
    floop(root);
    printf("\r\n");
    reserve(root);
    floop(root);
    deleteNode(root);

    getchar();
    return 0;
}





