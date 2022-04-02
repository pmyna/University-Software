#include <iostream>
#include "Sequences.h"
using namespace std;

// Idee: Header & zugehörige Sequence als ein Read zu speichern und gemeinsam an das .txt File übergeben und dort einlesen
// Scheitere am Auslesen der Klassen von Read, da ein string übergeben werden muss
// Idee 2: Reads als Liste von Vektoren mit Header/Sequences -> gleiches Problem 
// Sequences.h verworfen, da kompilen nicht möglich

Header::Header(){}

void Header::setNCBI(const string &i_ncbi){ ncbi.append(i_ncbi); }
void Header::setName(const string &i_name){ name = i_name; }
void Header::setSpecies(const string &i_species){ species=i_species; }

string Header::getNCBI() const {return ncbi;}
string Header::getName() const {return name;}
string Header::getSpecies() const {return species;}
 

Sequence::Sequence(){}
void Sequence::addSequence(const string &i_seq){seq.append(i_seq);}


/*Read::Read(const Header &head, const Sequence &seq):
            read_header(head), read_seq(seq){}

string Read::getHeader(){return read_head);} //Wie Header als string returnen?
string Read::getSequence(){return read_seq;}*/
