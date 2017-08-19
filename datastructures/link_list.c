#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

struct Node* newNode(int v){
   struct Node *node = (struct Node*)malloc(sizeof(struct Node));
   node->val = v;
   node->next = NULL;
   return node;
}

// push 操作可能会修改头指针所以使用 **head 在头部建立空节点在deleteNode时防止修改头指针
void push(struct Node **head, int v){
    if((*head) == NULL){
        (*head) = newNode(0);
    }
    struct Node *node = newNode(v);
    node->next = (*head)->next;
    (*head)->next = node;
}

void append(struct Node *head, int v){
    while(head->next){
        head = head->next;
    }
    struct Node *node = newNode(v);
    head->next = node;
}

void printList(struct Node *head){
    while(head->next != NULL){
        printf("%d", head->next->val);
        head = head->next;
    }
    printf("\n");
}

void deleteNode(struct Node *head, int v){
    while (head->next && head->next->val != v) {
        head = head->next;
    }
    if(head->next){
        struct Node *tmp = head->next;
        head->next = head->next->next;
        free(tmp);
    }
}

void deleteAtPos(struct Node *head, int pos){
    if(pos <= 0){
        return;
    }
    while(head->next && pos > 1){
        head = head->next;
        pos--;
    }
    if(head->next != NULL){
       struct Node *tmp = head->next;
       head->next = head->next->next;
       free(tmp);
    }
}

int main(void){
    struct Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    append(head, 4);
    printList(head);
    deleteNode(head, 2);
    printList(head);
    deleteAtPos(head, 1);
    printList(head);
}
