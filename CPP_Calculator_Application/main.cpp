#include <iostream>
#include "calculator.h"

using namespace std;

int main()
{
    int sentinal = 0;
    do
    {
        int numExp;
        cout << "Please enter the number of expressions you would like to store: ";
        cin >> numExp;
        if (numExp < 1)
        {
            cerr << "Error: Number of stored expressions must be positive ...!!!" << endl;
        }
        else
        {
            Calc calculator_obj = Calc(numExp);
//            Calc abc = Calc(calculator_obj);
            for (size_t count = 0; count < numExp; count++)
            {
                cout << endl << "******************************" << endl;
                cout << "Expression No. " << count+1 << " started ...!!!" << endl;
                int currentIndex = 0;
                double result = 0;
                double answer = 0;
                bool flag = true;
                while (flag)
                {
                    cout << "------------------------------" << endl;
                    string userString;
                    cout << "Enter 'STOP' to halt the input stream" << endl;
                    cout << "Accumulated Answer: " << answer << endl;
                    cout << "Please enter the number: ";
                    cin >> userString;
                    if (userString == "STOP")
                    {
                        currentIndex = calculator_obj.getArrayIndex();
                        calculator_obj.storedExpressions[currentIndex] = to_string(answer);
                        flag = false;
                        break;
                    }
                    result = calculator_obj.process(userString, answer);
                    cout << answer << userString << " = " << result << endl;
                    answer = result;
                }
                calculator_obj.incrementArrayIndex(currentIndex);
            }
            calculator_obj.print();
            std::cout << "Press 1 to continue with another calculator, any other value to quit" << std::endl;
            std::cin >> sentinal;
            cout << "------------------------------" << endl;
        }
    } while (sentinal == 1);
    return 0;
}
