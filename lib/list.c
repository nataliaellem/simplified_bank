#include "../includes/list.h"

List* create_list_accounts(FILE *file, int file_lines){
  List *list = (List*) NULL;
  if (file == NULL){
    printf("Arquivo nao pode ser aberto.\n");
    return list;
  }
  rewind(file);
  char first_column[50], second_column[50], third_column[50], fourth_column[50];
  int i = 0;
  while(i < file_lines){
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
    // printf("FIRST COLUMN: %s\n", first_column);
    // printf("second COLUMN: %s\n", second_column);
    // printf("third COLUMN: %s\n", third_column);
    // printf("Fourth COLUMN: %s\n", fourth_column);
    List *new_block = (List*) malloc(sizeof(List));
    new_client(&new_block->client);
    set_client_name(new_block, first_column);
    set_client_matricula(new_block, second_column);
    set_client_balance(new_block, third_column);
    set_client_transfer_limit(new_block, fourth_column);
    if (list == NULL){
      new_block->prev = (List*) NULL;
      new_block->next = (List*) NULL;
      list = new_block;
    }
    else {
      List *aux;
      for (aux=list; aux->next!=NULL; aux=aux->next);
      new_block->prev = aux;
      new_block->next = (List*) NULL;
      aux->next = new_block;
    }
    i++;
  }

  return list;
}

User* create_list_logins(FILE *file, int file_lines){
  User *list = (User*) NULL;
  if (file == NULL){
    printf("Arquivo nao pode ser aberto.\n");
    return list;
  }
  rewind(file);
  char first_column[50], second_column[50], third_column[50], fourth_column[50];
  int i = 0;
  while(i < file_lines){
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
    User *new_block = (User*) malloc(sizeof(List));
    new_login(new_block);
    set_user_name(new_block, first_column);
    set_user_matricula(new_block, second_column);
    set_user_password(new_block, third_column);
    set_user_role(new_block, fourth_column);
    if (list == NULL){
      new_block->prev = (User*) NULL;
      new_block->next = (User*) NULL;
      list = new_block;
    }
    else {
      User *aux;
      for (aux=list; aux->next!=NULL; aux=aux->next);
      new_block->prev = aux;
      new_block->next = (User*) NULL;
      aux->next = new_block;
    }
    i++;
  }

  return list;
}

void print_list_logins(User *list){
  User *aux;
  int i = 0;
  for (aux=list; aux!=NULL; aux=aux->next){
    i++;
    printf("NAME OF USER %d: %s\n", i, aux->name);
    printf("MATRICULA OF USER %d: %s\n", i, aux->matricula);
    printf("PASSWORD OF USER %d: %s\n", i, aux->password);
    printf("ROLE OF USER %d: %s\n", i, aux->role);
    printf("\n");
  }
}

void print_list_of_clients(List *list){
	List *aux;
  int i = 0;
	for (aux=list; aux!=NULL; aux=aux->next){
    i++;
    printf("NAME OF CLIENT %d: %s\n", i, aux->client.name);
    printf("MATRICULA OF CLIENT %d: %s\n", i, aux->client.matricula);
    printf("BALANCE OF CLIENT %d: %2f\n", i, aux->client.balance);
    printf("TRANSFER LIMIT OF CLIENT %d: %2f\n", i, aux->client.transfer_limit);
    printf("\n");
	}
}

void new_login(User *user){
  user->name = (char*) malloc(50 * sizeof(char));
  user->password = (char*) malloc(8 * sizeof(char));
  user->matricula = (char*) malloc(20 * sizeof(char));
  user->role = (char*) malloc(10 * sizeof(char));
}

void new_client(Client *client){
  client->name = (char*) malloc(50 * sizeof(char));
  client->matricula = (char*) malloc(20 * sizeof(char));
}

void set_client_name(List *block, char *name){
  strcpy(block->client.name, name);
}

void set_client_balance(List *block, char *balance){
  block->client.balance = atof(balance);
}

void set_client_transfer_limit(List *block, char *transfer_limit){
  block->client.transfer_limit = atof(transfer_limit);
}

void set_client_matricula(List *block, char *matricula){
  strcpy(block->client.matricula, matricula);
}

void set_user_name(User *user, char *name){
  strcpy(user->name, name);
}

void set_user_matricula(User *user, char *matricula){
  strcpy(user->matricula, matricula);
}

void set_user_password(User *user, char *password){
  strcpy(user->password, password);
}

void set_user_role(User *user, char *role){
  strcpy(user->role, role);
}
