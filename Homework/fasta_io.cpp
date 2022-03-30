#include <ostream>
#include  <fstream>
#include <sstream>
using namespace std;

class Person{
    public:
        Person(const string &i_Name, int i_Age): m_Name(i_Name), m_Age(i_Age){

        }
    string getName() const {return m_Name;}
    int getAge() const {return m_Age;}

    private:
        int m_Age;
        string m_Name;
};

ofstream &operator<<(ofstream &i_out, Person &i_person){
    i_out << i_person.getName() << ';' << i_person.getAge() << '\n';
    return i_out;
}

int main()
{
    Person Michael("Michael Mustermann", 55);
    Person Lisa("Lisa Nordpork", 34);

    //In das File schreiben
    ofstream fSave("data.txt", ofstream::out);
    fSave << Michael << Lisa;
    fSave.close();

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

    return 0;
}