#include <assert.h>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <iterator>

#include "src/calculator.h"

int main()
{
    // Function calls to calculate
    // Write your all possible input scenarios here
    // Notice that calculator code written here works with integers

    std::map<char, std::function<float(float, float)>> operations;
    operations['+'] = [](float v1, float v2) { return v1+v2; };
    operations['-'] = [](float v1, float v2) { return v1-v2; };
    operations['*'] = [](float v1, float v2) { return v1*v2; };
    operations['/'] = [](float v1, float v2) { return v1/v2; };


    for (std::map<char, std::function<float(float, v)>>::iterator it = operations.begin() ; it != operations.end() ; ++it)
    {
        char op = it->first;
        std::function<float(float,float)> operation = it->second;

        for (int value1 = -123; value1 < 123; value1++)
        {
            for (int value2 = -123; value2 < 123; value2++)
            {
                float result;
                if (op == '/' && value2 == 0)
                {
                    result = 1;
                }
                else
                {
                    result = operation(value1, value2);
                }

                std::cout << std::to_string(value1) + op + std::to_string(value2) + " = " + std::to_string(result) << std::endl;
                assert(calculator(value1, op, value2) == result);
            }
        }
    }

    for (uint i = 0; i < 256; i++)
    {
        int value1 = -999;
        int value2 = 12345;
        char op = static_cast<char>(i);

        if (operations.find(op) == operations.end())
        {
            assert(calculator(value1, op, value2) == 1);
        }
        else
        {
            float result = operations[op](value1, value2);
            std::cout << std::to_string(value1) + op + std::to_string(value2) + " = " + std::to_string(result) << std::endl;
            assert(calculator(value1, op, value2) == result);
        }
    }

    return 0;
}
