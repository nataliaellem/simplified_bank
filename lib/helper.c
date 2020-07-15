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
  //with lists where the calloc function was used
  int aux = 1;
  char *smaller = malloc(50 * sizeof(char));
  for (int i = 0; i < size_list; i++){
    int j = 0;
    if (strcmp(list[i], list[i+aux]) == 0){
      break;
    }
    while (list[i][j] != 0){
      if (list[i][j] < list[i+aux][j]){
        strcpy(smaller, list[i]);
      } else if (list[i][j] > list[i+aux][j]){
          strcpy(smaller, list[i*aux]);
        }
      j++;
    }
  }
  return NULL;
}
