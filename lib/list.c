#include "../includes/list.h"
List* new_node(){
  List *new_block = (List*) malloc(sizeof(List));
  new_block->data = (Data*) malloc(sizeof(Data));
  return new_block;
}

void delete_block(List *node){
  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
}

void new_linked_block(List *list, List *new_block){
  if (list == NULL){
    new_block->prev = (List*) NULL;
    new_block->next = (List*) NULL;
    list = new_block;
  } else {
    List *aux;
    for (aux = list; aux->next != NULL; aux = aux->next);
    new_block->prev = aux;
    new_block->next = (List*) NULL;
    aux->next = new_block;
  }

}
