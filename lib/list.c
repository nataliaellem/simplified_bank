#include "../includes/list.h"
List* new_node(){
  List *new_block = (List*) malloc(sizeof(List));
  new_block->data = (Data*) malloc(sizeof(Data));
  return new_block;
}

List* delete_block(List *list, int position){
  List *aux = list;
  for (int i = 1; i < position+1; i++){
    if (i == position){
      if (aux->prev == NULL){
        aux->next->prev = NULL;
        list = aux->next;
      } else if (aux->next == NULL){
          aux->prev->next = NULL;
      } else {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
      }
      break;
    }
    aux = aux->next;
  }
  return list;
}

List* new_linked_block(List *list, List *new_block){
  if (list == NULL){
    new_block->prev = NULL;
    new_block->next = NULL;
    list = new_block;
  } else {
    List *aux;
    for (aux = list; aux->next != NULL; aux = aux->next);
    new_block->prev = aux;
    new_block->next = NULL;
    aux->next = new_block;
  }
  return list;
}
