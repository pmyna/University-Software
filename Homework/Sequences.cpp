#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

string Read::getHeader(){cout << read_header;}
string Read::getSequence(){cout << read_seq;}