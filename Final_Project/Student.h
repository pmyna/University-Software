#ifndef STUDENT_H
#define STUDENT_H
#pragma once
#include "Person.h"
#include "Vorlesung.h"
#include <algorithm>

class Student : public Person{
    int Matrikelnummer;
    vector<Vorlesung> belegt_VO;
    int Semester;
    bool aktiv;
public:
    static int ID;
    static int count;

    // Constructor
    Student(string vor, string nach, int sem=1, bool aktiv=true) : Person(move(vor), move(nach)), Semester{sem}, aktiv{aktiv}{Matrikelnummer = ID++; count++;}
    Student(string vor, string nach, string geb, int sem=1, bool aktiv=true) : Person(move(vor), move(nach), move(geb)), Semester{sem}, aktiv{aktiv}{Matrikelnummer = ID++; count++;}

    // Destructor
    virtual ~Student(){count--;}

    // Getter
    int get_matrikel() const {return Matrikelnummer;}
    int get_semester() const {return Semester;}
    string get_status() const {
        if (aktiv){return "AKTIV";}
        return "INAKTIV";
    }

    // Setter
    void set_semester(const int& sem){Semester=sem;}

    bool is_in(Vorlesung &VO){
    for (auto i : belegt_VO){
        if (i == VO){return true;}}
        return false;}

    // Anmeldung zu einer VO
    void anmeldung(Vorlesung &VO){
        if(!Student::aktiv){
            cout << "Anmeldung nicht möglich > Student inaktiv!" << endl;}
        if(is_in(VO)){
            cout << "Anmeldung nicht möglich > Student ist bereits angemeldet!" << endl;}
        if(VO.is_full()){
            cout << "Anmeldung nicht möglich > Alle Plätze belegt!" << endl;}
        if(Student::aktiv && !is_in(VO) && !VO.is_full()){
            belegt_VO.push_back(VO);
            VO.new_entry();
            cout << Matrikelnummer << " wurde zu " << VO << " angemeldet" << endl;}
    }

    //Abmeldung von einer VO
    void abmeldung(Vorlesung &VO){
        if(!Student::aktiv){
            cout << "Abmeldung nicht möglich > Student inaktiv!" << endl;}
        if(!is_in(VO)){
            cout << "Abmeldung nicht möglich > Student nicht angemeldet!" << endl;}
        if(Student::aktiv && is_in(VO)){
            remove(belegt_VO.begin(), belegt_VO.end(), VO);
            VO.delete_entry();
            cout << Matrikelnummer << " wurde von " << VO << " abgemeldet" << endl;}
    }

    // Print Function
    ostream& print(ostream& out) const{
        out << "Name: " << Person::get_Vorname() << ' ' << Person::get_Nachname() << endl;
        out << "Matrikelnummer: " << get_matrikel() << endl;
        out << "Status: " << get_status() << endl;
        out << "Semester: " << get_semester() << endl;
        out << "Belegte Vorlesungen:" << endl;
        for (Vorlesung i: belegt_VO){out << '[' << i << ']' << endl;}
        return out;
    }
};

inline ostream& operator<<(ostream& o, const Student& st){
    return st.print(o);
}

#endif
