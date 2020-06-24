#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "manager.h"
#include "login.h"

typedef struct list {
  struct list *prev;
  struct list *next;
  Client client;
} List;

List* create_list_accounts(FILE *file, int file_lines);
User* create_list_logins(FILE *file, int file_lines);
void print_list_logins(User *list);
void print_list_of_clients(List *list);
void new_login(User *user);
void new_client(Client *client);
void set_client_name(List *block, char *name);
void set_client_balance(List *block, char* balance);
void set_client_transfer_limit(List *block, char* transfer_limit);
void set_client_matricula(List *block, char *matricula);
void set_user_name(User *user, char *name);
void set_user_matricula(User *user, char *matricula);
void set_user_password(User *user, char *password);
void set_user_role(User *user, char *role);

#endif
