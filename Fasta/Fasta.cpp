/*
 * Fasta.cpp
 *
 *  Created on: 06.11.2016
 *      Author: Christian
 */

#include <iostream>
#include "stdio.h"
#include "string.h"
#include "FASTASequence.h"

// forward declarations
bool ReadFASTAFile( const char *i_strFileName, FASTASequences &o_rFASTASequences );
bool WriteFASTAFile( const char *i_strFileName, const FASTASequences &i_rFASTASequences );

int main(int argc, char **argv)
{
	FASTASequences vecFASTASequences;
	ReadFASTAFile( "Data\\AsianElefant_CytochromeB.fasta", vecFASTASequences );
	WriteFASTAFile( "Data\\Test.fasta", vecFASTASequences );

	return 0;	// ok;
}

/**
 * Read in a file in FASTA format. It can contain multiple sequences.
 */
bool ReadFASTAFile( const char *i_strFileName, FASTASequences &o_rFASTASequences )
{
	FILE *fdsFASTA = fopen(i_strFileName, "r");
	if ( fdsFASTA )
	{
		FASTASequence *pSequence = NULL;

		while ( !feof( fdsFASTA ) )
		{
			const int MAX_LINE_LENGTH = 83;		// 80 characters + crlf + '\0'
			char strLine[ MAX_LINE_LENGTH ];
			if ( fgets( strLine, MAX_LINE_LENGTH - 3, fdsFASTA ) )
			{
				// trim new-line
				auto len = strlen(strLine);
				if ( ( len > 0 ) && ( strLine [ len - 1] == '\n') )
					strLine[ len - 1 ] = '\0';

				// debug output
				std::cout << strLine << std::endl;

				// interpret line type by checking first character
				if ( strLine[ 0 ] == '>' )
				{
					// header for new sequence
					// maybe there was already a sequence before this one - add it to return parameter
					if ( pSequence != NULL )
						o_rFASTASequences.push_back(pSequence);

					pSequence = new FASTASequence();
					pSequence->SetId( strLine + 1 );
				}
				else if ( strLine[ 0 ] == ';' )
				{
					// comment line
					if (pSequence)
						pSequence->AppendCommentLine(strLine + 1);
					else
						;
				}
				else
				{
					// array of codes with '\n' at the end
					if (pSequence)
						pSequence->AppendCodes(strLine);
					else
						;
				}
			}
		}

		fclose( fdsFASTA );

		// the last sequence needs to be added, as well.
		if ( pSequence != NULL )
			o_rFASTASequences.push_back(pSequence);
	}

	return true;
}

/**
 * Read in a file in FASTA format. It can contain multiple sequences.
 */
bool WriteFASTAFile( const char *i_strFileName, const FASTASequences &i_rFASTASequences )
{
	FILE *fdsFASTA = fopen(i_strFileName, "w");		// create/truncate file and open for writing
	if ( !fdsFASTA )
		return false;

	for( auto iterFASTASequences = i_rFASTASequences.begin(); iterFASTASequences != i_rFASTASequences.end(); ++iterFASTASequences )
	{
		FASTASequence *pSequence = *iterFASTASequences;

		// write header
		fputc('>', fdsFASTA);
		fputs(pSequence->GetId().c_str(), fdsFASTA);
		fputc('\n', fdsFASTA);

		// write comments
		for ( auto iterComments = pSequence->GetComments().begin(); iterComments != pSequence->GetComments().end(); ++iterComments )
		{
			fputc(';', fdsFASTA);
			fputs((*iterComments).c_str(), fdsFASTA);
			fputc('\n', fdsFASTA);
		}

		// write codes - avoid lines longer than 80 characters
		int column = 0;
		for ( auto iterBases = pSequence->GetSequence().begin(); iterBases != pSequence->GetSequence().end(); ++iterBases )
		{
			if ( column >= 80 )
			{
				fputc('\n', fdsFASTA);
				column = 0;
			}

			fputc(( *iterBases )->GetCode(), fdsFASTA);
			column++;
		}
	}

	fclose( fdsFASTA);

	return true;
}
