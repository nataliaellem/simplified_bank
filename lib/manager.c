#include "../includes/manager.h"

void manager_menu(List *node){
  int k = 1;
  int option;
  while (k){
    printf("Wich option do you want to make? \n\n");
    printf("\t(1) Create new account\n");
    printf("\t(2) Delete an account\n");
    printf("\t(3) Modify a transfer limit\n");
    printf("\t(4) List customers alphabetically\n");
    printf("\t(5) List customers by registration date\n");
    printf("\t(6) List total bank reserves\n");
    printf("\t(7) Exit the manager menu\n\n);
    printf("Choose one: ");
    scanf("%d", &option);
    printf("\n");
    switch (option) {
      case 1:
        system("clear");
        break;
      case 2:
        system("clear");
        break;
      case 3:
        system("clear");
        break;
      case 4:
        system("clear");
        break;
      case 5:
        system("clear");
        break;
      case 6:
        system("clear");
        break;
      case 7:
        k = 0;
        break;
      default:
        printf("\nInvalid option, try again.\n");
        break;
    }
  }
}
