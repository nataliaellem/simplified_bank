#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"
#include "manager.h"
#include "list.h"


User* login();
void new_login(User *user);
void set_user_name(User *user, char *name);
void set_user_matricula(User *user, char *matricula);
void set_user_password(User *user, char *password);
void set_user_role(User *user, char *role);

#endif
