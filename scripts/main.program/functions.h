/*
 * Michael Stepp
 * main.h
*/

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
void handleRequest(char *name, char *args[]);
void printMenu();
int handleMenuOption(char input);

#endif
