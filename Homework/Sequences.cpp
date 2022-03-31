#include <ostream>
#include <fstream>
#include <sstream>
#include <vector>
//#include "Sequences.h"
using namespace std;

class Header{
    public:
        Header(const string &i_ncbi, int i_id, string &i_name, string &i_species):
        ncbi(i_ncbi), id_number(i_id), name(i_name), species(i_species){}

    private:
        string ncbi;
        int id_number;
        string name;
        string species;

    string getNCBI() const{return ncbi;}
    int getID() const{return id_number;}
    string getName() const{return name;}
    string getSpecies() const{return species;}
};

class Sequence{
    public:
      Sequence(const string &i_seq):
        seq(i_seq){}

    private:
        string seq;
    
    string getSeq() const {return seq;}
};

class Read{
    public:
        Read(const Header &head, const Sequence &seq):
            header(head), seq(seq){}

    private:
        Header header;
        Sequence seq;
};