#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "includes/client.h"
#include "includes/list.h"
#include "includes/manager.h"
#include "includes/homepage.h"


int main(){
  FILE *accounts = fopen("storage/accounts.csv", "r");
  int file_lines = 0;
  for (char c = getc(accounts); c != EOF; c = getc(accounts)){
    if (c == '\n'){
      file_lines++;
    }
  }
  List *list = create_list_accounts(accounts, file_lines);
  print_list_of_clients(list);
  rewind(accounts);
  fclose(accounts);
return 0;
}
