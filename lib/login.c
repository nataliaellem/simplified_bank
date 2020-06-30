#include "../includes/login.h"

User* login(){
  char *matricula = (char*) malloc(20 * sizeof(char));
  printf("Do you want to login as a client or as a manager?\n");
  printf("\t(1)Client\n");
  printf("\t(2)Manager\n");
  printf("Choose one of the options\n");
  int option;
  int k = 1;
  while(k){
    scanf("%d", &option);
    switch (option) {
      case 1:
      printf("Digite sua matricula: \n");
      __fpurge(stdin);
      scanf("%[^\n]", matricula);
      printf("\n");

      k = 0;
      break;
      case 2:
      k = 0;
      break;
      default:
      printf("Invalid option, try again.");
      break;
    }

  }
  // int i = 0;
  // char *matricula = (char*) malloc(1 * sizeof(char));
  // char c = matricula[i];
  // while (c != '\n'){
  //   scanf("%c", &matricula[i]);
  //   char c = matricula[i];
  //   i++;
  //   matricula = (char*) realloc(matricula, (i+1) * sizeof(char));
  //   printf("MATRICULA: %s\n", matricula);
  // }

  User *user = NULL;
  return user;
}

void new_login(User *user){
  user->name = (char*) malloc(50 * sizeof(char));
  user->password = (char*) malloc(10 * sizeof(char));
  user->matricula = (char*) malloc(20 * sizeof(char));
  user->role = (char*) malloc(10 * sizeof(char));
}

char* get_user_name(User *user){
  char *name = (char*) malloc(50 * sizeof(char));
  strcpy(name, user->name);
  return name;
}

char* get_user_matricula(User *user){
  char *matricula = (char*) malloc(20 * sizeof(char));
  strcpy(matricula, user->matricula);
  return matricula;
}

char* get_user_password(User *user){
  char *password = (char*) malloc(10 * sizeof(char));
  strcpy(password, user->password);
  return password;
}

char* get_user_role(User *user){
  char *role = (char*) malloc(10 * sizeof(char));
  strcpy(role, user->role);
  return role;
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
  int i = 0;
  while(i < file_lines){
    char first_column[50], second_column[50], third_column[50], fourth_column[50];
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column);
    List *new_block = (List*) malloc(sizeof(List));
    new_block->data = (Data*) malloc(sizeof(Data));
    new_block->data->user = (User*) malloc(sizeof(User));
    new_login(new_block->data->user);
    set_user_name(new_block->data->user, first_column);
    set_user_matricula(new_block->data->user, second_column);
    set_user_password(new_block->data->user, third_column);
    set_user_role(new_block->data->user, fourth_column);
    List *aux;
    if (list == NULL){
      new_block->prev = (List*) NULL;
      new_block->next = (List*) NULL;
      list = new_block;
      aux = list;
    } else {
      new_block->prev = aux;
      new_block->next = (List*) NULL;
      aux->next = new_block;
      aux = aux->next;
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
    printf("NAME OF USER %d: %s\n", i, aux->data->user->name);
    printf("MATRICULA OF USER %d: %s\n", i, aux->data->user->matricula);
    printf("PASSWORD OF USER %d: %s\n", i, aux->data->user->password);
    printf("ROLE OF USER %d: %s\n", i, aux->data->user->role);
    printf("\n");
  }
}

List* new_user_block(List *list, User *user){
  List *new_block = (List*) malloc(sizeof(List));
  new_block->data = (Data*) malloc(sizeof(Data));
  new_block->data->user = (User*) malloc(sizeof(User));
  char *name = get_user_name(user);
  char *matricula = get_user_matricula(user);
  char *password = get_user_password(user);
  char *role = get_user_role(user);
  new_login(new_block->data->user);
  set_user_name(new_block->data->user, name);
  set_user_matricula(new_block->data->user, matricula);
  set_user_password(new_block->data->user, password);
  set_user_role(new_block->data->user, role);
  if (list == NULL){
    new_block->prev = (List*) NULL;
    new_block->next = (List*) NULL;
    list = new_block;
  } else {
    List *aux;
    for (aux = list; aux->next != NULL; aux = aux->next);
    new_block->prev = aux;
    new_block->next = (List*) NULL;
    aux->next = new_block;
  }
  return list;
}

List* filter_logins(List *list, char* (*block)(User*), char *attribute){
  List *aux;
  List *filtered_list = (List*) NULL;
  int i = 0;
  for (aux = list; aux != NULL; aux = aux->next){
    i++;
    char *role = (*block)(aux->data->user);
    if (strcmp(role, attribute) == 0){
      filtered_list = new_user_block(filtered_list, aux->data->user);
    }
  }

  return filtered_list;
}
