#pragma once

#include <string>
#include <vector>

/**
 * @brief  a single acid code in a nucleic sequence. 
 * See NucleicAcidCodes for the set of available acid codes.
 * 
 */
class NucleicAcidCode
{
    public:
        // member variables
        char m_code;                // e.g. A
        std::string m_strMnemonic;  // e.g. Adenine
        std::string m_strMeaning;   // e.g. A

        // member functions        
        void print();
};

/**
 * @brief The set of all defined nucleic acids codes 
 * 
 */
class NucleicAcidCodes
{
    public:
        // member variables
        std::vector<NucleicAcidCode *> m_allElements;

        // member functions
        void initializeNucleicAlphabeth();
        NucleicAcidCode *getNucleicAcid(char i_codeFromSequence);
};
