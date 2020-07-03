#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "includes/client.h"
#include "includes/list.h"
#include "includes/manager.h"
#include "includes/homepage.h"
#include "includes/models.h"
#include "includes/login.h"
#include "includes/helper.h"


int main(){
  // FILE *file = fopen("storage/login.csv", "r");
  // int  file_lines = 0;
  // for (char c = getc(file); c != EOF; c = getc(file)){
  //   if (c == '\n'){
  //     file_lines++;
  //   }
  // }
  // List *logins_list = create_list_logins(file, file_lines);
  // //print_list_logins(logins_list);
  // rewind(file);
  // fclose(file);
  // char *role = (char*) malloc(10 * sizeof(char));
  // char test[] = "client";
  // strcpy(role, test);
  // int *length = (int*) malloc(sizeof(int));
  // List *filtered_list = filter_logins(logins_list, get_user_role, role, length);
  // print_list_logins(filtered_list);
  home_page();
  return 0;
}
