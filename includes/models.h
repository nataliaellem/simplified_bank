#ifndef APPLICATIONS_H
#define APPLICATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user{
  char *name;
  char *matricula;
  char *password;
  char *role;
} User;

typedef struct client {
  char *name;
  char *matricula;
  float balance;
  float transfer_limit;
  char *char_balance;
  char *char_transfer_limit;
  char *reg_date;
} Client;

typedef struct manager{
  char *name;
  char *matricula;
} Manager;

typedef union {
  User *user;
  Client *client;
  Manager *manager;
} Data;

#endif
