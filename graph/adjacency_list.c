#include <stdio.h>
#include <stdlib.h>

// 节点数据
struct AdjNode{
    int index;
    struct AdjNode* next;
};

//struct AdjList{
//
//};

struct Graph{
    int v;  // number of vertex
    struct AdjNode* ptr;  // pointer to AdjNode
};

struct AdjNode* newAdjNode(int index){
    struct AdjNode* node = (struct AdjNode*)malloc(sizeof(struct AdjNode));
    node->index = index;
    node->next = NULL;
    return node;
}

struct Graph* createGraph(int v){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    struct AdjNode* list = (struct AdjNode*)malloc(v * sizeof(struct AdjNode));
    graph->ptr = list;
    graph->v = v;
    for(int i = 0; i < v; i++){
        graph->ptr[i].index = i;
        graph->ptr[i].next = NULL;
    }
    return graph;
}

void addEage(struct Graph* graph, int src, int dest){
    struct AdjNode* node = newAdjNode(dest);
    node->next = graph->ptr[src].next;
    graph->ptr[src].next = node;

    // 无向图需要反向链接
    struct AdjNode* rnode = newAdjNode(src);
    rnode->next = graph->ptr[dest].next;
    graph->ptr[dest].next = rnode;
}

void printGraph(struct Graph* graph){
    for(int i = 0; i < graph->v; i++){
        struct AdjNode node = graph->ptr[i];
        printf("%d", node.index);
        while(node.next){
            printf("->%d", node.next->index);
            node = *node.next;
        }
        printf("\n");
    }
}

int main(void){
    struct Graph* graph = createGraph(5);
    addEage(graph, 0, 2);
    addEage(graph, 1, 3);
    addEage(graph, 3, 4);
    printGraph(graph);
}
