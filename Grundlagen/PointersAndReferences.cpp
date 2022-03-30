/*
 * PointersAndReferences.cpp
 *
 *  Created on: 11.10.2016
 *      Author: Christian
 */

#include <iostream>

int main()
{
	// --------------------------------- LEVEL ONE ------------------------------------
	// a local variable occupying space her inside the function (which is on the stack)
	// 'val' is the name of the memory that can store an integer value.
	int val = 23;
	std::cout << "Value = " << val << std::endl;

	// manipulate the value. 'val' can be interpreted as the address of the memory block that stores the value.
	val = -23;
	std::cout << "Value = " << val << std::endl;

	// instead of above name for the memory we can define a new additional name for the same memory - a reference
	int &rSameVal = val;
	rSameVal = 5;
	std::cout << "Value = " << val << std::endl;
	// references always point to a memory block of the appropriate size.
	// int &rInvalidVal;	// immediate initialization is required!

	// instead of above name we can define a new variable that holds the address of the memory to above value - a pointer
	int *pSameVal = &val;
	*pSameVal = -3;
	std::cout << "Value = " << val << std::endl;
	// in contrast to references, pointers can point to nothing
	pSameVal = NULL;
	// but beware of using such a pointer for anything else than comparing it with NULL. A run-time error will result.
	// *pSameVal = 2;  - the classical crash!

	// --------------------------------- LEVEL TWO ------------------------------------
	// the most useful usage of pointers - strings
	const char *strMyFirstName = "Christian";
	const char *strMySecondName = "Heiderer";
	const char *strMyFamilyName = strMySecondName;	// uses SAME memory!
	std::cout << "My name is " << strMyFirstName << " " << strMyFamilyName << std::endl;

	// the second most useful usage of pointers - arrays of sizes that are not known at compile-time
	std::cout << "Bitte geben Sie eine Zahl zwischen 1 und 100 ein: ";
	int count;
	std::cin >> count;
	if ( ( count >= 1 ) && ( count <= 100 ) )
	{
		// we need memory for all these values, we allocate it from the heap.
		int *intArray = new int[ count ];
		// int *intArray2 = new int(count);
		for ( int i = 0; i < count; i++ )
			intArray[ i ] = i + 1;

		std::cout << "The first " << count << " natural numbers are: ";
		for ( int i = 0; i < count; i++ )
			std::cout << intArray[ i ] << " ";
		std::cout << std::endl;

		// when we no longer need the memory we can free it.
		delete [] intArray;
		// never attempt to access this memory after deleting it ;-)
	}
	else
		std::cout << "Sie Scherzkekse, Sie sollten eine Zahl zwischen 1 und 100 eingeben." << std::endl;

	// --------------------------------- LEVEL THREE ------------------------------------
	// You may want to pass the address to some memory and be sure that the memory itself will not be changed
	// use 'const'


	// --------------------------------- LEVEL FOUR ------------------------------------
	// the funny things - avoid if possible :-)
	// you can use a point to a pointer to store the address of the address to something.

	return 0;
}


