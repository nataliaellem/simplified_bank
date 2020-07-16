#include "../includes/helper.h"

char* reading(){
  __fpurge(stdin);
  int i = 0;
  char *information = (char*) malloc(1 * sizeof(char));
  char c = ' ';
  while (c != '\n'){
    scanf("%c", &c);
    if (c != '\n'){
      information[i] = c;
      i++;
      information = (char*) realloc(information, (i+1) * sizeof(char));

    }
  }
  return information;
}

char** sort_list(char **list, int size_list){
  int i, j;
  char *higher = malloc(50 * sizeof(char));
  for (i = 0; i < size_list; i++){
    for (j = i; j < size_list; j++){
      if (strcmp(list[i], list[j]) > 0){
        strcpy(higher, list[i]);
        strcpy(list[i], list[j]);
        strcpy(list[j], higher);
      }
    }
  }
  return list;
}

int number_of_file_lines(FILE *file){
  int file_lines = 0;
  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n'){
      file_lines++;
    }
  }
  return file_lines;
}


int date_day(){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  return data_hora_atual->tm_mday;
}

int date_month(){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  return data_hora_atual->tm_mon+1;
}

int date_year(){
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  return data_hora_atual->tm_year + 1900;
}
