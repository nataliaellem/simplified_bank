#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "models.h"
#include "helper.h"


void new_login(User *user);
char* get_user_name(User *user);
char* get_user_matricula(User *user);
char* get_user_password(User *user);
char* get_user_role(User *user);
void set_user_name(User *user, char *name);
void set_user_matricula(User *user, char *matricula);
void set_user_password(User *user, char *password);
void set_user_role(User *user, char *role);
List* create_list_logins(FILE *file, int file_lines);
void print_list_logins(List *list);
List* new_block(List *list, User *user);
List* filter_logins(List *list, char* (*block)(User*), char *attribute, int *length);

#endif
