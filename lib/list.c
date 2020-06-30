#include "../includes/list.h"
void new_node(List *new_block){
  new_block = (List*) malloc(sizeof(List));
  new_block->data = (Data*) malloc(sizeof(Data));
}
