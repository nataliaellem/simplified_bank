#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "manager.h"

typedef struct list {
  struct list *prev;
  struct list *next;
  Client client;
} List;

List create_list_(FILE *file, int file_lines);
void set_client_name(List *block, char *name);
void set_client_balance(List *block, float balance);
void set_client_transfer_limit(List *block, float transfer_limit);
void set_client_password(LIST *block, char *pass);
void set_client_matricula(List *block, char *matricula);

#endif
