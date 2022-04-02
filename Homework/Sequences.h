#ifndef SEQUENCES_H
#define SEQUENCES_H
#include<iostream>
using namespace std;

class Header{
    public:
        Header();

    void setNCBI(const string &i_ncbi);
    void setName(const string &i_name);
    void setSpecies(const string &i_species);

    string getNCBI() const;
    string getName() const;
    string getSpecies() const;

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
      Sequence();

    void addSequence(const string &i_seq);

    private:
        string seq;
    
};

ostream &operator<<(ostream &o, Sequence &i_seq){
    return o << "Sequence: " << i_seq << '\n';
}

class Read{
    public:
        Read(const Header &head, const Sequence &seq);
        
    
    string getHeader();
    string getSequence();
        
    private:
        Header read_header;
        Sequence read_seq;
};

ostream &operator<<(ostream &o, Read &i_read){
    return o << i_read.getHeader() << '\n' << i_read.getSequence() << '\n';
}

#endif
