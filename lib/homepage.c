#include "../includes/homepage.h"

void home_page(){
  char authenticated_role[8];
  List *authenticated_user = login(authenticated_role);
  char manager[] = "manager";
  char client[] = "client";
  if (strcmp(authenticated_role, manager) == 0){
    manager_menu(authenticated_user);
  }
  else if (stcmp(authenticated_role, client) == 0) {
    client_menu(authenticated_user);
  }
}
