#include <ostream>
#include <fstream>
#include <sstream>
#include "Sequences.h"
using namespace std;

/* 
-) Compilieren nicht möglich: 
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation) 
-) Programm kann nicht getestet werden; 
-) Debugging startet ebenfalls nicht;
*/

int main()
{
    //Aus dem Fasta auslesen
    ifstream fLoad("AsianElefant_CytochromeB.fasta", ofstream::in);

    while(!fLoad.eof())
    {
      Header temp_head;
      Sequence temp_seq;
      string strField;
      getline(fLoad, strField);

        if(strField[0] == '>')
        {
          while(!strField[0])
            getline(fLoad, strField, '|');
            string i_ncbi = strField;
            temp_head.setNCBI(i_ncbi);
          
          getline(fLoad, strField, '[');
          string i_name = strField;
          temp_head.setName(i_name);

          getline(fLoad, strField, ']');
          string i_species = strField;
          temp_head.setSpecies(i_species);
        }

        while(!strField.empty())
          {
            temp_seq.addSequence(strField);
          }
        fLoad.close();

    //In ein .txt File einlesen
    ofstream fSave("Reads.txt", ofstream::out);

    fSave << temp_head << temp_seq;
    fSave.close();
    }

    return 0;
}