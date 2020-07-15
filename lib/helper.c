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

char** list_alphabetically(char **list, int size_list){
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
