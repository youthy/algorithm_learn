#include <stdio.h>
#include <stdlib.h>

// tree node struct
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} TNode;

// function return node
TNode *newNode(int data)
{
    TNode *new = (TNode *)malloc(sizeof(TNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

/******    TRAVERSAL   ******/
void postOrder(TNode *root)
{
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d", root->data);
}

void inOrder(TNode *root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d", root->data);
    inOrder(root->right);
}

void preOrder(TNode *root)
{
    if(root == NULL)
        return;
    printf("%d", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main(void)
{
}
