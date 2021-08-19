/*
 * Michael Stepp
 * functions.c
 * Functions for main
*/

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "functions.h"

//Exit Statuses
#define EXIT_TEMPERATURE 2
#define EXIT_UPDATE 3
#define EXIT_EXIT 4
#define EXIT_RESTART 5

/*
 * Handles the script and command requests with a fork()
 * @param name name of the command or script
 * @param args array of arguments for the script  
*/
void handleRequest(char *name, char *args[]){
	int pid, c_pid;

	//Fork program, child will run exec and handle the scripts
	pid = fork();
	switch (pid){
		//Failure
		case -1:
			fprintf(stderr, "Fork Error!\n");
			return;
		//Child Process to run execvp
		case 0:
			printf("Executing: %s\n", name);
			execvp(name, args);
		//Parent process
		default:
			c_pid = wait(NULL);
			//printf("Child pid: %d\n", c_pid);    //for error testing
	}
}

/*
 * Prints the menu  
*/
void printMenu(){
	printf("================================================================\n");
	printf("||                                                            ||\n");
	printf("||          PLEASE SELECT FROM THE FOLLOWING OPTIONS          ||\n");
	printf("||                                                            ||\n");
	printf("================================================================\n");
	printf("||                             ||                             ||\n");
	printf("||(1) View System Information  ||(7) View Network Information ||\n");
	printf("||                             ||                             ||\n");
  	printf("||------------------------------------------------------------||\n");
	printf("||                             ||                             ||\n");
 	printf("||(2) View Current Restart Log ||(8) Open Calculator          ||\n");
	printf("||                             ||                             ||\n");
 	printf("||------------------------------------------------------------||\n");
	printf("||                             ||                             ||\n");
  	printf("||(3) View Kicked Log          ||(9) Update System Software   ||\n");
	printf("||                             ||                             ||\n");
  	printf("||------------------------------------------------------------||\n");
	printf("||                             ||                             ||\n");
	printf("||(4) View Error Log           ||(10) Exit Server             ||\n");
	printf("||                             ||                             ||\n");
  	printf("||------------------------------------------------------------||\n");
	printf("||                             ||                             ||\n");
	printf("||(5) View Update Log          ||(11) Restart Server          ||\n");
	printf("||                             ||                             ||\n");
  	printf("||------------------------------------------------------------||\n");
	printf("||                             ||                             ||\n");
	printf("||(6) Get CPU Temperature      ||(12) Exit Program            ||\n");
	printf("||                             ||                             ||\n");
	printf("================================================================\n");
}



/* 
 * Handles the menu options 
 * @param input character holding the value of the menu option
 * @returns exit status, or -1 to represent a continue
*/ 
int handleMenuOption (char input){
	//Switch to control the menu
	switch (input){
		//Print server info
		case 1:{
			char *args[] = {NULL};
			handleRequest("../server_info", args);
			break;
		}
		//Print current restart log
		case 2:{
			char *args[] = {"cat", "../../logs/restarts.log", NULL};
			handleRequest("/bin/cat", args);
			break;
	        }
		//Print kicked log
		case 3: {
			char *args[] = {"cat", "../../logs/kicked.log", NULL};	
			handleRequest("/bin/cat", args);
			break;
		}
		//Print Error Log
		case 4: {
			char *args[] = {"cat", "../../logs/errors.log", NULL};
			handleRequest("/bin/cat", args);
			break;
		}
		//Print update log
		case 5: {
			char *args[] = {"cat", "../../logs/updates.log", NULL};
			handleRequest("/bin/cat", args);
			break;
		}
		//Get CPU Temperature
		case 6: {
			return EXIT_TEMPERATURE;
			break;
		}
		//Print Network Information
		case 7: {
			char *args[] = {NULL};
			handleRequest("../network_info", args);
			break;
		}
		//Open Calculator
		case 8: {
			char *args[] = {NULL};
			handleRequest("../calculator/calculator", args);
			break;
		}
		// Update System Software
		case 9: {
			return EXIT_UPDATE;
			break;
		}
		//Exit Server
		case 10: {
			return EXIT_EXIT;
		}
		
		//Restart Server
		case 11: {
			return EXIT_RESTART;
		}
		//Terminate Program
		case 12: {
			printf("Terminating Program\n");
			printf("Have a nice day!\n");
			return EXIT_SUCCESS;
		}
		default:
			printf("Please choose a valid option!\n");
	}

	//go back to break
	return -1;
}
