/*
 * NucleinBase.h
 *
 *  Created on: 06.11.2016
 *      Author: Christian
 */

#pragma once

/**
 * Stores the code for one nuclein base.
 */
class NucleinBase
{
	public:
		NucleinBase(char i_strCodeCharacter);
		virtual ~NucleinBase();

		char GetCode() const;

	private:
		char m_chCode;
};
