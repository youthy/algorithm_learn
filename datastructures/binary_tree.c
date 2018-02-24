#include <stdio.h>
#include <stdlib.h>

// tree node struct
typedef struct TNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
} TNode;

// return tree height
int height(TNode *root)
{
    if (root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return (lheight > rheight ? lheight : rheight) + 1;
}

// print given level
void printGivenLevel(TNode *tree, int level)
{
    if(level < 1)
        return; 
    if(level == 1)
        printf("%d", tree->data);
    else
    {
        printGivenLevel(tree->left, level - 1);
        printGivenLevel(tree->right, level - 1);
    }
}

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
    printf("%d ", root->data);
}

void inOrder(TNode *root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(TNode *root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void levelOrder(TNode *root)
{
    if(root == NULL)
        return;
    int h = height(root);
    for(int i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

int findPos(int arr[], int data, int start, int end)
{
    for(int i = start;i <= end; i++)
    {
        if(arr[i] == data)
            return i;
    }
    return -1;
}

// build tree from preorder and in order
// p_start p_end is index range in preOrder, preOrder[p_start] is the root node. then from i_start to i_end in inOrder find
// pos of root data, then the i_start to root_pos - 1 is left tree, root_pos + 1, i_end is right tree
struct TNode *buildTree(int inOrder[], int preOrder[], int p_start, int p_end, int i_start, int i_end)
{
    if(p_start > p_end)
        return NULL;
    TNode *root = newNode(preOrder[p_start]);
    if(p_start == p_end)
        return root;
    int root_pos = findPos(inOrder, preOrder[p_start], i_start, i_end);
    root->left = buildTree(inOrder, preOrder, p_start + 1, p_start + root_pos - i_start, i_start, root_pos - 1);
    root->right = buildTree(inOrder, preOrder, p_start + root_pos - i_start + 1, p_end, root_pos + 1, i_end);
    return root;
}

int main(void)
{
    int in[11] = {8,4,9,2,10,5,11,1,6,3,7};
    int pre[11] = {1,2,4,8,9,5,10,11,3,6,7};
    TNode *tree = buildTree(in, pre, 0, 10, 0, 10);
    preOrder(tree);
    inOrder(tree);
    levelOrder(tree);
    printf("height:%d", height(tree));
    return 0;
}
