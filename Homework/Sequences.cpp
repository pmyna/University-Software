// Idee: Header & zugehörige Sequence als ein Read zu speichern und gemeinsam an das .txt File übergeben und dort einlesen
// Scheitere am Auslesen von Reads, da ein string übergeben werden muss und Reads als Header/Sequence definiert sind
// Verwefen der Idee Reads
// Verwerfen der Sequences.h und Sequences.cpp, da nicht kompilierbar [ld: symbol(s) not found for architecture x86_64 clang: error: linker command failed with exit code 1 (use -v to see invocation)]git a

/* VERWORFEN

#include <iostream>
#include "Sequences.h"
using namespace std;


Header::Header(){}

void Header::setNCBI(const string &i_ncbi){ ncbi.append(i_ncbi); }
void Header::setName(const string &i_name){ name = i_name; }
void Header::setSpecies(const string &i_species){ species=i_species; }

string Header::getNCBI() const {return ncbi;}
string Header::getName() const {return name;}
string Header::getSpecies() const {return species;}
 

Sequence::Sequence(){}
void Sequence::addSequence(const string &i_seq){seq.append(i_seq);}


Read::Read(const Header &head, const Sequence &seq):
            read_header(head), read_seq(seq){}

string Read::getHeader(){return read_head);} //Wie Header als string returnen?
string Read::getSequence(){return read_seq;}
*/