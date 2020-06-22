#include "../includes/list.h"

List create_list_(FILE *file, int file_lines){
  if (file == NULL){
    printf("Arquivo nao pode ser aberto.\n");
    return 0;
  }
  List *list = NULL;
  char first_column[50], second_column[50], third_column[50], fourth_column[50];
  while(!feof(file)){
    fscanf(file, "[^,],[^,],[^,],[^,]", first_column, second_column, third_column, fourth_column);
    List *new_block = (List*) malloc(sizeof(List));

  }
}

void set_client_name(List *block, char *name){
  strcpy(block->client.name, name);
}

void set_client_balance(List *block, float balance){
  block->client.balance = balance;
}

void set_client_transfer_limit(List *block, float transfer_limit){
  block->client.transfer_limit = transfer_limit;
}

void set_client_password(LIST *block, char *pass){
  strcpy(block->client.password, pass);
}

void set_client_matricula(List *block, char *matricula){
  strcpy(block->client.matricula, matricula);
}
