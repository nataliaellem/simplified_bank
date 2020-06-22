#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct client {
  char *name;
  float balance;
  float transfer_limit;
  char *password;
  char *matricula;
} Client;

#endif
