#include "../includes/client.h"

void client_menu(List *node){
  node->data->client = malloc(sizeof(Client));
  new_client(node->data->client);
  char *matricula = get_user_matricula(node->data->user);
}

void new_client(Client *client){
  client->name = (char*) malloc(50 * sizeof(char));
  client->matricula = (char*) malloc(20 * sizeof(char));
  client->char_balance = (char*) malloc(50 * sizeof(char));
  client->char_transfer_limit = (char*) malloc(50 * sizeof(char));
}

char* get_client_name(Client *node){
  char *name = malloc(50 * sizeof(char));
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

List* create_list_accounts(FILE *file, int file_lines){
  List *list = (List*) NULL;
  if (file == NULL){
    printf("Arquivo nao pode ser aberto.\n");
    return list;
  }
  rewind(file);
  char first_column[50], second_column[50];
  float third_column;
  float fourth_column;
  int i = 0;
  while(i < file_lines){
    fscanf(file, "%[^,],%[^,],%f,%f,\n", first_column, second_column, &third_column, &fourth_column);
    List *new_block = (List*) malloc(sizeof(List));
    new_block->data = malloc(sizeof(Client)); //YOU HAVE TO MALLOC THE DATA UNION AND THE CLIENT STRUCT THAT IS INSIDE DATA
    new_block->data->client = malloc(sizeof(Client));
    new_client(new_block->data->client);
    set_client_name(new_block->data->client, first_column);
    set_client_matricula(new_block->data->client, second_column);
    set_client_balance(new_block->data->client, third_column);
    set_client_transfer_limit(new_block->data->client, fourth_column);
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
  char first_column[50], second_column[50], third_column[50], fourth_column[50];
  int i = 0;
  while(i < file_lines){
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
    List *new_block = (List*) malloc(sizeof(List));
    new_block->data = malloc(sizeof(Client));
    new_block->data->client = malloc(sizeof(Client));
    new_client(new_block->data->client);
    set_client_name(new_block->data->client, first_column);
    set_client_matricula(new_block->data->client, second_column);
    set_client_char_balance(new_block->data->client, third_column);
    set_client_char_transfer_limit(new_block->data->client, fourth_column);
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
    printf("\n");
  }
}
