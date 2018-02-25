#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// array stack 
struct Stack
{
    unsigned cap;
    int top;
    int *array;
};

struct Stack* newStack(unsigned cap)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->array = (int *)malloc(sizeof(int));
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->cap - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int element)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = element;
}

int pop(struct Stack* stack)
{
    if(isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// linklist stack
struct Node
{
    int data;
    struct Node* next;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int l_isEmpty(struct Node *linkStack)
{
    // point to nothing
    return !linkStack;
}

void l_push(struct Node **linkStack, int data)
{
    struct Node *new = newNode(data);
    new->next = *linkStack;
    *linkStack = new;
}

int l_pop(struct Node **linkStack)
{
    if(l_isEmpty(*linkStack))
    {
        return INT_MIN;
    }
    struct Node *temp = *linkStack;
    *linkStack = (*linkStack)->next;
    int ret = temp->data;
    free(temp);
    return ret;
}

int main(void){
    struct Stack *stack = newStack(100);
    push(stack, 10);
    push(stack, 100);
    push(stack, 20);
    printf("poped :%d", pop(stack));
    printf("poped :%d", pop(stack)); printf("poped :%d", pop(stack));
    printf("poped :%d", pop(stack));

    struct Node *linkStack = NULL;
    l_push(&linkStack, 10);
    l_push(&linkStack, 20);
    l_push(&linkStack, 30);
    printf("poped linkStack :%d", l_pop(&linkStack));
    printf("poped linkStack :%d", l_pop(&linkStack));
    printf("poped linkStack :%d", l_pop(&linkStack));
    printf("poped linkStack :%d", l_pop(&linkStack));
    return 0;
}

