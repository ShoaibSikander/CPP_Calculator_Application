#include <iostream>
#include "calculator.h"

using namespace std;

int main()
{
    int sentinal = 0;                                                           // Initialize the variable for the do-while loop
    do                                                                          // Start the Do-While loop
    {                                                               
        int numExp;                                                             // Variable to store the number of expressions
        cout << "Please enter the number of expressions you would like to store: ";            // Print on the Console
        cin >> numExp;                                                          // Take user input for the number of expressions
        if (numExp < 1)                                                         // If user enters a value less than 1, then its not realistic
        {
            cerr << "Error: Number of stored expressions must be positive ...!!!" << endl;     // Print on the Console
        }
        else                                                                    // If user enters a value equal to 1 or greater
        {
            Calc calculator_obj = Calc(numExp);                                 // Initialize the Class object and call its constructor
//            Calc abc = Calc(calculator_obj);
            for (size_t count = 0; count < numExp; count++)                     // Run the loop for the user defined number of expressions
            {
                cout << endl << "******************************" << endl;       // Print on the Console
                cout << "Expression No. " << count+1 << " started ...!!!" << endl;  // Print on the Console
                int currentIndex = 0;                                           // Declare and initialize the variable to store the current index of array where result will be stored
                double result = 0;                                              // Declare and initialize the variable to store the mathematical result
                double answer = 0;                                              // Declare and initialize the variable to store the accumulated answer
                bool flag = true;                                               // Define a boolean variable and initialize it with "true"                                
                while (flag)                                                    // Keep running the While-Loop untill the flag is true
                {
                    cout << "------------------------------" << endl;           // Print on the Console
                    string userString;                                          // Define string variable to get user input number for calculation
                    cout << "Enter 'STOP' to halt the input stream" << endl;    // Print on the Console
                    cout << "Accumulated Answer: " << answer << endl;           // Print on the Console
                    cout << "Please enter the number: ";                        // Print on the Console
                    cin >> userString;                                          // Get user input for calculation
                    if (userString == "STOP")                                   // If user enters "STOP", then this if-condition will be executed
                    {
                        currentIndex = calculator_obj.getArrayIndex();          // Get the current index number where accumulated answer will be stored
                        calculator_obj.storedExpressions[currentIndex] = to_string(answer); // Convert the accumulated answer to string and store at the first available index of array
                        flag = false;                                           // Set the flag to False
                        break;                                                  // Break the loop
                    }
                    result = calculator_obj.process(userString, answer);        // Perform mathematical calculations and get the result
                    cout << answer << userString << " = " << result << endl;    // Display the calculated result on the Console
                    answer = result;                                            // Overwrite the value of accumuated answer
                }
                calculator_obj.incrementArrayIndex(currentIndex);               // Increase index to store the next calculated answer 
            }
            calculator_obj.print();                                             // Call the "print" function of the Class and display accumulated answers for all expressions
            std::cout << "Press 1 to continue with another calculator, any other value to quit" << std::endl;   // Print on the Console 
            std::cin >> sentinal;                                               // Take the user input and check if he/she wants to continue or not
            cout << "------------------------------" << endl;                   // Print on the Console
        }
    } while (sentinal == 1);                                                    // Check the condition for the While Loop
    return 0;                                                                   // Main function finished without any error
}