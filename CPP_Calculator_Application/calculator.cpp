#include <iostream>
#include "calculator.h"
#include <cmath>

using namespace std;

Calc::Calc(int value)
{
	storedExpressions = new string[value];
	index = 0;
}

Calc::~Calc()
{
	delete[] storedExpressions;
	storedExpressions = nullptr;
	index = 0;
}

double Calc::process(string userInput, double prevValue)
{
	string cleansedString = "";
	for (size_t i = 0; i < userInput.size(); ++i)
	{
		if (userInput[i] == '0' || userInput[i] == '1' || userInput[i] == '2' || userInput[i] == '3' || userInput[i] == '4' || userInput[i] == '5' || userInput[i] == '6' || userInput[i] == '7' || userInput[i] == '8' || userInput[i] == '9' || userInput[i] == '+' || userInput[i] == '-' || userInput[i] == '*' || userInput[i] == '/' || userInput[i] == '^' || userInput[i] == '.')
		{
			cleansedString += userInput[i];
		}
		else
		{
		}
	}
	int stringLength = cleansedString.length() - 1;
	string cutString = cleansedString.substr(1, stringLength);
	double inputValue = stod(cutString);
	if (cleansedString[0] == '^')
	{
		return pow(prevValue, inputValue);
	}
	else if (cleansedString[0] == '+')
	{
		return prevValue + inputValue;
	}
	else if (cleansedString[0] == '-')
	{
		return prevValue - inputValue;
	}
	else if (cleansedString[0] == '*')
	{
		return prevValue * inputValue;
	}
	else if (cleansedString[0] == '/')
	{
		if (inputValue == 0)
		{
			exit(0);
		}
		else
		{
			return prevValue / inputValue;
		}
	}
	else
	{
		cout << "Error: Must start with operator" << endl;
	}

}

void Calc::print()
{
	cout << endl << "******************************" << endl;
	cout << "You have " << index << " expressions stored ...!!!" << endl;
	for (size_t i = 0; i < index; ++i)
	{
		cout << "Expression " << i + 1 << ": " << storedExpressions[i] << endl;
	}
	cout << endl << "******************************" << endl;
}

void Calc::incrementArrayIndex(size_t currentIndex)
{
	index = currentIndex +1;
}

size_t Calc::getArrayIndex()
{
	return index;
}
