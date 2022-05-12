#ifndef PERSON_H
#define PERSON_H

#pragma once
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Person{
    string Vorname;
    string Nachname;
    string Geburtstag;
public:
    Person(string, string);
    Person(string, string, string);
    ~Person();

    //getter
    string get_Vorname() const;
    string get_Nachname() const;
    string get_Geburtstag() const;

};

#endif
