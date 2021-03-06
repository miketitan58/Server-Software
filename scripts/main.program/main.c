/*
 * Michael Stepp
 * main.c
 * Program that provides the user with a 
 * simple menu and will take input to
 * handle the running of various scripts
 * and or bash commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include  <sys/types.h>
#include "functions.h"


//Buffer
#define BUFF_SIZE 100

//Exit Statuses
#define EXIT_TEMPERATURE 2
#define EXIT_UPDATE 3
#define EXIT_EXIT 4
#define EXIT_RESTART 5

/*
 * Main function
*/ 
int main (int argc, char * argv[]){
  	//Variables
	int choice, result, iterations = 0;
	char inputBuffer[BUFF_SIZE];
	
	//Loop through main program
	while(1){
		//Prompt user for input
		printf("Press ENTER key to continue...\n");
		if(fgets(inputBuffer, BUFF_SIZE, stdin) == NULL){
			fprintf(stderr, "EOF Detected");
			return EXIT_FAILURE;
		}

		//If input is just 'enter' then run program, else give message and try again
		if(strcmp(inputBuffer, "\n") == 0){
			//Returning to menu message
			if(iterations > 0){
				printf("RETURNING TO THE MAIN MENU\n");
				sleep(1);
			}

			//Clear the screen
			system("clear");

			//Print Menu
			printMenu();

			//Get user input ... CHANGE TO FGETS AND SSCANF
			scanf("%d", &choice);

			//Clear the screen again for incoming script
			system("clear");

			//Hnadle the manu items, then get exit status or continue
			result = handleMenuOption(choice);
			switch(result){
				case 1:
					return EXIT_FAILURE;     //Close program with failure
				case 2: 
					return EXIT_TEMPERATURE; //Get CPU Temperature
				case 3:
					return EXIT_UPDATE;      //Update System Software
				case 4:
					return EXIT_EXIT;        //Exit server
				case 5:
					return EXIT_RESTART;     //Restart Server
				case 0: 
					return EXIT_SUCCESS;     //Close program successfully
				defualt:
					break;
			}
		}
		else{
			printf("Only press the ENTER key\n");
			printf("Pleae try again...\n");
		}

		//Take '\n' our of the input stream
		getchar();
		iterations++;
	}

	//Redundant return statement, there no reason this should ever happen
	return EXIT_FAILURE;
}
