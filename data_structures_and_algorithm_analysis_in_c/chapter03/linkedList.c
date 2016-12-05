#include <stdio.h>
#include <stdlib.h>

typedef int element_type;
typedef struct node* node_ptr;
struct node{
  element_type element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

int
main(int argc, char const *argv[]) {
  printf("%s\n", "haha");
  return 0;
}

int
is_empty(LIST L){
  return (L -> next == NULL);
}

int
is_last(position p, LIST L){
  return (p -> next == NULL);
}

// find element x in list L
position
find(element_type x, LIST L){
  position p = L -> next;
  while(p && (p -> element != x))
  p = p -> next;
  return p;
}

// find x previous element
position
find_previous(element_type x, LIST L){
  position tmp = L -> next;
  while(tmp && (tmp -> next -> element != x))
  tmp = tmp -> next;
  return tmp;
}

// remove element x in list L
void
remove(element_type x, LIST L) {
  position p, tmp_cell;
  p = find_previous(x, L);
  if(p && (p -> next != NULL)){
    tmp_cell = p -> next;
    p -> next = tmp_cell -> next;
    free(tmp_cell);
  }
}

// insert e after x
void
insert(element_type x, LIST L, element_type e){
  position p, tmp;
  p = find(x, L);
  if(p){
    tmp = (position) malloc(sizeof(struct node));
    if(tmp == NULL)
      printf("Out of space!!!\n");
      exit(-1);
    tmp -> next = p -> next;
    tmp -> element = e;
    p -> next = tmp;
  }
}

// delete whole list
void
delete_list(LIST L) {
  position p, tmp;
  p = L;
  while(p){
    tmp = p -> next;
    free(p);
    p = tmp;
  }
}
