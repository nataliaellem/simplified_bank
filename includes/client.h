#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "models.h"
#include "helper.h"
#include "login.h"

void client_menu(List *node);
void view_balance(char *matricula);
float change_balance(char *authentic_mat, char *action);
float make_transfer(char *matricula, char *transfer_mat);
void new_client(Client *client);
char* get_client_name(Client *node);
char* get_client_matricula(Client *node);
float get_client_balance(Client *node);
float get_client_transfer_limit(Client *node);
char* get_reg_date(Client *node);
void set_client_name(Client *block, char *name);
void set_client_balance(Client *block, float balance);
void set_client_transfer_limit(Client *block, float transfer_limit);
void set_client_matricula(Client *block, char *matricula);
void set_client_char_balance(Client *node, char *balance);
void set_client_char_transfer_limit(Client *node, char *transfer_limit);
void set_client_reg_date(Client *node, char *date);
List* create_list_accounts(FILE *file, int file_lines);
List* create_list_char(FILE *file, int file_lines);
void print_list_of_clients(List *list);
void print_char_list(List *list);
void delete_client_account(char *matricula);
void logger(int option, char *matricula, float value, char *transfer_mat);
void clear_database();

#endif
