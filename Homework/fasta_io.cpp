#include <ostream>
#include <fstream>
#include <sstream>
#include "Reads.h"
using namespace std;

// Implementierung weiterer fasta-Strukuren um multi-fasta einlesen zu können ausstehend

int main()
{
  ifstream fLoad("AsianElefant_CytochromeB.fasta", ofstream::in);
  ofstream fSave("Reads.txt", ofstream::out);
  string strFile;

  while(!fLoad.eof())
  {
    Header temp_head;
    Sequence temp_seq;

    getline(fLoad, strFile, '\r');

    if(strFile[0] == '>' || strFile[1] == '>') //Einfachere Lösung substrings aus der getline zu bekommen?
    {
      size_t pos1 = strFile.find(' ');
      string i_ncbi = strFile.substr(1, pos1-1);
      temp_head.setNCBI(i_ncbi);

      size_t pos2 = strFile.find('[');
      string i_name = strFile.substr(pos1+1, pos2-(pos1+2));
      temp_head.setName(i_name);

      size_t pos3 = strFile.find(']');
      string i_species = strFile.substr(pos2+1, pos3-(pos2+1));
      temp_head.setSpecies(i_species);

      fSave << temp_head << '\n';
    }

    if(strFile[0] == '\n' && strFile[1] != '>')
    {
      string i_seq;
      do{
      strFile = strFile.substr(1);
      i_seq += strFile;
      getline(fLoad, strFile, '\r');
      } while(strFile.size() > 1 && strFile[0] != '>');

      temp_seq.addSequence(i_seq);
      fSave << temp_seq << '\n'; 
    }
    }
    fLoad.close();
    fSave.close();
    return 0;
}