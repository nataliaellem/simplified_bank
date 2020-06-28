#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "applications.h"

typedef struct list {
  struct list *prev;
  struct list *next;
  Data *data;
} List;
#endif
