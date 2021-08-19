/*
	Michael Stepp
	Functions Header File
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//ALL PROTOTYPES
//4 Function calc
void calculator();
double addFunction(double array[] , int num);
double subFunction(double num1, double num2);
double multFunction(double array[] , double num);
double divFunction(double num1, double num2);

//Data Set Functions
double averageFunction( double array[] , double num);
double StandardDeviation(double userArray[], int num, double mean);
void PrintZScores(double  userArray[],int num, double sDev, double mean);

//Precal Function
void PrecalCalculator();

//Logarithmic Calculator
void logCalc();

//Square Root Function
double sqrtFunction(double num);

#endif
