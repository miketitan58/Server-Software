/*
	Michael Stepp
	Functions File
*/

#include "functions.h"

//CALCULATOR AND ITS FUNTIONS\/\/
void calculator(){

	bool quit = false;
	int response;

	//Loops Calculator
	while(quit == false){

		int numAdded;
		double sumArray [50];
		
		printf("Calculator: \n");
		printf("What would you like to do?\n");
		printf("(1) Addition \n");
		printf("(2) Subtraction \n");
		printf("(3) Multiplication \n");
		printf("(4) Division \n");
		printf("(5) Exit Calculator \n");
		
		scanf("%d" , &response);

		//Addition
		if( response == 1 ){

			printf("How many numbers will be added?\n");
			scanf("%d" , &numAdded);
			if (numAdded == 2){
				//Add the two numbers
				double sum;
				double num1;
				double num2;
				printf("Enter number 1\n");
				scanf("%lf", &num1);
				printf("Enter number 2\n");
				scanf("%lf", &num2);
				sum = num1 + num2;
				printf("Sum: %0.3lf\n", sum);				
			}
			else if (numAdded > 2){
				//Add function with the array
				int x;
				double temp;
				for(x = 0; x < numAdded; x++){
					printf("Enter number %d\n" , x);
					scanf("%lf" , &temp);
					sumArray[x] = temp;
				}
				printf("Sum: %0.3lf\n" , addFunction(sumArray, numAdded));
				printf("\n");
			}
			else{
				printf("Sorry you must add more than two numbers\n");
			}
		}

		//Subtraction
		else if ( response == 2 ){
			double num1;
			double num2;
			printf("Enter number 1: \n");
			scanf("%lf" , &num1);
			printf("Enter number 2: \n");
			scanf("%lf" , &num2);
			printf("Difference: %0.3lf\n" , subFunction(num1 , num2));
			printf("\n");
		}		

		//Multiplication
		else if ( response == 3 ){
			int num;
			double array [50];
			printf("How many numbers will be multiplied?\n");
			scanf("%d" , &num);			
			
			if ( num >= 2 ){
				int x;
				for ( x = 0; x < num; x++ ){
					printf("Enter number %d \n" , x);
					scanf("%lf" , &array[x]);
				}
				printf("Product: %0.3lf\n" , multFunction(array, num));
			}
			else {
				printf("Sorry you must multiply more than two numbers\n");
			}
		}		

		//Division
		else if ( response == 4 ){
			double num1;
			double num2;
			printf("Enter the first number:\n");
			scanf("%lf" , &num1);
			printf("Enter the second number:\n");
			scanf("%lf" , &num2);
			printf("Quotient: %0.3lf\n" , divFunction(num1 , num2));
			printf("\n");
		}

		//Exit Program
		if (response == 5){
			quit = true;
		}

	}

	printf("Returning to Main Menu...\n");
	return;
}

//Addition Function
double addFunction(double array [], int num){

	double sum = 0.0;
	int x = 0;
	for (x = 0; x < num; x++){
		sum += array[x];
	}	

	return sum;
}

//Subtraction Function
double subFunction(double num1, double num2){

	double difference;
	difference = num1 - num2;

	return difference;
}

//Multiplication Function
double multFunction(double array [], double num){

	double product = 1;
	int x;
	for (x = 0; x < num; x++){
		product = product * array[x];
	}

	return product;
}

//Division Function
double divFunction(double num1, double num2){

	double quotient;
	quotient = num1 / num2;

	return quotient;
}

//Square Root Function
double sqrtFunction(double num){
	
	double temp;
	double sqrt = num / 2.0;

	while (sqrt != temp){
		temp = sqrt;
		sqrt = (num/temp + temp) / 2;
	}

	return sqrt;
}

//Average Function
double averageFunction(double array [], double num){

	double average = 0.0;
	double total = 0.0;
	int x;
	for (x = 0; x < num; x++){
		total += array[x];
	}
	average = (double)(total / num);

	return average;
}

//Standard Deviation Function
double StandardDeviation(double userArray[], int num, double mean){

	double standardDev;
	int x = 0;
	double sumOfVals = 0.0;
	double temp;

	//Sum of all values (Xi - u)^2
	while (x < num){
		temp = ((userArray[x] - mean)*(userArray[x] - mean));
		sumOfVals += temp;
		x++;
	}

	//1/N-1
	double oneOverNMinusOne = (1.0 / (num -1));

	//Calculate Variance
	double variance;

	variance = oneOverNMinusOne * sumOfVals;
									
	standardDev = sqrtFunction(variance);
	return standardDev;
}

//Calculate Z Scores Function
void PrintZScores(double  userArray[],int num, double sDev, double mean){

	//CREATE NEW ARRAY 
	double newArray [num];
	int x = 0;
	double  zScore = 0;

	//Iterrates through the array
	while (x < num){
		zScore = ((userArray[x] - mean)/sDev);
		newArray[x] = zScore;
		x++;	
	}

	//Print Z scores
	printf("Zscores: \n [ ");
	int i = 0;
	//Iterrates through the array
	while (i < num){
		printf("%0.2lf " , newArray[i]);
		i++;
	}

	printf("]");
	printf("\n");
}

//Precal
void PrecalCalculator(){

	//Loops calculator
	while(1 == 1){
		int response = 0;

		//Options
		printf("Precal Functions:\n");
		printf("(1) sin\n");
		printf("(2) cos\n");
		printf("(3) tan\n");
		printf("(4) Degrees to Radians\n");
		printf("(5) Radians to Degrees\n");
		printf("(6) Exit Calculator\n");

		scanf("%d" , &response);

		//sin
		if (response == 1){

			double rad1 = 0.0;
			printf("Enter Radian Angle:\n");
			scanf("%lf" , &rad1);
			printf("sin of %0.3lf: %0.3lf\n" , rad1 , sin(rad1));

		}

		//cos
		if (response == 2){

			double rad2 = 0.0;
			printf("Enter Radian Angle:\n");
			scanf("%lf" , &rad2);
			printf("cos of %0.3lf: %0.3lf\n" , rad2 , cos(rad2));

		}

		//tan
		if (response == 3){

			double rad3 = 0.0;
			printf("Enter Radian Angle:\n");
			scanf("%lf" , &rad3);
			printf("tan of %0.3lf: %0.3lf\n" , rad3 , tan(rad3));

		}

		//Degrees to radians
		if (response == 4){
			double degrees;
			double radians;

			printf("Enter degrees:\n");
			scanf("%lf" , &degrees);

	 		radians = ((degrees*3.141592653589793)/180.0);
			printf("Radians: %0.3lf\n", radians);

		}

		//Radians to degrees
		if (response == 5){
			double degrees;
			double radians;
			
			printf("Enter radians:\n");
			scanf("%lf" , &radians);
		
			degrees = (radians * (180.0 / 3.141592653589793));
			printf("Degrees: %0.3lf\n" , degrees);

		}

		//Exit
		else if (response == 6){

			printf("Returning to Main Menu...\n");
			printf("\n");
			return;

		}

		printf("\n");
	}

}

//Logarithmic Calculator
void logCalc(){
	
	while (1 ==1){
		
		int response = 0;
		
		//Menu
		printf("Log Functions\n");
		printf("(1) Natural Log\n");
		printf("(2) Base 10 Log\n");
		printf("(3) Different Base Log\n");
		printf("(4) Exit\n");

		scanf("%d" , &response);


		//Natural Log
		if (response == 1){

			double natLog;
			double input;

			printf("Enter Value:\n");
			scanf("%lf" , &input);
			natLog = log(input);

			//Print answer
			printf("Natural log of %0.2lf: %0.4lf\n" , input, natLog);
 
		}

		//Base 10 Log
		if (response == 2){

			double logAnswer;
			double input;

			printf("Enter Value:\n");		
			scanf("%lf" , &input);
			logAnswer = log10(input);

			//Print answer
			printf("Log of %0.2lf: %0.4lf\n" , input, logAnswer);	

		}
		//Different Base Log
		if (response == 3){

			double base;
			double input;
			double log1;
			double log2;
			double logAnswer;

			printf("Enter the base:\n");
			scanf("%lf" , &base);
			printf("Enter Value:\n");
			scanf("%lf" , &input);

			//Calc Logs
			log1 = log(input);
			log2 = log(base);
			logAnswer = (log1 / log2);
			
			//Print answer
			printf("Log of %0.2lf with a base of %0.2lf: %0.4lf\n" , input, base, logAnswer);

		}
		//Exit
		if (response == 4){

			printf("Returning to Main Menu...\n");
			printf("\n");
			return;

		}
	}

}
