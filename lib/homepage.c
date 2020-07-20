#include "../includes/homepage.h"

void home_page(){
  char authenticated_role[8];
  int *t = (int*) malloc(sizeof(int));
  t[0] = 1;
  while (t[0] == 1){
    List *authenticated_user = login(authenticated_role, t);
    char manager[] = "manager";
    char client[] = "client";
    if (strcmp(authenticated_role, manager) == 0){
      manager_menu();
    }
    else if (strcmp(authenticated_role, client) == 0) {
      client_menu(authenticated_user);
    }
  }
}
