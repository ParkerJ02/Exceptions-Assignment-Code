/*
Parker Haynie
11/29/2022
Source File For Simple Division Calculator
*/

// This is the header file that contains all of the functions like "cout" and "cin".
#include <iostream>
// This is the header file that has the nexessary information to include the input and output related functions.
#include <stdio.h>
// This is the header file that has all of the information for all input and output related functions.
#include <stdlib.h>
// This is the header that tells the program to use a variable that has a type std::string. 
#include <string>
// This includes my own header file that I created for this project.
#include "divCalc.h";
// This tells the program to look at the standard namespace for everything that is not declared.
using namespace std;

// This initializes the string variable "name".
string name;
// This initializes the double variable "N1".
double N1;
// This initializes the double variable "N2".
double N2;

// This is a void function that displays the title of the program and tells the user what the program does.
void welcomeMessage()
{
	cout << "                  Simple Divison Program" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "\nHello and welcome to my simple division program. With this " << endl;
	cout << "program you can input a numerator and a denominator to recieve" << endl;
	cout << "a solved division equation of the two chosen numbers." << endl;
	cout << "(WARNING: You can not use zero or any negative numbers in this calculator)" << endl;
}

// This is a string function that asks the user for their name, allows the user to input their name, and then returns that name.
string getName()
{
	cout << "\nBut first, please enter your name:" << endl;
	// This line allows the user to input a string for the "name" variable.
	cin >> name;
	// This line returns the "name" variable after the user inputs a string for the "name" varaible.
	return name;
}

// This is a void function that handles all of the functions of the calculator.
// If the user entered an invalid name they will get an error.
// If the user entered an invalid numerator they will get an error.
// If the user entered an invalid denominator they will get an error.
void calcLogic()
{
	// This if/else statement uses the "isNumberS" function to determine if the name is a string or a number.
	// The "isNumberS" function is also my way of detecting an exception without using the try/catch block.
	// If the user entered a number then there will be an error message and the program will stop.
	// If the user entered a string then the program will continue with the rest of its operations.
	if (isNumberS(name))
	{
		// This happens when the user enters an invalid name.
		cout << "\nThis is an invalid name. Please restart and input a name." << endl;
		// This line completely stops the program once the error message has been displayed.
		exit(EXIT_FAILURE);
	}
	// This happens when the user enters a valid name.
	else
	{
		cout << "--------------------------------------------------------------" << endl;
		cout << "\nThank you, " << name << ", for using my program. Now you can enter" << endl;
		cout << "in two numbers in order to solve your division equation." << endl;
		// This sends a message to the user asking for the first number.
		cout << "\nEnter the first number of the equation (numerator):" << endl;
		// This allows the user to enter the first number (numerator).
		cin >> N1;
		cout << "--------------------------------------------------------------" << endl;
		// This sends a message to the user asking for the second number.
		cout << "\nEnter the second number of the equation (denominator):" << endl;
		// This allows the user to enter the second number (denominator).
		cin >> N2;
		cout << "--------------------------------------------------------------" << endl;
		// This is the first try/catch block to see if the first number is valid.
		try
		{
			// This if statement sees if the first number, "N1", is less than or equal to 0.
			// If the number is less than 0 then it will throw an error message to the catch.
			// If the number is greater than 0 then the program will continue its operations.
			if (N1 <= 0)
				throw "\nIncorrect input for first number. Please input a number that is more than 0.";
			// This happens when the user enters a valid first number.
			else
			{
				// This is the second try/catch block to see if the second number is valid.
				try
				{
					// This if statement sees if the second number, "N2", is less than or equal to 0.
					// If the number is less than 0 then it will throw an error message to the catch.
					// If the number is greater than 0 then the program will continue its operations.
					if (N2 <= 0)
						throw "\nIncorrect input for second number. Please input a number that is more than 0.";
					// This happens when the user enters a valid second number.
					else
					{
						// This line sets the value of the "solution" double variable to the value of the first number (numerator) divided by the second number (denominator).
						double solution = N1 / N2;
						cout << "\nSolution:\n\n";
						// This line displays the full equation as well as the solution to the equation.
						cout << N1 << " / " << N2 << " = " << solution << endl;
					}
				}
				// This is the catch that catches the error message of the second exception.
				// The second exception is if the user enters an invalid number for "N2" (denominator).
				catch (const char* Exception2)
				{
					// This line displays the error message of the second exception.
					cout << Exception2 << endl;
					// This line completely stops the program once the error message has been displayed.
					exit(EXIT_FAILURE);
				}
			}
		}
		// This is the catch that catches the error message of the first exception.
		// The first exception is if the user enters an invalid number for "N1" (numerator).
		catch (const char* Exception1)
		{
			// This line displays the error message of the first exception.
			cout << Exception1 << endl;
			// This line completely stops the program once the error message has been displayed.
			exit(EXIT_FAILURE);
		}
	}
}

// "isNumberS" is a bool function that will see if the input for a string is actually a digit.
// The "isNumberS" function is also my way of detecting an exception without using the try/catch block.
// If the input is a digit then the function will be set to false.
// If the input is a string then the function will be set to true.
bool isNumberS(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;
		return true;
}

// This is a void function displays the goodbye message to the user.
void goodbyeMessage()
{
	cout << "\nThank you for using my program, " << name << "! You can now restart the program to enter another equation." << endl;
}