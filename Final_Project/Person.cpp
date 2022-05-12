#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string vor, string nach): Vorname(vor), Nachname(nach), Geburtstag("01.01.1900"){
    if (vor.empty() || nach.empty())
        throw runtime_error("Name darf nicht leer sein!");
}

Person::Person(string vor, string nach, string geb): Vorname(vor), Nachname(nach), Geburtstag(geb){
        if (vor.empty() || nach.empty())
            throw runtime_error("Name darf nicht leer sein!");
}

Person::~Person(){}

string Person::get_Vorname() const{return Vorname;}
string Person::get_Nachname() const {return Nachname;}
string Person::get_Geburtstag() const {return Geburtstag;}