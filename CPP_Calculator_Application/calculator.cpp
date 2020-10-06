#include <iostream>
#include "calculator.h"
#include <cmath>

using namespace std;

Calc::Calc(int value)															// Constructor
{
	storedExpressions = new string[value];										// Make an array of user defined size and assign to pointer
	index = 0;																	// Initialize the array index number with a zero value
}

Calc::~Calc()																	// Destructor
{
	delete[] storedExpressions;													// Delete the array which is made in the Constructor
	storedExpressions = nullptr;												// Set it equal to the Null Pointer
	index = 0;																	// Make the array index number equal to Zero
}

double Calc::process(string userInput, double prevValue)						// Function for mathematical calculation
{
	string cleansedString = "";													// Define and initialize an empty string
	for (size_t i = 0; i < userInput.size(); ++i)								// Run the for-loop equal to string's size
	{
		if (userInput[i] == '0' || userInput[i] == '1' || userInput[i] == '2' || userInput[i] == '3' || userInput[i] == '4' || userInput[i] == '5' || userInput[i] == '6' || userInput[i] == '7' || userInput[i] == '8' || userInput[i] == '9' || userInput[i] == '+' || userInput[i] == '-' || userInput[i] == '*' || userInput[i] == '/' || userInput[i] == '^' || userInput[i] == '.')  // if its a number or correct operation sign 
		{
			cleansedString += userInput[i];										// Connect the correct values in a string
		}
		else																	// Otherwise if there is some incorrect value input by user
		{																		// Ignore that value	
		}
	}
	int stringLength = cleansedString.length() - 1;								// Find the length of newly constructed array and subtract 1
	string cutString = cleansedString.substr(1, stringLength);					// Ignore the symbol at first location of array
	double inputValue = stod(cutString);										// Convert the string array to numeric value
	if (cleansedString[0] == '^')												// If the first value of the input string is ^
	{
		return pow(prevValue, inputValue);										// result = (AccumulatedAnswer)^(InputValue)
	}
	else if (cleansedString[0] == '+')											// If the first value of the input string is +
	{
		return prevValue + inputValue;											// result = (AccumulatedAnswer)+(InputValue)
	}
	else if (cleansedString[0] == '-')											// If the first value of the input string is -
	{
		return prevValue - inputValue;											// result = (AccumulatedAnswer)-(InputValue)
	}
	else if (cleansedString[0] == '*')											// If the first value of the input string is *
	{
		return prevValue * inputValue;											// result = (AccumulatedAnswer)*(InputValue)
	}
	else if (cleansedString[0] == '/')											// If the first value of the input string is /
	{
		if (inputValue == 0)													// If the input string is zero
		{
			exit(0);															// Exit the code													
		}
		else																	// If the input string is non-zero
		{
			return prevValue / inputValue;										// result = (AccumulatedAnswer)/(InputValue)
		}
	}
	else																		// Otherwise
	{
		cout << "Error: Must start with operator" << endl;						// Print on the Console
	}

}

void Calc::print()																// Print function
{
	cout << endl << "******************************" << endl;					// Print on the Console
	cout << "You have " << index << " expressions stored ...!!!" << endl;		// Print on the Console
	for (size_t i = 0; i < index; ++i)											// Start for-loop
	{
		cout << "Expression " << i + 1 << ": " << storedExpressions[i] << endl;	// Print on the Console
	}
	cout << endl << "******************************" << endl;					// Print on the Console
}

void Calc::incrementArrayIndex(size_t currentIndex)									// Function to move the index to next position in array
{
	index = currentIndex +1;													// New_Index = Old_Index + 1
}

size_t Calc::getArrayIndex()													// Function to return the current index value of array
{
	return index;																// Return the current value of array index
}