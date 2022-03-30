/*
 * ControlStructures.cpp
 *
 *  Created on: 28.10.2016
 *      Author: Christian Heiderer
 */

/** This is a compilation unit. Run through a C or C++ compiler it will result in object code.
 * use a linker to combine multiple object files and libraries into one executable.
 */

/**
 * Read in data types, function declarations and names defined somewhere else.
 * The corresponding code, resulting from their definitions is available as libraries.
 * You will need link to them to get a complete executable.
 */
#include "stdio.h"

// forward declaration of a function - defines the function's signature
int calculate(int a, int b);

// forward declaration of a procedure - same as a function with no return value
void show(int a);

/**
 * Entry point into the program.
 * Invoked when executed by the operating system.
 * Parameters to the invocation get passed in via argc and argv.
 * The return value is typically interpreted as success (0) or failure (!= 0) by the caller.
 */
// a function definition
int main(int argc, char **argv)		// beginning with the function's signature
									// followed by the function's body
{	// begin of code block
	// a code block is a sequence of statements

	// a simple statement defining a new variable's name and type and initializes it with a value.
	int val1 = 3;

	// a more complex statement defining a new variable using an expression to calculate the initial value.
	int val2 = 2 * val1 + 1;

	// expressions consist of:
	//    names
	//    literals for primitive data types like: 1, 4.3e-2, 'a', "hello"
	//    operators - mathematical operators, logic and comparison operators, ...
	//    round brackets to override operator priorities
	//    function invocations

	// a statement that invokes a procedure - a function name followed by round brackets.
	// define arguments or parameters as expressions separated by commas.
	show(val2);

	// putting more things together into one statement
	show(calculate(val1, val2 - val1));

	// signal no error back to caller
	return 0;

}	// end of code block

/**
 * a local function.
 * declared at the beginning of this file so that it's name and signature is known when used inside 'main'.
 * defined here.
 * it doesn't implement something useful but shall show the alternatives to the strict sequential execution of statements.
 */
int calculate(int a, int b)
{
	// a conditional statement
	if ( a < 0 )		// the condition - an expression enclosed in round brackets that get evaluated against 0. 0 means 'false'
	{					// the code block that gets evaluated if above condition does not evaluate to 0.
						// the curly brackets are optional if only one statement is used
		return 0;		// a special control statement that jumps to the end of the function's code block. and defines the function's return value
	}

	// the switch - a conditional statement for special purposes
	switch (a)			// expression enclosed in round brackets that must evaluate to an integral value - int, long, char
	{
		case 1:			// execution starts here if expression evaluated to 1
			return a + b;

		case 2:
			return a * b;

		case 3:
			break;		// jumps to end of switch statement. statement after switch will be executed next

		default:		// execution starts here if expression didn't evaluate to anything matching above cases
			show(-1);
	}

	// we only come here for case 3 and default

	// how to execute a code block multiple times?
	int val = 0;
	// use for if you know in advance how often to repeat
	// use while if it is easier to think about the condition to do something than the number of times to do it
	// use do {}until if it is really tricky to formulate the while condition for the first execution.
	// prefer 'for' over 'while' over 'until'
	for (int i = 0; i < 10; i++ )
		val += i;		// the code block to repeat - again, curly brackets are optional if only one statement is needed.

	return val;
}

/**
 * A procedure is a function with no return value.
 */
void show(int a)
{
	printf("%d\n", a);
}
