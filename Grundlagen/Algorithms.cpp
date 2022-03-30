
#include <iostream>
#include <exception>

// a function declaration - ignore for the moment
float divide(float a, float b);

int main()
{
    // ----------------------------------------------------
    // algorithm 1 - divide 2 numbers
    printf("An algorithm is a series of steps (expressions)\n.");
    // the data 
    float a,b;
    float result;

    // input
    a = 2.6;
    b = 1.2;

    // the algorithm
    result = a / b;

    // output result - C++ way
    std::cout << a << " / " << b << " = " << result << std::endl;
    // output result C-way
    printf("%f / %f = %f\n", a, b, result);
    printf("\n");

    // --------------------------------------------------------
    // improved algorithm - error handling with conditional statement
    printf("Conditions: One step after the other is not always working.\n");
    if (b != 0)
    {
        result = a / b;
        printf("%f / %f = %f\n", a, b, result);
    }
    else
        printf("ERROR: Division by zero is not allowed.\n");
    printf("\n");

    // --------------------------------------------------------
    // improved algorithm - error handling with exception
    printf("Exceptions: there are times when the normal flow of the algorithm cannot be maintained any more.\n");
    if (b == 0)
        throw std::logic_error("Division by zero is not allowed");

    result = a / b;
    printf("%f / %f = %f\n", a, b, result);
    printf("\n");

    // --------------------------------------------------------
    // the algorithm is indepedent from its input
    // we can use the same code for multiple input
    printf("We can exceute the same algorithm multiple times.\n Makes only sense, if some variables changed.\n");
    float divident = 23.45;
    for (float divisor : {3.0, 2.3, 1.0})
    {
        if (divisor != 0)
        {
            result = a / divisor;
            printf("%f / %f = %f\n", divident, divisor, result);
        }
        else
            printf("ERROR: Division by zero is not allowed.\n");
    }
    printf("\n");

    // --------------------------------------------------------
    // for better re-use of the algorithm we can parameterize it.
    // a function is an algorithm that can be invoked with differemt parameters.
    printf("Functions allow to re-use code for different input.\n");
    for (float divisor : {3.3, 2.2, 1.1})
        printf("%f / %f = %f\n", divident, divisor, divide(divident, divisor));
    printf("\n");
}

// implementation of a function
float divide(float a, float b)
{
    if (b == 0)
        throw std::logic_error("Division by zero is not allowed.");

    float result = a / b;

    return result;
}
