/*
Parker Haynie
11/29/2022
Main Function File For Simple Division Calculator
*/

// This includes my own header file that I created for this project.
#include "divCalc.h";

// This is the "main()" function. This is the first function that the program looks at.
int main()
{
	// This displays whatever is in the "welcomeMessage()" function to the terminal.
	welcomeMessage();
	// This displays whatever is in the "getName()" function to the terminal.
	getName();
	// This displays whatever is in the "calcLogic() function to the terminal.
	calcLogic();
	// This displays whatever is in the "goodbyeMessage()" function to the terminal.
	goodbyeMessage();
	//This line returns the value "0" after main has already ran through everything.
	return 0;
}