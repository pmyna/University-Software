/*
 * FASTASequence.h
 *
 *  Created on: 06.11.2016
 *      Author: Christian
 */

#pragma once

#include <string>
#include <vector>

#include "NucleinBase.h"

/**
 * A sequence as read in from a file in FASTA format.
 * A FASTA file can include multiple sequences.
 */
class FASTASequence
{
	public:
		FASTASequence();
		virtual ~FASTASequence();

		void SetId(const char *i_strId);
		void AppendCommentLine(const char *i_strComment);
		void AppendCodes(const char *i_strCodeString);

		const std::string &GetId() const;
		const std::vector<std::string> GetComments() const;
		const std::vector<NucleinBase *> GetSequence() const;

	private:
		std::string m_strId;
		std::vector<std::string> m_comments;
		std::vector<NucleinBase *> m_sequence;
};

typedef std::vector<FASTASequence *> FASTASequences;
