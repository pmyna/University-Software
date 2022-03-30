#pragma once

#include <string>
#include <vector>

#include "NucleicAcidCodes.h"

struct NCBIIdentifier
{
    std::string m_strDatabaseType;
    std::vector<std::string> m_databaseAccess;
};

class Sequence
{
    public:
        // member variables
        std::vector<NCBIIdentifier> m_databaseIdentifiers;
        std::string m_strName;
        std::vector<std::string> m_commentLines;
        std::vector<NucleicAcidCode *> m_sequence;

        // member functions
        void initialize(const std::string &i_strHeader, const std::string &i_strSequence);
        void print();
};