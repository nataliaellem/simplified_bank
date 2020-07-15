#include "../includes/manager.h"

void manager_menu(){
  int k = 1;
  int option;
  while (k){
    printf("\nMANAGER MENU\n\n");
    printf("What option do you want to execute? \n\n");
    printf("\t(1) Create new account\n");
    printf("\t(2) Delete an account\n");
    printf("\t(3) Modify a transfer limit\n");
    printf("\t(4) List customers alphabetically\n");
    printf("\t(5) List customers by registration date\n");
    printf("\t(6) List total bank reserves\n");
    printf("\t(7) Clear database\n");
    printf("\t(8) Exit the manager menu\n\n");
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
        printf("Enter the registration number of the account you want to delete: ");
        char *matricula = (char*) malloc(50 * sizeof(char));
        scanf("%s", matricula);
        delete_account(matricula);
        printf("\n");
        break;
      case 3:
        system("clear");
        change_transfer_limit();
        break;
      case 4:
        system("clear");
        list_accounts_alphabetically();
        break;
      case 5:
        system("clear");
        break;
      case 6:
        system("clear");
        bank_reserve();
        break;
      case 7:
        system("clear");
        clear_database();
        break;
      case 8:
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
  char *password = malloc(50 * sizeof(char));
  while(k){
    printf("\nType the new password of at least %zu digits: ", digits);
    scanf("%s", password);
    printf("\n");
    if (strlen(password) >= digits){
      char *confirm_pass;
      printf("Confirm new password: ");
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
    sprintf(char_matricula, "%d", new_matriculation);
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
  fprintf(file, "%s,%s,%s,%s,\n\n", name, char_matricula, password, role);
  rewind(file);
  fclose(file);
}

void new_client_data(char *name, char *matricula){
  int day = date_day();
  int month = date_month();
  int year = date_year();
  printf("Enter the customer's initial balance: ");
  float balance;
  scanf("%f", &balance);
  printf("Enter the customer's initial transfer limit: ");
  float transfer_limit;
  scanf("%f", &transfer_limit);
  FILE *file = fopen("storage/accounts.csv", "a");
  fprintf(file, "%s,%s,%.2f,%.2f,%d/%d/%d,\n", name, matricula, balance, transfer_limit, day, month, year);
  fclose(file);
  printf("New account created.\n");
}

void delete_account(char *matricula){
  char client[] = "client";
  FILE *file = fopen("storage/login.csv", "r");
  int file_lines = number_of_file_lines(file);
  rewind(file);
  int line;
  int i = 1;
  int n_char_first_col = 0;
  int n_char_sec_col = 0;
  int n_char_third_col = 0;
  int n_char_fourth_col = 0;
  char *authenticated_matricula = (char*) malloc(20 * sizeof(char));
  char *name = (char*) malloc(50 * sizeof(char));
  char *role = (char*) malloc(10 * sizeof(char));
  while(i < file_lines+1){
    char *first_column = calloc(50, sizeof(char));
    char *second_column = calloc(50, sizeof(char));
    char *third_column = calloc(50, sizeof(char));
    char *fourth_column = calloc(50, sizeof(char));
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
    if (strcmp(second_column, matricula) == 0){
      strcpy(authenticated_matricula, matricula);
      strcpy(name, first_column);
      strcpy(role, fourth_column);
      line = i;
      for (int j = 1; j<51; j++){
          if (first_column[j] == 0 && n_char_first_col == 0){
            n_char_first_col = j;

          }
          if (second_column[j] == 0 && n_char_sec_col == 0){
            n_char_sec_col = j;
          }
          if (third_column[j] == 0 && n_char_third_col == 0){
            n_char_third_col = j;
          }
          if (fourth_column[j] == 0 && n_char_fourth_col == 0){
            n_char_fourth_col = j;
          }
      }
    }
    free(first_column);
    free(second_column);
    free(third_column);
    free(fourth_column);
    i++;
}
rewind(file);
  if (authenticated_matricula == NULL){
    printf("Invalid matriculation, try again.\n");
    return;
}

  printf("Are you sure you want to delete %s's account?\n(y)Yes\n(n)No\nChoose one: ", name);
  char op;
  __fpurge(stdin);
  scanf("%c", &op);
  switch(op){
      case 'y':
        printf("\n");
        int n_char_file = 0;
        for (int n = 1; n < line; n++){
          n_char_file++;
          for (char ch = getc(file); ch != '\n'; ch = getc(file)){
            n_char_file++;
          }
        }
        rewind(file);
        fclose(file);
        file = fopen("storage/login.csv", "r+");
        fseek(file, n_char_file, SEEK_SET);
        for (int k = 0; k < n_char_first_col; k++){
          fprintf(file, "!");
        }
        fprintf(file, ",");
        for (int k = 0; k < n_char_sec_col; k++){
          fprintf(file, "!");
        }
        fprintf(file, ",");
        for (int k = 0; k < n_char_third_col; k++){
          fprintf(file, "!");
        }
        fprintf(file, ",");
        for (int k = 0; k < n_char_fourth_col; k++){
          fprintf(file, "!");
        }
        fprintf(file, ",");
        rewind(file);
        fclose(file);
        printf("Deleted account.\n");
        break;
      case 'n':
        printf("Account not deleted.\n");
        rewind(file);
        fclose(file);
        return;
      default:
        printf("Invalid option. Try again.\n");
        return;
        break;
    }

    if (strcmp(client, role) == 0){
      delete_client_account(matricula);
    }
  }

void delete_client_account(char *matricula){
  FILE *file = fopen("storage/accounts.csv", "r");
  int file_lines = number_of_file_lines(file);
  rewind(file);
  int line;
  int i = 1;
  int n_char_first_col = 0;
  int n_char_sec_col = 0;
  int n_char_third_col = 0;
  int n_char_fourth_col = 0;
  int n_char_fifth_col = 0;
  char *authenticated_matricula = (char*) malloc(20 * sizeof(char));
  char *name = (char*) malloc(50 * sizeof(char));
  while(i < file_lines+1){
    char *first_column = calloc(50, sizeof(char));
    char *second_column = calloc(50, sizeof(char));
    char *third_column = calloc(50, sizeof(char));
    char *fourth_column = calloc(50, sizeof(char));
    char *fifth_column = calloc(14, sizeof(char));
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column, fifth_column);
    if (strcmp(second_column, matricula) == 0){
      strcpy(authenticated_matricula, matricula);
      strcpy(name, first_column);
      line = i;
      for (int j = 1; j<51; j++){
          if (first_column[j] == 0 && n_char_first_col == 0){
            n_char_first_col = j;
          }
          if (second_column[j] == 0 && n_char_sec_col == 0){
            n_char_sec_col = j;
          }
          if (third_column[j] == 0 && n_char_third_col == 0){
            n_char_third_col = j;
          }
          if (fourth_column[j] == 0 && n_char_fourth_col == 0){
            n_char_fourth_col = j;
          }
          if (fifth_column[j] == 0 && n_char_fifth_col == 0){
            n_char_fifth_col = j;
          }
      }
    }
    free(first_column);
    free(second_column);
    free(third_column);
    free(fourth_column);
    free(fifth_column);
    i++;
}
  rewind(file);
  fclose(file);
  file = fopen("storage/accounts.csv", "r+");
  int offset = 0;
  for (int n = 1; n < line; n++){
    offset++;
    for (char ch = getc(file); ch != '\n'; ch = getc(file)){
      offset++;
    }
  }
  fseek(file, offset, SEEK_SET);
  for (int k = 0; k < n_char_first_col; k++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  for (int l = 0; l < n_char_sec_col; l++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  for (int m = 0; m < n_char_third_col; m++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  for (int n = 0; n < n_char_fourth_col; n++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  for (int b = 0; b < n_char_fifth_col; b++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  rewind(file);
  fclose(file);
}

void change_transfer_limit(){
  printf("Type the matriculation of the account you want to modify the transfer limit: ");
  char *matricula = reading();
  float new_limit;
  printf("\nType the new transfer limit: ");
  scanf("%f", &new_limit);
  printf("\n");
  FILE *file = fopen("storage/accounts.csv", "r");
  int file_lines = number_of_file_lines(file);
  rewind(file);
  int n_char_first_col = 0;
  int n_char_sec_col = 0;
  int n_char_third_col = 0;
  int n_char_fourth_col = 0;
  int n_char_fifth_col = 0;
  int line;
  int i = 1;
  char *authenticated_matricula = (char*) malloc(20 * sizeof(char));
  char *name = (char*) malloc(50 * sizeof(char));
  char *balance = (char*) malloc(50 * sizeof(char));
  char *transfer_limit = (char*) malloc(50 * sizeof(char));
  char *reg_date = (char*) malloc(14 * sizeof(char));
  while(i < file_lines+1){
    char *first_column = calloc(50, sizeof(char));
    char *second_column = calloc(50, sizeof(char));
    char *third_column = calloc(50, sizeof(char));
    char *fourth_column = calloc(50, sizeof(char));
    char *fifth_column = calloc(14, sizeof(char));
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column, fifth_column);
    if (strcmp(second_column, matricula) == 0){
      strcpy(authenticated_matricula, matricula);
      strcpy(name, first_column);
      strcpy(balance, third_column);
      strcpy(transfer_limit, fourth_column);
      strcpy(reg_date, fifth_column);
      line = i;
      for (int j = 1; j<51; j++){
          if (first_column[j] == 0 && n_char_first_col == 0){
            n_char_first_col = j;
          }
          if (second_column[j] == 0 && n_char_sec_col == 0){
            n_char_sec_col = j;
          }
          if (third_column[j] == 0 && n_char_third_col == 0){
            n_char_third_col = j;
          }
          if (fourth_column[j] == 0 && n_char_fourth_col == 0){
            n_char_fourth_col = j;
          }
          if (fifth_column[j] == 0 && n_char_fifth_col == 0){
            n_char_fifth_col = j;
          }
      }
    }
    free(first_column);
    free(second_column);
    free(third_column);
    free(fourth_column);
    free(fifth_column);
    i++;
  }
  rewind(file);
  fclose(file);
  file = fopen("storage/accounts.csv", "r+");
  int offset = 0;
  for (int n = 1; n < line; n++){
    offset++;
    for (char ch = getc(file); ch != '\n'; ch = getc(file)){
      offset++;
    }
  }
  fseek(file, offset, SEEK_SET);
  for (int k = 0; k < n_char_first_col; k++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  for (int l = 0; l < n_char_sec_col; l++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  for (int m = 0; m < n_char_third_col; m++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  for (int n = 0; n < n_char_fourth_col; n++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  for (int n = 0; n < n_char_fifth_col; n++){
    fprintf(file, "!");
  }
  fprintf(file, ",");
  rewind(file);
  fclose(file);
  file = fopen("storage/accounts.csv", "a");
  fprintf(file, "%s,%s,%s,%.2f,%s,\n", name, matricula, balance, new_limit, reg_date);
  rewind(file);
  fclose(file);
  printf("Updated transfer limit.\n");
}

void list_accounts_alphabetically(){
  FILE *file = fopen("storage/accounts.csv", "r");
  int file_lines = number_of_file_lines(file);
  rewind(file);
  List *list = create_list_accounts(file, file_lines);
  rewind(file);
  fclose(file);
  char **names = (char**) calloc(file_lines, sizeof(char*));
  int i;
  for (i = 0; i < file_lines; i++){
    names[i] = (char*) calloc(50, sizeof(char));
  }
  List *aux;
  i = 0;
  for (aux = list; aux != NULL; aux = aux->next){
    char *name = get_client_name(aux->data->client);
    strcpy(names[i], name);
    i++;
  }
  char **new_names = list_alphabetically(names, file_lines);
  for (i = 0; i < file_lines; i++){
    printf("%s\n", new_names[i]);
  }
}

void bank_reserve(){
  FILE *file = fopen("storage/accounts.csv", "r");
  int file_lines = number_of_file_lines(file);
  List *clients = create_list_accounts(file, file_lines);
  float *reserves = malloc(file_lines * sizeof(float));
  List *aux = clients;
  for (int i = 0; i < file_lines; i++){
    if (aux != NULL){
      float balance = get_client_balance(aux->data->client);
      reserves[i] = balance;
      aux = aux->next;
    }
  }
  float total_reserves = 0;
  for (int j = 0; j < file_lines; j++){
    total_reserves = total_reserves + reserves[j];
    printf("Reserve of client %d: %.2f\n", j+1, reserves[j]);
  }
  rewind(file);
  fclose(file);
  printf("Total bank reserves: %.2f\n", total_reserves);
}

void clear_database(){
  FILE *file = fopen("storage/login.csv", "r");
  int file_lines = number_of_file_lines(file);
  List *logins = create_list_logins(file, file_lines);
  rewind(file);
  fclose(file);
  List *aux;
  int position;
  int count = 0;
  for (aux = logins; aux != NULL; aux = aux->next){
    count++;
    if (aux->data->user->matricula[0] == '!'){
      position = count;
      delete_block(logins, position);
    }
  }
  file = fopen("storage/login.csv", "w");
  List *aux2;
  for (aux2 = logins; aux2 != NULL; aux2 = aux2->next){
      fprintf(file, "%s,", aux2->data->user->name);
      fprintf(file, "%s,", aux2->data->user->matricula);
      fprintf(file, "%s,", aux2->data->user->password);
      fprintf(file, "%s,", aux2->data->user->role);
      fprintf(file, "\n");
  }
  rewind(file);
  fclose(file);
  FILE *accounts = fopen("storage/accounts.csv", "r");
  int accounts_lines = number_of_file_lines(accounts);
  List *list = create_list_char(accounts, accounts_lines);
  rewind(accounts);
  fclose(accounts);
  List *a;
  int pos;
  count = 0;
  for (a = list; a != NULL; a = a->next){
    count++;
    if (a->data->client->matricula[0] == '!'){
      pos = count;
      delete_block(list, pos);
    }
  }
  accounts = fopen("storage/accounts.csv", "w");
  List *a2;
  for (a2 = list; a2 != NULL; a2 = a2->next){
    fprintf(accounts, "%s,", a2->data->client->name);
    fprintf(accounts, "%s,", a2->data->client->matricula);
    fprintf(accounts, "%s,", a2->data->client->char_balance);
    fprintf(accounts, "%s,", a2->data->client->char_transfer_limit);
    fprintf(accounts, "%s,", a2->data->client->reg_date);
    fprintf(accounts, "\n");
  }
  rewind(accounts);
  fclose(accounts);
  printf("Clean database.\n");
}
