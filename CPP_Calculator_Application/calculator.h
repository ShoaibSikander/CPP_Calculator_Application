#include <string>

class Calc
{
    private:
        size_t index;
    public:
        Calc(int value);
        ~Calc();
        double process(std::string userInput, double prevValue);
        void print();
        std::string* storedExpressions;
        void incrementArrayIndex(size_t currentIndex);
        size_t getArrayIndex();
};