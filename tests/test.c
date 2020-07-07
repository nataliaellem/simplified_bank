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
  FILE *accounts = fopen("tests/test_accounts.csv", "r");
  int file_lines = 0;
  if (accounts == NULL){
    printf("FILE ACCOUNTS NOT FOUND.\n");
    return 0;
  }
  for (char c = getc(accounts); c != EOF; c = getc(accounts)){
    if (c == '\n'){
      file_lines++;
    }
  }
  if (file_lines == 3){
    printf("\nFILE LINES PASSED");
  }
  printf("\n______________________________________________________________________\n");
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
              printf("TEST WITH FUNCTION 'CREATE_LIST_ACCOUNTS' PASSED!");
            }
          }
        }
      }
      else {
        printf("TEST WITH FUNCTION 'CREATE_LIST_ACCOUNTS' NOT PASSED.");
      }
    }
  }
//  print_list_of_clients(list);
  rewind(accounts);
  fclose(accounts);
 printf("\n______________________________________________________________________\n");

  //TEST FOR FUNCTIONS TO LOGINS LIST
  FILE *file = fopen("tests/test_logins.csv", "r");
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
    printf("TEST WITH FUNCTION 'CREATE_LIST_LOGINS' NOT PASSED.");
  }
  rewind(file);
  fclose(file);
  printf("\n______________________________________________________________________\n");
  char *test_name = get_user_name(logins_list->data->user);
  if (strcmp(test_name, "Antonio") == 0){
    printf("GET USER NAME PASSED.");
  }
  printf("\n______________________________________________________________________\n");
  // TEST FOR FILTER FUNCTION E NEW BLOCK FUNCTION
  char *role = (char*) malloc(10 * sizeof(char));
  char test[] = "client";
  strcpy(role, test);
  int *length = (int*) malloc(sizeof(int));
  List *filtered_list = filter_logins(logins_list, get_user_role, role, length);
  char first_name_filtered[] = "Natalia Ellem";
  char sec_name_filtered[] = "Alan Bispo";
  char third_name_filtered[] = "Pedro";
  char first_matricula_filtered[] = "20201";
  char sec_matricula_filtered[] = "20202";
  char third_matricula_filtered[] = "20203";
  char first_password_filtered[] = "12345678";
  char sec_password_filtered[] = "12345678";
  char third_password_filtered[] = "12345678";
  char first_role_filtered[] = "client";
  char sec_role_filtered[] = "client";
  char third_role_filtered[] = "client";
  if (strcmp(filtered_list->data->user->name, first_name_filtered) == 0 && strcmp(filtered_list->data->user->matricula, first_matricula_filtered) == 0){
    if (strcmp(filtered_list->data->user->password, first_password_filtered) == 0 && strcmp(filtered_list->data->user->role, first_role_filtered) == 0){
      if (strcmp(filtered_list->next->data->user->name, sec_name_filtered) == 0 && strcmp(filtered_list->next->data->user->matricula, sec_matricula_filtered) == 0){
        if (strcmp(filtered_list->next->data->user->password, sec_password_filtered) == 0 && strcmp(filtered_list->next->data->user->role, sec_role_filtered) == 0){
          if (strcmp(filtered_list->next->next->data->user->name, third_name_filtered) == 0 && strcmp(filtered_list->next->next->data->user->matricula, third_matricula_filtered) == 0){
            if (strcmp(filtered_list->next->next->data->user->password, third_password_filtered) == 0 && strcmp(filtered_list->next->next->data->user->role, third_role_filtered) == 0){
                  printf("\nTEST WITH FUNCTION 'FILTER_LOGINS' PASSED!\n");
            }
          }
        }
      }
    }
  }
  else {
    printf("TEST WITH FUNCTION 'FILTER_LOGINS' NOT PASSED.");
  }
  printf("\n______________________________________________________________________\n");
//  print_list_logins(filtered_list);
//   printf("LENGTH : %d\n", *length);
  if (*length == 3){
    printf("TEST LENGTH PASSED");
  }
  else {
    printf("TEST LENGTH NOT PASSED");
  }
  printf("\n______________________________________________________________________\n");
  //char *matricula = reading();
  //char authenticated_role[8];
  //login(authenticated_role);
  //printf("AUTHENTICATED ROLE : %s\n", authenticated_role);

  // char client[] = "client";
  // char manager[] = "manager";
  // char anything[] = "anything";
  // new_account(anything);
return 0;
}
