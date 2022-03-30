/*
 * FASTASequence.cpp
 *
 *  Created on: 06.11.2016
 *      Author: Christian
 */

#include "string.h"

#include "FASTASequence.h"

FASTASequence::FASTASequence()
{
}

FASTASequence::~FASTASequence()
{
}

void FASTASequence::SetId(const char *i_strId)
{
	m_strId = i_strId;
}

void FASTASequence::AppendCommentLine(const char *i_strComment)
{
	m_comments.push_back(i_strComment);
}

void FASTASequence::AppendCodes(const char *i_strCodeString)
{
	for ( size_t i = 0; i < strlen(i_strCodeString); i++)
	{
		// simplified version - create a code out of a code character without error checking
		NucleinBase *pBase = new NucleinBase(i_strCodeString[i]);
		m_sequence.push_back(pBase);
	}
}

const std::string &FASTASequence::GetId() const
{
	return m_strId;
}

const std::vector<std::string> FASTASequence::GetComments() const
{
	return m_comments;
}

const std::vector<NucleinBase *> FASTASequence::GetSequence() const
{
	return m_sequence;
}
