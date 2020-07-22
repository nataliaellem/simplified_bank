# Simplified Bank

## Introduction
    This project, whose sole purpose is learning, consists of a simpified bank program in which there are  functions that perform client activities and manager activities. In the storage folder there are files  that store login, manager and customer information, customer bank information, statements and, finally,  files that store the latest registered enrollment numbers. Inside the lib folder you can find the source  codes, while the headers are in the includes folder. Finally, there are some tests in the tests folder, as well as the main function, in the main.c file, outside that scope. The program can be run with the  makefile, which will be specified bellow, as well as the other files.
   
## Includes Folder
    
    In the list.h file, the struct 'List' is defined, which will be used in linked lists throughout the code. The union 'Data', attribute of 'List', is defined in the models.h folder. Also in this folder, the structs 'user' and 'client' are defined. The struct user is used in functions that handle user logins while 'client' contains client attributes such as balance, transfer limit and registration date.
    
## Lib Folder
#### Client.c

The client menu function presents the options that the client type user can execute and calls the functions related to the respective options. The "view char data" function prints the information of the logged user on the screen, which is of the char pointer type. The "change balance" function can deposit or remove amounts from the user's balance. In turn, the "get receiver matricula" can be linked to the "make transfer" to receive from the keyboard a registration number that will be used to make a transfer in "make transfer". While "new client" allocates memory for the struct client attributes, the "get" and "set" functions respectively return attributes already contained and insert new attributes in "Client" type pointers. The attributes "balance" and "transfer limit" in some cases are more convenient when identified as "char *" and in other cases as "float". Therefore, the "create list accounts" and "create list char" functions have this distinction "as well as the print accounts," print list of cliets "and" print char list "functions. "Delete client account" deletes a line (representing an account) from the file "accounts.cvs", "view extract" shows the actions already done by the logged in user, "logger" detects the user's actions and stores it in the "production" file. log "and, finally," clear database "clears the files" login.csv "and" accounts.csv ", as these have lines filled with exclamations ("!") when a user is removed.                             

### Helper.c


This file contains some functions that are important in the program but that are not specifically related to client or manager activities. The "reading" function reads user strings in a way that does not waste memory. "Sort list" sorts a list of strings, "number of file lines" receives a file and counts how many lines it has, and finally, the other functions return the current time and date.

### Homepage.c


This file contains only the "login" function, which asks for and verifies the registration and password of the user, as well as their role (customer or manager). This function displays the login screen during execution until the user enters '0' to exit.



