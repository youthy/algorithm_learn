#include <stdlib.h>
#include <stdio.h>
#include <sys/queue.h>

//  struct Entry
//  {
//      int data;
//      struct {
//          struct Entry *tqe_next;
//          struct Entry **tqe_prev;
//      } entries;
//  }      
struct Entry
{
    int data;
    TAILQ_ENTRY(Entry) entries;
};

struct Entry *newEntry(int data)
{
    struct Entry *n1 = (struct Entry*)malloc(sizeof(struct Entry));
    n1->data = data;
    return n1;
}

// TAILQ_HEAD =>
//  struct tailhead
//  {
//      struct Entry *tqh_first;
//      struct Entry **tqh_last;
//  } head;
TAILQ_HEAD(tailhead, Entry) head;

int main(void)
{
    struct tailhead *headp;
    // TAILQ_INIT(&head) =>
    // do
    // {
    //     (&head)->tqh_first = NULL;
    //     (&head)->tqh_last = &(&head)->tqh_first;
    // } while(0);
    TAILQ_INIT(&head);
    struct Entry *n1 = newEntry(10);
    TAILQ_INSERT_TAIL(&head, n1, entries);
    struct Entry *n2 = newEntry(20);
    TAILQ_INSERT_TAIL(&head, n2, entries);

    struct Entry *temp;
    temp = TAILQ_FIRST(&head);
    printf("%d", temp->data);
    temp = TAILQ_NEXT(temp, entries);
    printf("%d", temp->data);
    return 0;
}