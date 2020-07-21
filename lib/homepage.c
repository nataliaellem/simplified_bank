#include "../includes/homepage.h"

void login(){
  char *authenticated_role = (char*) malloc(10 * sizeof(char));
  FILE *login = fopen("storage/login.csv", "r");
  int file_lines = number_of_file_lines(login);
  List *logins_list = create_list_logins(login, file_lines);
  List *authenticated_user = NULL;
  char *matricula;
  char *password;
  int option;
  int k = 1;
  while(k){
    system("clear");
    printf("HOME / LOGIN\n\n");
    printf("Do you want to login as a client or as a manager?\n");
    printf("(To exit the page press '0')\n\n");
    printf("(1) CLIENT\n");
    printf("(2) MANAGER\n");
    printf("Choose one of the options: ");
    scanf("%d", &option);
    switch (option) {
      case 0:
        k = 0;
        break;
      case 1:
        system("clear");
        printf("HOME / CLIENT LOGIN\n\n");
        printf("Type your matriculation: ");
        matricula = reading();
        int *length = (int*) malloc(sizeof(int));
        char role[] = "client";
        strcpy(authenticated_role, role);
        List *client_logins = filter_logins(logins_list, get_user_role, role, length);
        List *aux;
        for (aux = client_logins; aux != NULL; aux = aux->next){
          char *comparative_matricula = get_user_matricula(aux->data->user);
          if (strcmp(matricula, comparative_matricula) == 0){
              authenticated_user = aux;
          }
        }
        if (authenticated_user == NULL){
          printf("\nInvalid matriculation, try again.\n");
        } else {
            printf("\nType your password: ");
            password = reading();
            printf("\n");
            char *comparative_password = get_user_password(authenticated_user->data->user);
            if (strcmp(password, comparative_password) == 0){
              client_menu(authenticated_user);
            } else {
              printf("\nIncorrect password.\n");
            }
        }
        break;
      case 2:
        system("clear");
        printf("HOME / MANAGER LOGIN\n\n");
        printf("Type your matriculation: ");
        matricula = reading();
        int *length2 = (int*) malloc(sizeof(int));
        char role2[] = "manager";
        strcpy(authenticated_role, role2);
        List *manager_logins = filter_logins(logins_list, get_user_role, role2, length2);
        List *aux2;
        for (aux2 = manager_logins; aux2 != NULL; aux2 = aux2->next){
          char *comparative_matricula = get_user_matricula(aux2->data->user);
          if (strcmp(matricula, comparative_matricula) == 0){
              authenticated_user = aux2;
          }
        }
        if (authenticated_user == NULL){
          printf("\nInvalid matriculation, try again.\n");
        } else {
            printf("\nType your password: ");
            password = reading();
            printf("\n");
            char *comparative_password = get_user_password(authenticated_user->data->user);
            if (strcmp(password, comparative_password) == 0){
              printf("\nLogin succeded!\n\n");
              manager_menu();
            } else {
                printf("\nIncorrect password.\n");
            }
        }
        break;
      default:
        system("clear");
        printf("Invalid option, try again.\n\n");
      break;
    }
  }
  rewind(login);
  fclose(login);
}
