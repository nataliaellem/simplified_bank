#include "../includes/manager.h"

void manager_menu(){
  printf("DEBUG \n");
  int k = 1;
  int option;
  while (k){
    printf("\n\tMANAGER MENU\n");
    printf("What option do you want to execute? \n\n");
    printf("\t(1) Create new account\n");
    printf("\t(2) Delete an account\n");
    printf("\t(3) Modify a transfer limit\n");
    printf("\t(4) List customers alphabetically\n");
    printf("\t(5) List customers by registration date\n");
    printf("\t(6) List total bank reserves\n");
    printf("\t(7) Exit the manager menu\n\n");
    printf("Choose one: ");
    scanf("%d", &option);
    printf("\n");
    int n = 1;
    switch (option) {
      case 1:
        system("clear");
        creat_new_account();
        break;
      case 2:
        system("clear");
        while (n){
          printf("Do you want to delete a (1)manager or a (2)client account?\nChoose one: ");
          int opt;
          scanf("%d", &opt);
          printf("\n");
          char manager[] = "manager";
          char client[] = "client";
          printf("Enter the registration number of the account you want to delete: ");
          char *matricula = reading();
          printf("\n");
          switch(opt){
            case 1:
              delete_account(matricula, manager);
              n = 0;
              break;
            case 2:
              delete_account(matricula, client);
              n = 0;
              break;
            default:
              printf("invalid option for account type, try again.\n");
              break;
          }
        }

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

void creat_new_account(){
  int c = 1;
  while (c){
    printf("Do you want to create a manager or a client account?\n");
    printf("\t(1) Manager account\n\t(2) Client account\n\nChoose one option: ");
    int option;
    scanf("%d", &option);
    printf("\n");
    switch (option){
      case 1:
        system("clear");
        char *manager = "manager";
        new_account(manager);
        c = 0;
        break;
      case 2:
        system("clear");
        char *client = "client";
        new_account(client);
        c = 0;
        break;
      default:
        printf("Invalid option, try again.\n");
        break;
    }
  }
}

void new_account(char *role){
  size_t digits;
  char manager[] = "manager";
  char client[] = "client";
  if (strcmp(role, manager) == 0){
    digits = 5;
  }
  else if (strcmp(role, client) == 0){
    digits = 8;
  }
  else {
    printf("Impossible to create a new account without a role client or manager.\n");
    return;
  }
  printf("Type the name of the new %s: ", role);
  char *name = reading();
  int k = 1;
  char *password;
  while(k){
    printf("\nType the new password of at least %zu digits: ", digits);
    password = reading();
    if (strlen(password) >= digits){
      char *confirm_pass;
      printf("Confirm your password: ");
      confirm_pass = reading();
      printf("\n");
      if (strcmp(password, confirm_pass) == 0){
        k = 0;
      } else {
        printf("Password checking doesn't match. Try again.\n\n");
      }
    } else {
      printf("Password is less than %zu digits, try again.\n\n", digits);
    }
  }
  int new_matriculation;
  char char_matricula[50];
  if (strcmp(role, manager) == 0){
    digits = 5;
    FILE *mat = fopen("storage/manager_mat.val", "r");
    fscanf(mat, "%d\n", &new_matriculation);
    fclose(mat);
    new_matriculation++;
    mat = fopen("storage/manager_mat.val", "w");
    fprintf(mat, "%d\n", new_matriculation);
    fclose(mat);
    printf("New account created.\n\n");
  }
  else if (strcmp(role, client) == 0){
    digits = 8;
    FILE *mat = fopen("storage/client_mat.val", "r");
    fscanf(mat, "%d\n", &new_matriculation);
    fclose(mat);
    new_matriculation++;
    mat = fopen("storage/client_mat.val", "w");
    fprintf(mat, "%d\n", new_matriculation);
    fclose(mat);
    sprintf(char_matricula, "%d", new_matriculation);
    new_client_data(name, char_matricula);
  }
  FILE *file = fopen("storage/login.csv", "a");
  fprintf(file, "%s,%s,%s,%s,\n", name, char_matricula, password, role);
  rewind(file);
  fclose(file);
}

void new_client_data(char *name, char *matricula){
  printf("Enter the customer's initial balance: ");
  float balance;
  scanf("%f", &balance);
  printf("Enter the customer's initial transfer limit: ");
  float transfer_limit;
  scanf("%f", &transfer_limit);
  FILE *file = fopen("storage/accounts.csv", "a");
  fprintf(file, "%s,%s,%.2f,%.2f,", name, matricula, balance, transfer_limit);
  fclose(file);
  printf("New account created.\n");
}

void delete_account(char *matricula, char *role){
    char manager[] = "manager";
    char client[] = "client";
    if (strcmp(manager, role) == 0){
      FILE *file = fopen("storage/login.csv", "r");
      int file_lines = 0;
      for (char c = getc(file); c != EOF; c = getc(file)){
        if (c == '\n'){
          file_lines++;
        }
      }
      List *logins = create_list_logins(file, file_lines);
      rewind(file);
      fclose(file);
      List *aux;
      List *authenticated_user = NULL;
      for (aux = logins; aux->next != NULL; aux = aux->next){
        if (strcmp(aux->data->user->matricula, matricula) == 0){
          authenticated_user = aux;
          aux = NULL;
          printf("Are you sure you want to delete %s's account?\n(y)Yes\n(n)No\nChoose one: ", authenticated_user->data->user->name);
          char op;
          scanf("%c", &op);
          switch(op){
            case 'y':
              printf("\n");
              printf("Deleted account.\n");
              printf("debug\n");
              break;
            case 'n':
              printf("Account not deleted.\n");
              return;
            default:
              printf("Invalid option. Try again.\n");
              break;
          }
        }
      }
      printf("debug\n");
      if (authenticated_user == NULL){
        printf("Invalid matriculation, try again.\n");
        return;
      } else{
        printf("LOGINS AFTER\n______________________________________\n");
        delete_block(authenticated_user);
        printf("\n______________________________________\n");
      }
    }
}
