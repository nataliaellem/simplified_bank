#include "../includes/manager.h"

void manager_menu(List *node){
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
    switch (option) {
      case 1:
        system("clear");
        creat_new_account();
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
    char matricula[50];
    sprintf(matricula, "%d", new_matriculation);
    new_client_data(name, matricula);
  }
  char matriculation[50];
  sprintf(matriculation, "%d", new_matriculation);
  FILE *file = fopen("storage/login.csv", "a");
  fprintf(file, "%s,%s,%s,%s,\n", name, matriculation, password, role);
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
