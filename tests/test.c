#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/login.h"
#include "../includes/client.h"
#include "../includes/list.h"
#include "../includes/manager.h"
#include "../includes/homepage.h"


int main(){
  //TEST FOR FUNCTIONS TO ACCOUNTS LIST
  FILE *accounts = fopen("storage/test_accounts.csv", "r");
  int file_lines = 0;
  for (char c = getc(accounts); c != EOF; c = getc(accounts)){
    if (c == '\n'){
      file_lines++;
    }
  }
  if (file_lines == 3){
    printf("FILE LINES PASSED\n");
  }
  List *list = create_list_logins(accounts, file_lines);
  char first_name[] = "Natalia Ellem";
  char sec_name[] = "Alan Bispo";
  char third_name[] = "Pedro";
  char first_matricula[] = "20201";
  char sec_matricula[] = "20202";
  char third_matricula[] = "20203";
  char first_balance[] = "10000";
  char sec_balance[] = "10000";
  char third_balance[] = "10000";
  char first_transfer_limit[] = "1000";
  char sec_transfer_limit[] = "1000";
  char third_transfer_limit[] = "1000";
  if (strcmp(list->data->client->name, first_name) == 0 && strcmp(list->data->client->matricula, first_matricula) == 0){
    if (strcmp(list->data->client->balance, first_balance) == 0 && strcmp(list->data->client->transfer_limit, first_transfer_limit) == 0){
      if (strcmp(list->next->data->client->name, sec_name) == 0 && strcmp(list->next->data->client->matricula, sec_matricula) == 0){
        if (strcmp(list->next->data->client->balance, sec_balance) == 0 && strcmp(list->next->data->client->transfer_limit, sec_transfer_limit) == 0){
          if (strcmp(list->next->next->data->client->name, third_name) == 0 && strcmp(list->next->next->data->client->matricula, third_matricula) == 0){
            if (strcmp(list->next->next->data->client->balance, third_balance) == 0 && strcmp(list->next->next->data->client->transfer_limit, third_transfer_limit) == 0){
              printf("\nTEST WITH FUNCTION 'CREATE_LIST_ACCOUNTS' PASSED!\n\n");
            }
          }
        }
      }
      else {
        printf("\nTEST NOT PASSED.\n");
      }
    }
  }
//  print_list_of_clients(list);
  rewind(accounts);
  fclose(accounts);
 printf("\n______________________________________________________________________\n");

  //TEST FOR FUNCTIONS TO LOGINS LIST
  FILE *file = fopen("storage/test_logins.csv", "r");
  file_lines = 0;
  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n'){
      file_lines++;
    }
  }
  List *logins_list = create_list_logins(file, file_lines);
  //print_list_logins(logins_list);
  char First_name[] = "Antonio";
  char Sec_name[] = "Natalia Ellem";
  char Third_name[] = "Alan Bispo";
  char Fourth_name[] = "Pedro";
  char First_matricula[] = "202011";
  char Sec_matricula[] = "20201";
  char Third_matricula[] = "20202";
  char Fourth_matricula[] = "20203";
  char first_password[] = "12345";
  char sec_password[] = "12345678";
  char third_password[] = "12345678";
  char fourth_password[] = "12345678";
  char first_role[] = "manager";
  char sec_role[] = "client";
  char third_role[] = "client";
  char fourth_role[] = "client";
  if (strcmp(logins_list->data->user->name, First_name) == 0 && strcmp(logins_list->data->user->matricula, First_matricula) == 0){
    if (strcmp(logins_list->data->user->password, first_password) == 0 && strcmp(logins_list->data->user->role, first_role) == 0){
      if (strcmp(logins_list->next->data->user->name, Sec_name) == 0 && strcmp(logins_list->next->data->user->matricula, Sec_matricula) == 0){
        if (strcmp(logins_list->next->data->user->password, sec_password) == 0 && strcmp(logins_list->next->data->user->role, sec_role) == 0){
          if (strcmp(logins_list->next->next->data->user->name, Third_name) == 0 && strcmp(logins_list->next->next->data->user->matricula, Third_matricula) == 0){
            if (strcmp(logins_list->next->next->data->user->password, third_password) == 0 && strcmp(logins_list->next->next->data->user->role, third_role) == 0){
              if (strcmp(logins_list->next->next->next->data->user->name, Fourth_name) == 0 && strcmp(logins_list->next->next->next->data->user->matricula, Fourth_matricula) == 0){
                if (strcmp(logins_list->next->next->next->data->user->password, fourth_password) == 0 && strcmp(logins_list->next->next->next->data->user->role, fourth_role) == 0){
                  printf("\nTEST WITH FUNCTION 'CREATE_LIST_LOGINS' PASSED!\n");
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    printf("\nTEST NOT PASSED.\n");
  }
  rewind(file);
  fclose(file);
  printf("\n______________________________________________________________________\n");
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
  char authenticated_role[8];
  login(authenticated_role);
  printf("AUTHENTICATED ROLE : %s\n", authenticated_role);

return 0;
}
