#include <ostream>
#include <fstream>
#include <sstream>
#include "Reads.h"
using namespace std;

// Zeilen können mit getline nicht mehrfach oder stückweise eingelesen werden
// Zusammensetzen der Sequenz-Zeilen -> jede Zeile beginnt mit \n außer die erste Zeile
// Implementierung weiterer fasta-Strukuren um multi-fasta einlesen zu können ausstehend


int main()
{
  ifstream fLoad("AsianElefant_CytochromeB.fasta", ofstream::in);
  ofstream fSave("Reads.txt", ofstream::out);
  string strFile;
  bool loop = true;

  while(!fLoad.eof())
  {
    Header temp_head;
    Sequence temp_seq;

    getline(fLoad, strFile);

    if(strFile[0] == '>') //Einfachere Lösung substrings aus der getline zu bekommen?
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
    }

    while(loop) // Wie unterscheiden zwischen leerer Zeile \n und Zeile mit \nSEQUENZ?
    {
    getline(fLoad, strFile, '\r');
    if(strFile[0] == '\n')
        strFile = strFile.substr(1);
    if(!strFile.size())
      loop = false;
      break;
    string i_seq = strFile;
    temp_seq.addSequence(i_seq);
    }

    //Ins .txt File speichern
    fSave << temp_head << temp_seq; //loop funktiert nur für den ersten Absatz, nicht für den zweiten; Übergabe leerer Parameter
    }
    fLoad.close();
    fSave.close();
    return 0;
}