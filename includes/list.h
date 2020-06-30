#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"

typedef struct list {
  struct list *prev;
  struct list *next;
  Data *data;
} List;

void new_node(List *new_block);

#endif
