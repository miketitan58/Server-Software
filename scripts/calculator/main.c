/*
	Michael Stepp
	Calculator Program
	Simple Menus, straightforward program
*/

#include <stdio.h>
#include "functions.h"

int main (int argc, char * argv[]){
	int response = -1;

	printf("\n");
	printf("Welcome to the calculator program.\n");
	printf("\n");
		
	while ( response != 6 ){
		
		printf("\n");
		printf("********************************\n");
		printf("*          MAIN MENU           *\n");
		printf("********************************\n");

		printf("\n");
		printf("What would you like to do?\n");
		printf("================================\n");	

		//Options		
		printf("|| (1) 4 Function Calculator  ||\n");
		printf("|| (2) Data Sets Calculators  ||\n");
		printf("|| (3) Precal Calculator      ||\n");
		printf("|| (4) Logarithmic Calculator ||\n");
		printf("|| (5) Square Root Calculator ||\n");
		printf("|| (6) Exit                   ||\n");
		printf("================================\n");

		//Get Response
		scanf("%d" , &response);

		//4 Function Calc
		if ( response == 1){
			calculator();
			printf("\n");
		}

		//Average Calculator
		if ( response == 2 ){
			int arrayLength = 0;
			printf("How many numbers are will be input in the data set?\n");
			scanf("%d" , &arrayLength);
			double array [arrayLength];

			//Loop to fill array
			int x;
			for (x = 0; x < arrayLength; x++){
				printf("Enter number %d:\n" , x);
				scanf("%lf" , &array[x]);
			}

			//Show data set
			printf("Your data set is:\n");
			printf("[ ");
			int y;
			for (y = 0; y < arrayLength; y++){
				printf("%0.3lf " , array[y]);
			}
			printf("]\n");

			//Calculate average
			double average = averageFunction(array, arrayLength);
			printf("Average: %0.3lf\n" , average);

			//Standard Deviation Calculator
			double standDev = StandardDeviation(array,arrayLength, average);
			printf("Standard Deviation: %0.3lf\n" , standDev);

			//Z-scores Calculator
			PrintZScores(array, arrayLength, standDev, average);
			printf("\n");
		}

		//Precal Calculator
		if ( response == 3){
			
			PrecalCalculator();
			
		}

		//Response 4
		if ( response == 4 ){
		
			logCalc();

		}

		//Square Root Calculator
		else if ( response == 5 ){
			double num;
			printf("Enter your number:\n");
			scanf("%lf" , &num);
			printf("Square root of %0.3lf is %0.3lf\n" , num , sqrtFunction(num));
		}

		//Exit
		else if ( response == 6 ){
			printf("End Program\n");
		}
	}

	return 0;
}
