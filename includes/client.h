#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "models.h"
#include "helper.h"

void client_menu(List *node);
void new_client(Client *client);
void set_client_name(Client *block, char *name);
void set_client_balance(Client *block, float balance);
void set_client_transfer_limit(Client *block, float transfer_limit);
void set_client_matricula(Client *block, char *matricula);
List* create_list_accounts(FILE *file, int file_lines);
void print_list_of_clients(List *list);

#endif
