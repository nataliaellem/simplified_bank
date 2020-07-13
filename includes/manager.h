#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "models.h"
#include "login.h"
#include "helper.h"
#include "client.h"

void manager_menu();
void creat_new_account();
void new_account(char *role);
void new_client_data(char *name, char *matricula);
void delete_account(char *matricula, char *role);
void delete_client_account(char *matricula);
void clear_database();

#endif
