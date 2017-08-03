#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *left, *right;
};

struct node *newNode(int data){
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->key = data;
    root->left = root->right = NULL;
    return root;
}

struct node *insert(struct node *pNode, int data){
    if(pNode == NULL){
        return newNode(data);
    }
    else if(pNode->key < data)
        pNode->right = insert(pNode->right, data);
    else
        pNode->left = insert(pNode->left, data);
    return pNode;
}

void insert2(struct node **pNode, int data){
    if((*pNode) == NULL){
        (*pNode) = newNode(data);
    }
    else if((*pNode)->key < data){
        insert2(&((*pNode)->right), data);
    }
    else{
        insert2(&((*pNode)->left), data);
    }
}

// 中序遍历 从大到小打印
void inOrder(struct node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d", root->key);
        inOrder(root->right);
    }
}

int main(void){
    struct node *root = NULL;
    root = insert(root, 1);
    insert(root, 3);
    insert(root, 2);
    insert(root, 6);
    insert(root, 4);
    inOrder(root);

    // 调用两种insert2的区别
    struct node *root2 = NULL;
    insert2(&root2, 1);
    insert2(&root2, 3);
    insert2(&root2, 2);
    insert2(&root2, 6);
    insert2(&root2, 4);
    inOrder(root2);

}
