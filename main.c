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
  FILE *file = fopen("tests/test_logins.csv", "r");
  int  file_lines = 0;
  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n'){
      file_lines++;
    }
  }
  rewind(file);
  char name[] = "teste";
  int line;
  int i = 1;
  int n_char_first_col = 0;
  int n_char_sec_col = 0;
  int n_char_third_col = 0;
  int n_char_fourth_col = 0;
  while(i < file_lines+1){
    char *first_column = calloc(50, sizeof(char));
    char *second_column = calloc(50, sizeof(char));
    char *third_column = calloc(50, sizeof(char));
    char *fourth_column = calloc(50, sizeof(char));
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
    printf("%s\n", first_column);
    printf("%s\n", name);
    if (strcmp(first_column, name) == 0){
      line = i;
      for (int j = 1; j<51; j++){
          if (first_column[j] == 0 && n_char_first_col == 0){
            n_char_first_col = j;

          }
          if (second_column[j] == 0 && n_char_sec_col == 0){
            n_char_sec_col = j;
          }
          if (third_column[j] == 0 && n_char_third_col == 0){
            n_char_third_col = j;
          }
          if (fourth_column[j] == 0 && n_char_fourth_col == 0){
            n_char_fourth_col = j;
          }
      }
      printf("Line: %d\n", line);
    }
    free(first_column);
    free(second_column);
    free(third_column);
    free(fourth_column);
    i++;
}
rewind(file);
int n_char_file = 0;
for (int n = 0; n < line; n++){
  n_char_file++;
  for (char ch = getc(file); ch != '\n'; ch = getc(file)){
    n_char_file++;
  }
}
int total_char_line = n_char_first_col + n_char_sec_col + n_char_third_col + n_char_fourth_col;
printf("CHARACTERS OF THE LINE TO DELETE: %d\n", total_char_line);
printf("NUMBER OF CHARACTERS ALL FILE: %d\n", n_char_file);
fclose(file);
file = fopen("tests/test_logins.csv", "r+");
fseek(file, 360, SEEK_SET);
fprintf(file, "t");
rewind(file);
fclose(file);
return 0;
}
