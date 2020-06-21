#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <timse.h>

typedef struct user {
  char *name;
  float balance;
  float transfer_limit;

} User;

#endif
