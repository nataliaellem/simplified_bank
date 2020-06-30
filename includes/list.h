#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"
#include "helper.h"

typedef struct list {
  struct list *prev;
  struct list *next;
  Data *data;
} List;

List* new_node();

#endif
