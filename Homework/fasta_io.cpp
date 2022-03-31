#include <ostream>
#include <fstream>
#include <sstream>
#include "Sequences.h"
using namespace std;


int main()
{
    Person Michael("Michael Mustermann", 55);
    Person Lisa("Lisa Nordpork", 34);

    //Aus dem File auslesen
    ifstream fLoad("data.txt", ofstream::in);

    while(!fLoad.eof())
    {
    string strField;

    getline(fLoad, strField, ';');
        if(!strField.empty())
        {
        string name = strField;

        getline(fLoad, strField, '\n');
        int age;
        istringstream(strField) >> age;
        }
        fLoad.close();
    }

      //In das File schreiben
    ofstream fSave("Reads.txt", ofstream::out);
    fSave << "NONE"; //Reads
    fSave.close();

    return 0;
}