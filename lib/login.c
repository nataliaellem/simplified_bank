#include "../includes/login.h"

User* login(){
  printf("Digite sua matricula: \n");
  User *user = NULL;
  return user;
}

void new_login(User *user){
  user->name = (char*) malloc(50 * sizeof(char));
  user->password = (char*) malloc(8 * sizeof(char));
  user->matricula = (char*) malloc(20 * sizeof(char));
  user->role = (char*) malloc(10 * sizeof(char));
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

List* create_list_logins(FILE *file, int file_lines){
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
    new_block->data = (Data*) malloc(sizeof(Data));
    new_block->data->user = (User*) malloc(sizeof(User));
    new_login(new_block->data->user);
    set_user_name(new_block->data->user, first_column);
    set_user_matricula(new_block->data->user, second_column);
    set_user_password(new_block->data->user, third_column);
    set_user_role(new_block->data->user, fourth_column);
    if (list == NULL){
      new_block->prev = (List*) NULL;
      new_block->next = (List*) NULL;
      list = new_block;
    }
    else {
      List *aux;
      // MEUS OLHOS SANGRARAM QUANDO EU VI ISSO GSUIS
      for (aux=list; aux->next!=NULL; aux=aux->next);
      new_block->prev = aux;
      new_block->next = (List*) NULL;
      aux->next = new_block;
    }
    i++;
  }

  return list;
}

void print_list_logins(List *list){
  List *aux;
  int i = 0;
  for (aux=list; aux!=NULL; aux=aux->next){
    i++;
    printf("%x\n", aux->data);

    printf("NAME OF USER %d: %s\n", i, aux->data->user->name);//HERE IS THE ERROR
    printf("DEBUG\n");
    printf("MATRICULA OF USER %d: %s\n", i, aux->data->user->matricula);
    printf("PASSWORD OF USER %d: %s\n", i, aux->data->user->password);
    printf("ROLE OF USER %d: %s\n", i, aux->data->user->role);
    printf("\n");
  }
}
