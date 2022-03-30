#include "NucleicAcidCodes.h"

#include <cctype>

NucleicAcidCode a = { 'A', "A", "Adenine" };
NucleicAcidCode c = { 'C', "A", "Cytocine" };
NucleicAcidCode g = { 'G', "A", "Guanine" };
NucleicAcidCode t = { 'T', "A", "Thymine" };
NucleicAcidCode u = { 'U', "A", "Uracil" };
// t.b.c.

void NucleicAcidCode::print()
{
    printf("%c", m_code);
}

void NucleicAcidCodes::initializeNucleicAlphabeth()
{
    m_allElements.push_back(&a);
    m_allElements.push_back(&c);
    m_allElements.push_back(&g);
    m_allElements.push_back(&t);
    m_allElements.push_back(&u);
    // ... and more
}

/**
 * @brief look up the code in the list of pre-defined codes.
 * 
 * @param i_codeFromSequencea a case independent code as found in a nucleic sequence
 * @return NucleicAcidCode* the nucleic acid object matching the code or nullptr if not found
 */
NucleicAcidCode *NucleicAcidCodes::getNucleicAcid(char i_codeFromSequence)
{
    auto upperCode = toupper(i_codeFromSequence);

    for (auto *acid : m_allElements)
        if (acid->m_code == upperCode)
            return acid;
        
    return nullptr;
}
