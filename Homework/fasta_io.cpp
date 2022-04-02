#include <ostream>
#include <fstream>
#include <sstream>
#include "Sequences.h"
using namespace std;


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
    
    Read read(temp_head, temp_seq);

    //In ein .txt File einlesen
    ofstream fSave("Reads.txt", ofstream::out);

    fSave << read;
    fSave.close();
    }

    return 0;
}