#include "../includes/client.h"

void client_menu(List *node){
  char *matricula = get_user_matricula(node->data->user);
  int k =1;
  float value = 0;
  int option;
  while (k){
    clear_database();
    system("clear");
    printf("HOME / CLIENT MENU\n\nWhat option do you want to execute? \n\n");
    printf("\t(1) View balance\n");
    printf("\t(2) Deposit value\n");
    printf("\t(3) Remove value\n");
    printf("\t(4) Make transfer\n");
    printf("\t(5) View registration date\n");
    printf("\t(6) View transfer limit\n");
    printf("\t(7) View extract\n");
    printf("\t(8) Exit the client menu\n");
    printf("Choose one: ");
    scanf("%d", &option);
    printf("\n");
    switch(option){
      case 1:
        system("clear");
        printf("HOME / CLIENT MENU / VIEW BALANCE\n\n");
        view_balance(matricula);
        logger(option, matricula, value);
        printf("\nType enter to return to the client menu.");
        __fpurge(stdin);
        getc(stdin);
        break;
      case 2:
        system("clear");
        printf("HOME / CLIENT MENU / DEPPOSIT\n\n");
        value = deposit(matricula);
        logger(option, matricula, value);
        printf("\nType enter to return to the client menu.");
        __fpurge(stdin);
        getc(stdin);
        break;
      case 3:
        system("clear");
        printf("HOME / CLIENT MENU / REMOVE VALUE\n\n");
        printf("\nType enter to return to the client menu.");
        __fpurge(stdin);
        getc(stdin);
        break;
      case 4:
        system("clear");
        printf("HOME / CLIENT MENU / MAKE TRANSFER\n\n");
        printf("\nType enter to return to the client menu.");
        __fpurge(stdin);
        getc(stdin);
        break;
      case 5:
        system("clear");
        printf("HOME / CLIENT MENU / VIEW REGISTRATION DATE\n\n");
        printf("\nType enter to return to the client menu.");
        __fpurge(stdin);
        getc(stdin);
        break;
      case 6:
        system("clear");
        printf("HOME / CLIENT MENU / VIEW TRANSFER LIMIT\n\n");
        printf("\nType enter to return to the client menu.");
        __fpurge(stdin);
        getc(stdin);
        break;
      case 7:
        system("clear");
        printf("HOME / CLIENT MENU / VIEW EXTRACT\n\n");
        printf("\nType enter to return to the client menu.");
        __fpurge(stdin);
        getc(stdin);
        break;
      case 8:
        k = 0;
        break;
      default:
        printf("Invalid option, try again.\n");
        break;
    }
  }
}

void view_balance(char *matricula){
  FILE *file = fopen("storage/accounts.csv", "r");
  int file_lines = number_of_file_lines(file);
  List *accounts = create_list_accounts(file, file_lines);
  List *aux;
  float balance;
  for (aux = accounts; aux != NULL; aux = aux->next){
    char *comp_mat = get_client_matricula(aux->data->client);
    if (strcmp(matricula, comp_mat) == 0){
      balance = get_client_balance(aux->data->client);
      break;
    }
  }
  printf("Your balance is : %.2f\n", balance);
}

float deposit(char *authentic_mat){
  List *client = NULL;
  FILE *file = fopen("storage/accounts.csv", "r");
  int file_lines = number_of_file_lines(file);
  rewind(file);
  List *list = create_list_accounts(file, file_lines);
  rewind(file);
  fclose(file);
  List *aux;
  for (aux = list; aux != NULL; aux = aux->next){
    char *matricula = get_client_matricula(aux->data->client);
    if (strcmp(matricula, authentic_mat) == 0){
      client = aux;
      break;
    }
  }
  if (client == NULL){
    printf("Matricula nao corresponde.\n");
  }
  int n = 1;
  float value;
  while (n) {
    printf("Type '0' to exit.\n");
    printf("Or enter the amount to be deposited: \n");
    scanf("%f", &value);
    if (value == 0){
      return 0;
    } else if (value / 0.01 < 1){
        printf("Invalid value, try again.\n");
    } else {
        n = 0;
      }
  }
  char *name = get_client_name(client->data->client);
  float balance = get_client_balance(client->data->client);
  float transfer_limit = get_client_transfer_limit(client->data->client);
  char *reg_date = get_reg_date(client->data->client);
  delete_client_account(authentic_mat);
  balance = balance + value;
  file = fopen("storage/accounts.csv", "a");
  fprintf(file, "%s,%s,%.2f,%.2f,%s,\n", name, authentic_mat, balance, transfer_limit, reg_date);
  rewind(file);
  fclose(file);
  printf("Successfull deposit.\n");
  return value;
}

void new_client(Client *client){
  client->name = (char*) malloc(50 * sizeof(char));
  client->matricula = (char*) malloc(20 * sizeof(char));
  client->char_balance = (char*) malloc(50 * sizeof(char));
  client->char_transfer_limit = (char*) malloc(50 * sizeof(char));
  client->reg_date = (char*) malloc(14 * sizeof(char));
}

char* get_client_name(Client *node){
  char *name = (char*) malloc(50 * sizeof(char));
  strcpy(name, node->name);
  return name;
}
char* get_client_matricula(Client *node){
  char *matricula = malloc(50 * sizeof(char));
  strcpy(matricula, node->matricula);
  return matricula;
}

float get_client_balance(Client *node){
  float balance = node->balance;
  return balance;
}
float get_client_transfer_limit(Client *node){
  float transfer_limit = node->transfer_limit;
  return transfer_limit;
}

char* get_reg_date(Client *node){
  char *reg_date = (char*) malloc(14 * sizeof(char));
  strcpy(reg_date, node->reg_date);
  return reg_date;
}

void set_client_name(Client *node, char *name){
  strcpy(node->name, name);
}

void set_client_balance(Client *node, float balance){
  node->balance = balance;
}

void set_client_transfer_limit(Client *node, float transfer_limit){
  node->transfer_limit = transfer_limit;
}

void set_client_matricula(Client *node, char *matricula){
  strcpy(node->matricula, matricula);
}

void set_client_char_balance(Client *node, char *balance){
  strcpy(node->char_balance, balance);
}

void set_client_char_transfer_limit(Client *node, char *transfer_limit){
  strcpy(node->char_transfer_limit, transfer_limit);
}

void set_client_reg_date(Client *node, char *date){
  strcpy(node->reg_date, date);
}

List* create_list_accounts(FILE *file, int file_lines){
  List *list = (List*) NULL;
  if (file == NULL){
    printf("Arquivo nao pode ser aberto.\n");
    return list;
  }
  rewind(file);
  char first_column[50], second_column[50], fifth_column[14];
  float third_column;
  float fourth_column;
  int i = 0;
  while(i < file_lines){
    fscanf(file, "%[^,],%[^,],%f,%f,%[^,],\n", first_column, second_column, &third_column, &fourth_column, fifth_column);
    List *new_block = (List*) malloc(sizeof(List));
    new_block->data = malloc(sizeof(Client)); //YOU HAVE TO MALLOC THE DATA UNION AND THE CLIENT STRUCT THAT IS INSIDE DATA
    new_block->data->client = (Client*) malloc(sizeof(Client));
    new_client(new_block->data->client);
    set_client_name(new_block->data->client, first_column);
    set_client_matricula(new_block->data->client, second_column);
    set_client_balance(new_block->data->client, third_column);
    set_client_transfer_limit(new_block->data->client, fourth_column);
    set_client_reg_date(new_block->data->client, fifth_column);
    List *aux;
    if (list == NULL){
      new_block->prev = (List*) NULL;
      new_block->next = (List*) NULL;
      list = new_block;
      aux = list;
    }
    else {
      new_block->prev = aux;
      new_block->next = (List*) NULL;
      aux->next = new_block;
      aux = aux->next;
    }
    i++;
  }

  return list;
}

List* create_list_char(FILE *file, int file_lines){
  List *list = (List*) NULL;
  if (file == NULL){
    printf("Arquivo nao pode ser aberto.\n");
    return list;
  }
  rewind(file);
  char first_column[50], second_column[50], third_column[50], fourth_column[50], fifth_column[14];
  int i = 0;
  while(i < file_lines){
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column, fifth_column);
    List *new_block = (List*) malloc(sizeof(List));
    new_block->data = malloc(sizeof(Client));
    new_block->data->client = malloc(sizeof(Client));
    new_client(new_block->data->client);
    set_client_name(new_block->data->client, first_column);
    set_client_matricula(new_block->data->client, second_column);
    set_client_char_balance(new_block->data->client, third_column);
    set_client_char_transfer_limit(new_block->data->client, fourth_column);
    set_client_reg_date(new_block->data->client, fifth_column);
    List *aux;
    if (list == NULL){
      new_block->prev = (List*) NULL;
      new_block->next = (List*) NULL;
      list = new_block;
      aux = list;
    }
    else {
      new_block->prev = aux;
      new_block->next = (List*) NULL;
      aux->next = new_block;
      aux = aux->next;
    }
    i++;
  }
  return list;
}

void print_list_of_clients(List *list){
	List *aux;
  int i = 0;
	for (aux=list; aux!=NULL; aux=aux->next){
    i++;
    printf("NAME OF CLIENT %d: %s\n", i, aux->data->client->name);
    printf("MATRICULA OF CLIENT %d: %s\n", i, aux->data->client->matricula);
    printf("BALANCE OF CLIENT %d: %.2f\n", i, aux->data->client->balance);
    printf("TRANSFER LIMIT OF CLIENT %d: %.2f\n", i, aux->data->client->transfer_limit);
    printf("REGISTRATION DATE OF CLIENT %d: %s\n", i, aux->data->client->reg_date);
    printf("\n");
	}
}

void print_char_list(List *list){
  List *aux;
  int i = 0;
  for (aux=list; aux!=NULL; aux=aux->next){
    i++;
    printf("NAME OF CLIENT %d: %s\n", i, aux->data->client->name);
    printf("MATRICULA OF CLIENT %d: %s\n", i, aux->data->client->matricula);
    printf("BALANCE OF CLIENT %d: %s\n", i, aux->data->client->char_balance);
    printf("TRANSFER LIMIT OF CLIENT %d: %s\n", i, aux->data->client->char_transfer_limit);
    printf("REGISTRATION DATE OF CLIENT %d: %s\n", i, aux->data->client->reg_date);
    printf("\n");
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

void logger(int option, char *matricula, float value){
  FILE *file = fopen("storage/production.log", "a");
  int day = date_day();
  int month = date_month();
  int year = date_year();
  int hour = time_hour();
  int minutes = time_minutes();
  int seconds = time_seconds();
  switch (option) {
    case 1:
      fprintf(file, "%s,visualized the balance,%d/%d/%d,%d:%d:%d,\n", matricula,day,month,year,hour,minutes,seconds);
      break;
    case 2:
      fprintf(file, "%s,deposited $ %.2f,%d/%d/%d,%d:%d:%d,\n", matricula,value,day,month,year,hour,minutes,seconds);
      break;
  }
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
}
