#ifndef READS_H
#define READS_H
#include<iostream>
using namespace std;

// Deklaration & Definition
// Kompilierung funktionert mit diesem File! Yay!

class Header{
    public:
        Header(){}

    void setNCBI(const string &i_ncbi){ ncbi.append(i_ncbi); }
    void setName(const string &i_name) { name = i_name; }
    void setSpecies(const string &i_species){ species=i_species; }

    string getNCBI() const {return ncbi;}
    string getName() const {return name;}
    string getSpecies() const {return species;}

    private:
        string ncbi;
        string name;
        string species;
};

ostream &operator<<(ostream &o, Header &i_head){
    return o << "NCBI: " << i_head.getNCBI() << '\n' << "Name: " << i_head.getName() << '\n' << "Spezies: " << i_head.getSpecies() << '\n';
}

class Sequence{
    public:
      Sequence(){}

    void addSequence(const string &i_seq){seq.append(i_seq);}
    string getSequence() const {return seq;}

    private:
        string seq;
    
};

ostream &operator<<(ostream &o, Sequence &i_seq){
    return o << "Sequence: " << i_seq.getSequence() << '\n';
}

#endif