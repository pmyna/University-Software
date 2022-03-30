/*
 * NucleinBase.cpp
 *
 *  Created on: 06.11.2016
 *      Author: Christian
 */

#include "NucleinBase.h"

NucleinBase::NucleinBase(char i_strCodeCharacter)
{
	m_chCode = i_strCodeCharacter;
}

NucleinBase::~NucleinBase()
{
}

char NucleinBase::GetCode() const
{
	return m_chCode;
}
