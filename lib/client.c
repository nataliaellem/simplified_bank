#include "../includes/client.h"

void client_list(){
  FILE *file = fopen("accounts.csv", "r");
  int file_lines = 0;
  for (char c = getc(file); c != EOF; getc(file)){
    if (c == '\n'){
      file_lines++;
    }
  }
  
}
