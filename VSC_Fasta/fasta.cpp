#include "NucleicAcidCodes.h"
#include "Sequence.h"

int main()
{
    NucleicAcidCodes nucleidAcidCodes;
    nucleidAcidCodes.initializeNucleicAlphabeth();

    // gi|5524211|gb|AAD44166.1| cytochrome b [Elephas maximus maximus]
    // no comments, no sequence
    Sequence sequ1 = { { { "gi", { "5524211" }}, { "gb", { "AAD44166.1"} } }, "cytochrome b [Elephas maximus maximus]" };
    // append the sequence
    // LCLYTHIGRNIYYGSYLYSETWNTGIMLLLITMATAFMGYVLPWGQMSFWGATVITNLFSAIPYIGTNLV
    // EWIWGGFSVDKATLNRFFAFHFILPFTMVALAGVHLTFLHETGSNNPLGLTSDSDKIPFHPYYTIKDFLG
    // LLILILLLLLLALLSPDMLGDPDNHMPADPLNTPLHIKPEWYFLFAYAILRSVPNKLGGVLALFLSIVIL
    // GLMPFLHTSKHRSMMLRPLSQALFWTLTMDLLTLTWIGSQPVEYPYTIIGQMASILYFSIILAFLPIAGX
    // IENY
    sequ1.m_sequence.push_back(nucleidAcidCodes.getNucleicAcid('L'));
    sequ1.m_sequence.push_back(nucleidAcidCodes.getNucleicAcid('C'));
    sequ1.m_sequence.push_back(nucleidAcidCodes.getNucleicAcid('L'));
    // t.b.c.

    Sequence sequ2;
    sequ2.initialize
        (
            "MCHU - Calmodulin - Human, rabbit, bovine, rat, and chicken", 
            "MADQLTEEQIAEFKEAFSLFDKDGDGTITTKELGTVMRSLGQNPTEAELQDMINEVDADGNGTID \
             FPEFLTMMARKMKDTDSEEEIREAFRVFDKDGNGYISAAELRHVMTNLGEKLTDEEVDEMIREA \
            DIDGDGQVNYEEFVQMMTAK*"
        );

    sequ1.print();
    printf("\n");
    sequ2.print();

    return 0;
}