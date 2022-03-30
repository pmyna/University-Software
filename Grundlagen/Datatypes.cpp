/*
 * Datatypes.cpp
 *
 *  Created on: 10.10.2016
 *      Author: Christian
 */

#include <iostream>

/**
 * Forward declarations of functions that get defined after use.
 */
void useArrays();
void useStructs();
void useCppDatatypes();

/**
 * and last but not least - declaring a new type name via typedef.
 */
typedef unsigned long MyInt;

/**
 *  Declare and use the predefined data-types known to C and C++.
 *  Invoke functions that show usage of arrays and structures.
 */
int main()
{
	// ----- integral types -----
	int i = -2;
	unsigned int ui = 3;
	long l = -1234567;
	unsigned long ul = 123;
	short s = 123;
	unsigned short s1 = 2;
	char x = 2;
	unsigned char y = 6;

	// ----- numbers -----
	float f1 = -3.2f;
	double d1 = 2.3e12;

	// ----- characters -----
	char ch = 'e';

	// ----- boolean value -----
	bool b1 = true;

	// ----- let the compiler think - a Standard C++ 11 feature -----
	// you need -std=c++11 (Select Project | Settings | Tool Settings | Cross G++ Compiler | Dialect | Language Standard to be ‘ISO C++11’)
	auto result = i + ui + l + ul + s + s1 + x + y;
	auto result2 = f1 * d1;
	auto b2 = b1 && ( ch + 1 == 'f');

	std::cout << "The integral value is: " << result << std::endl;
	std::cout << "The number value is: " << result2 << std::endl;
	std::cout << "The boolean value is: " << b2 << std::endl;

	useArrays();
	useStructs();

	// return success
	return 0;
}

/**
 * Show declaration and usage of arrays.
 */
void useArrays()
{
	// an array of values with identical size
	// we want initialize it with the first 10 natural numbers
	const int FIELD_SIZE = 10;
	int field[FIELD_SIZE];
	for ( int i = 0; i < FIELD_SIZE; i++ )
		field[i] = i + 1;

	std::cout << std::endl;
	std::cout << "The first 10 natural numbers are: " << std::endl;
	for ( int i = 0; i < FIELD_SIZE; i++ )
		std::cout << field[i];
	std::cout << std::endl;
}

/**
 * Show usage of a self-defined structure/record
 */
// here only for clarity of where this gets used.
// typically, includes are at the top of the file.
#include "ComplexNumber.h"
#include <cmath>

void useStructs()
{
	// now we use the data-type that we defined on our own
	ComplexNumber c;								// included from ComplexNumber.h
	c.a = 2.3;
	c.b = -3.5;
	auto lengthOfC = sqrt(c.a * c.a + c.b * c.b);	// included from cmath

	std::cout << std::endl;
	if ( c.b >= 0 )
		std::cout << "complex value: " << c.a << " + " << c.b << std::endl;
	else
		std::cout << "complex value: " << c.a << " + " << c.b << std::endl;

	std::cout << "its length is: " << lengthOfC << std::endl;
}

/**
 * Show usage of some very useful data-types implemented in the  C++ standard library.
 */
#include <string>
#include <vector>
#include <map>

void useCppDatatypes()
{
	// a character 'array' of flexible length
	std::string strName = "Christian Heiderer";

	// an arbitrary-length sequence of elements
	std::vector< double > numbersToSort;
	// a sequence of strings
	std::vector< std::string >comments;

	// and again you can use typedef to introduce a new type name.
	typedef std::vector< std::string > StringArray;
	StringArray arrNames;
}
