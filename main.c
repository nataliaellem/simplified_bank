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
  manager_menu();
  // char matricula[] = "20202";
  // float new_limit = 12000.99;
  // FILE *file = fopen("tests/test_accounts.csv", "r");
  // int file_lines = 0;
  // for (char c = getc(file); c != EOF; c = getc(file)){
  //   if (c == '\n'){
  //     file_lines++;
  //   }
  // }
  // rewind(file);
  // int line;
  // int i = 1;
  // int n_char_first_col = 0;
  // int n_char_sec_col = 0;
  // int n_char_third_col = 0;
  // int n_char_fourth_col = 0;
  // char *authenticated_matricula = (char*) malloc(20 * sizeof(char));
  // char *name = (char*) malloc(50 * sizeof(char));
  // char *balance = (char*) malloc(50 * sizeof(char));
  // char *transfer_limit = (char*) malloc(50 * sizeof(char));
  // while(i < file_lines+1){
  //   char *first_column = calloc(50, sizeof(char));
  //   char *second_column = calloc(50, sizeof(char));
  //   char *third_column = calloc(50, sizeof(char));
  //   char *fourth_column = calloc(50, sizeof(char));
  //   fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
  //   if (strcmp(second_column, matricula) == 0){
  //     strcpy(authenticated_matricula, matricula);
  //     strcpy(name, first_column);
  //     strcpy(balance, third_column);
  //     strcpy(transfer_limit, fourth_column);
  //     line = i;
  //     for (int j = 1; j<51; j++){
  //         if (first_column[j] == 0 && n_char_first_col == 0){
  //           n_char_first_col = j;
  //         }
  //         if (second_column[j] == 0 && n_char_sec_col == 0){
  //           n_char_sec_col = j;
  //         }
  //         if (third_column[j] == 0 && n_char_third_col == 0){
  //           n_char_third_col = j;
  //         }
  //         if (fourth_column[j] == 0 && n_char_fourth_col == 0){
  //           n_char_fourth_col = j;
  //         }
  //     }
  //   }
  //   free(first_column);
  //   free(second_column);
  //   free(third_column);
  //   free(fourth_column);
  //   i++;
  // }
  // rewind(file);
  // fclose(file);
  // file = fopen("tests/test_accounts.csv", "r+");
  // int offset = 0;
  // for (int n = 1; n < line; n++){
  //   offset++;
  //   for (char ch = getc(file); ch != '\n'; ch = getc(file)){
  //     offset++;
  //   }
  // }
  // fseek(file, offset, SEEK_SET);
  // fprintf(file, "%s,%s,%s,%.2f,\n", name, matricula, balance, new_limit);
  // rewind(file);
  // fclose(file);
return 0;
}
