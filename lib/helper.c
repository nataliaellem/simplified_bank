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
