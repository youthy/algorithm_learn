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
    if(tree == NULL)
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

//******    TRAVERSAL   ******/
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

//*********** constructions of tree
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

// build tree from inorder and level order without queue  space wasted a lot
struct TNode *buildTreeInLevelOrder(int inOrder[], int levelOrder[], int i_start, int i_end)
{
    if(i_start > i_end)
        return NULL;
    TNode *root = newNode(levelOrder[0]);
    if(i_start == i_end)
        return root;
    int node_count = i_end - i_start + 1;
    int root_pos = findPos(inOrder, levelOrder[0], i_start, i_end);
    int left_count = root_pos - i_start;
    int right_count = i_end - root_pos;
    if(left_count != 0)
    {
        int leftLevelOrder[left_count];
        int j = 0;
        for (int i = 1; i < node_count; i++)
        {
            for(int m = i_start; m < root_pos; m++)
            {
                if(inOrder[m] == levelOrder[i])
                {
                    leftLevelOrder[j] = levelOrder[i];
                    j++;
                    break;
                }
            }
            if(j > left_count - 1)
                break;
        }
        root->left = buildTreeInLevelOrder(inOrder, leftLevelOrder, i_start, root_pos - 1);
    }
    if(right_count != 0)
    {
        int rightLevelOrder[right_count];
        int j = 0;
        for (int i = 1; i < node_count; i++)
        {
            for(int m = root_pos + 1; m <= i_end; m++)
            {
                if(inOrder[m] == levelOrder[i])
                {
                    rightLevelOrder[j] = levelOrder[i];
                    j++;
                    break;
                }
            }
            if(j > right_count - 1)
                break;
        }
        root->right = buildTreeInLevelOrder(inOrder, rightLevelOrder, root_pos + 1, i_end);
    }
    return root;
}

//*********** find lowest common ancestor
struct TNode *findLCA(TNode *tree, int n1, int n2)
{
    if(!tree) return NULL;
    if(tree->data == n1 || tree->data == n2) return tree;
    TNode *leftLCA = findLCA(tree->left, n1, n2);
    TNode *rightLCA = findLCA(tree->right, n1, n2);
    if(leftLCA && rightLCA) return tree;
    return (leftLCA == NULL)? rightLCA:leftLCA;
}

//*********** calc distance between two nodes
int dist(TNode *root, int n1, int level)
{
    if(root == NULL) return -1;
    if(root -> data == n1) return level;
    int leftdist = dist(root->left, n1, level + 1);
    int rightdist = dist(root->right, n1, level + 1);
    return leftdist > rightdist ? leftdist : rightdist;
}
// distance between two nodes is dist to A, dist to B - 2 * LCA
int dist_between(TNode *root, int n1, int n2)
{
    if(n1 == n2)
        return 0;
    TNode *lca = findLCA(root, n1, n2);
    int dist_to_lca = dist(root, lca->data, 0);
    int dist_to_n1 = dist(root, n1, 0);
    int dist_to_n2 = dist(root, n2, 0);
    return dist_to_n1 + dist_to_n2 - 2 * dist_to_lca;
}
        
int main(void)
{
    int in[11] = {8,4,9,2,10,5,11,1,6,3,7};
    int pre[11] = {1,2,4,8,9,5,10,11,3,6,7};
    int lv[11] = {1,2,3,4,5,6,7,8,9,10,11};
    TNode *tree = buildTree(in, pre, 0, 10, 0, 10);
    TNode *tree2 = buildTreeInLevelOrder(in, lv, 0, 10);
    preOrder(tree);
    inOrder(tree);
    levelOrder(tree);
    printf("height:%d", height(tree));
    levelOrder(tree2);
    printf("lca of 8,9:%d\n", (findLCA(tree, 8, 9))->data);
    printf("lca of 8,10:%d\n", (findLCA(tree, 8, 10))->data);
    printf("dist between 8,9:%d", dist_between(tree, 8, 9));
    return 0;
}
