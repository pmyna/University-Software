#include<ostream>
using namespace std;
class Header{
    public:
        Header();

    private:
        string ncbi;
        int id_number;
        string name;
        string species;

    string getNCBI() const;
    int getID() const;
    string getName() const;
    string getSpecies() const;
};

class Sequence{
    public:
      Sequence();

    private:
        string seq;
    
    string getSeq() const;
};