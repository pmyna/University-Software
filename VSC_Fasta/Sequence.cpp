#include "Sequence.h"

#include <stdio.h>

void Sequence::print()
{
    // the header
    printf(">");
    for (auto &identifier : m_databaseIdentifiers)
    {
        printf("%s", identifier.m_strDatabaseType.c_str());
        for (auto &dbAccess : identifier.m_databaseAccess)
            printf("|%s", dbAccess.c_str());

        printf("|");
    }
    printf("%s\n", m_strName.c_str());

    // comments
    for (auto &strCommentLine : m_commentLines)
        printf(";%s\n", strCommentLine.c_str());

    // the sequence
    for ( size_t i = 0; i < m_sequence.size(); i++)
    {
        // maximum 80 characters per line
        if ( ((i % 80 ) == 0 ) && ( i != 0))
            printf("\n");

        if (m_sequence[i] != nullptr)
            m_sequence[i]->print();
        else
            printf("?");
    }

    printf("\n");
}

void Sequence::initialize(const std::string &i_strHeader, const std::string &i_strSequence)
{
    // well, how should we convert input to the value in the member?
}
