#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"
#include "list.h"
#include "manager.h"

typedef struct user{
  char *name;
  char *matricula;
  char *password;
  char *role;
  struct user *next;
  struct user *prev;
} User;

#endif
