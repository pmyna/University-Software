/*
 * Sequence.h
 *
 *  Created on: 10.10.2016
 *      Author: Christian
 */

#pragma once

/**
 * We define a new data-type that can hold complex values, which are not available as predefined C datatypes.
 * This data-type requires place for 2 double values.
 */
typedef struct
{
	double a;	// real part
	double b;	// imaginary part

}ComplexNumber;

// ComplexNumber becomes the name for the new data-type.
