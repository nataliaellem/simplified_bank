#include "../includes/list.h"
List* new_node(){
  List *new_block = (List*) malloc(sizeof(List));
  new_block->data = (Data*) malloc(sizeof(Data));
  return new_block;
}
