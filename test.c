#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "includes/client.h"
#include "includes/list.h"
#include "includes/manager.h"
#include "includes/homepage.h"


int main(){
  //TEST FOR FUNCTIONS TO ACCOUNTS LIST
  FILE *accounts = fopen("storage/accounts.csv", "r");
  int file_lines = 0;
  for (char c = getc(accounts); c != EOF; c = getc(accounts)){
    if (c == '\n'){
      file_lines++;
    }
  }
  User *list = create_list_logins(accounts, file_lines);
  print_list_of_clients(list);
  rewind(accounts);
  fclose(accounts);

  //TEST FOR FUNCTIONS TO LOGINS LIST
  FILE *login = fopen("storage/login.csv", "r");
  file_lines = 0;
  for (char c = getc(login); c != EOF; c = getc(login)){
    if (c == '\n'){
      file_lines++;
    }
  }
  List *logins_list = create_list_logins(login, file_lines);
  print_list_logins(logins_list);
  rewind(login);
  fclose(login);
  get_user_name(logins_list->data->user);
  // TEST FOR FILTER FUNCTION E NEW BLOCK FUNCTION
  char *role = (char*) malloc(10 * sizeof(char));
  char test[] = "client";
  strcpy(role, test);
  int *length = (int*) malloc(sizeof(int));
  List *filtered_list = filter_logins(logins_list, get_user_role, role, length);
  print_list_logins(filtered_list);
  printf("LENGTH : %d\n", *length);
  char *matricula = reading();
  
return 0;
}
