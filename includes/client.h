#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "manager.h"
#include "list.h"
#include "login.h"

typedef struct client {
  char *name;
  float balance;
  float transfer_limit;
  char *matricula;
} Client;

#endif
