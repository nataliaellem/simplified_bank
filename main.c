#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "includes/client.h"
#include "includes/list.h"
#include "includes/manager.h"
#include "includes/homepage.h"

int main(){
  FILE *login = fopen("storage/login.csv", "r");
  int  file_lines = 0;
  for (char c = getc(login); c != EOF; c = getc(login)){
    if (c == '\n'){
      file_lines++;
    }
  }
  List *logins_list = create_list_logins(login, file_lines);
  //print_list_logins(logins_list);
  rewind(login);
  fclose(login);
  char *role = (char*) malloc(10 * sizeof(char));
  char test[] = "client";
  strcpy(role, test);
  List *filtered_list = filter_logins(logins_list, get_user_role, role);
  print_list_logins(filtered_list);
return 0;
}
