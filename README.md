# Simplified Bank


## Introduction

### Resume

This project, whose sole purpose is learning, consists of a simpified bank program in which there are  functions that perform client activities and manager activities. In the storage folder there are files  that store login, manager and customer information, customer bank information, statements and, finally,  files that store the latest registered enrollment numbers. Inside the lib folder you can find the source  codes, while the headers are in the includes folder. Finally, there are some tests in the tests folder, as well as the main function, in the main.c file, outside that scope. The program can be run with the  makefile, which will be specified bellow, as well as the other files.

## Includes Folder

In the list.h file, the struct 'List' is defined, which will be used in linked lists throughout the code. The union 'Data', attribute of 'List', is defined in the models.h folder. Also in this folder, the structs 'user' and 'client' are defined. The struct user is used in functions that handle user logins while 'client' contains client attributes such as balance, transfer limit and registration date.

## Lib Folder

#### Client.c

The client menu function presents the options that the client type user can execute and calls the functions related to the respective options. The "view char data" function prints the information of the logged user on the screen, which is of the char pointer type. The "change balance" function can deposit or remove amounts from the user's balance. In turn, the "get receiver matricula" can be linked to the "make transfer" to receive from the keyboard a registration number that will be used to make a transfer in "make transfer". While "new client" allocates memory for the struct client attributes, the "get" and "set" functions respectively return attributes already contained and insert new attributes in "Client" type pointers. The attributes "balance" and "transfer limit" in some cases are more convenient when identified as "char*" and in other cases as "float". Therefore, the "create list accounts" and "create list char" functions have this distinction "as well as the print accounts," print list of cliets "and" print char list "functions. "Delete client account" deletes a line (representing an account) from the file "accounts.cvs", "view extract" shows the actions already done by the logged in user, "logger" detects the user's actions and stores it in the "production" file. log "and, finally," clear database "clears the files" login.csv "and" accounts.csv ", as these have lines filled with exclamations ("!") when a user is removed.                             

### Helper.c

This file contains some functions that are important in the program but that are not specifically related to client or manager activities. The "reading" function reads user strings in a way that does not waste memory. "Sort list" sorts a list of strings, "number of file lines" receives a file and counts how many lines it has, and finally, the other functions return the current time and date.

### Homepage.c

This file contains only the "login" function, which asks for and verifies the registration and password of the user, as well as their role (customer or manager). This function displays the login screen during execution until the user enters '0' to exit.

### List.c

In list.c, "new node" allocates a new block of type "List", "delete block" takes a linked list and a position from that list and removes the block that is in that position and, finally, "new linked block" takes a linked list, empty or not, and adds a new block with data already assigned to it.

### Login.c

This file contains functions that use the "user" struct within linked lists. First "new login" allocates in memory the attributes (char*) of "user", right after the "get" and "set" functions respectively, take the user's attribute and insert a new attribute in a user. "Create list logins" creates a linked list with the lines from the "login.csv" file while "print list logins" prints this list. Finally, "new block" receives a linked list and inserts a block of type "user" in this list, calling the function "new linked block", and "filter logins" receives a list, a "get" function pointer, an attribute (string) and returns a list of users that contain the received attribute.

### Manager.c

This file contains the functions related to the actions that the logged manager can perform on the system. First, the menu shows the options and calls the respective functions. The manager can create a new account with "create new account", delete an account with "delete account", change a customer's transfer limit with "change transfer limit", list customers in alphabetical order, list customers by registration date with "list by reg date" and list bank reserves with "bank reserve".

## Storage


Accounts.csv contains customer account information and login.csv contains information regarding manager and customer logins. To store and assist in the creation of new accounts, the files "client_mat.val" and "manager_mat.val" contain the latest registrations of customers and managers registered in the system. Finally, in "production.log" are customer statements.

## Execution


To run the program on the Linux Deepin SO, just call the "Makefile" file in the terminal.
