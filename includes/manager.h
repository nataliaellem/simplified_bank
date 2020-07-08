#ifndef MANAGER_H
#define MANAGER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "models.h"

void manager_menu(List *node);
void creat_new_account();
void new_account(char *role);
void new_client_data(char *name, char *matricula);

#endif
