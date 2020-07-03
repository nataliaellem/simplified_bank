#include "../includes/client.h"

void new_client(Client *client){
  client->name = (char*) malloc(50 * sizeof(char));
  client->matricula = (char*) malloc(20 * sizeof(char));
}

void set_client_name(Client *node, char *name){
  strcpy(node->name, name);
}

void set_client_balance(Client *node, char *balance){
  strcpy(node->balance, balance);
}

void set_client_transfer_limit(Client *node, char *transfer_limit){
  strcpy(node->transfer_limit, transfer_limit);
}

void set_client_matricula(Client *node, char *matricula){
  strcpy(node->matricula, matricula);
}

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
    new_block->data->client = (Client*) malloc(sizeof(Client));
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

void print_list_of_clients(List *list){
	List *aux;
  int i = 0;
	for (aux=list; aux!=NULL; aux=aux->next){
    i++;
    printf("NAME OF CLIENT %d: %s\n", i, aux->data->client->name);
    printf("MATRICULA OF CLIENT %d: %s\n", i, aux->data->client->matricula);
    printf("BALANCE OF CLIENT %d: %s\n", i, aux->data->client->balance);
    printf("TRANSFER LIMIT OF CLIENT %d: %s\n", i, aux->data->client->transfer_limit);
    printf("\n");
	}
}

void client_menu(List *node){
  printf("\n\n");
}
