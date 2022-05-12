#include "Student.h"
#include "Professor.h"
#include "Studium.h"

int main() {
    Vorlesung EP(100, Vorlesung::Semester::SS, 30, "Einführung in Programmieren", Vorlesung::Type::UE, 10);
    Student moritz("Moritz", "Hadinger");
    //moritz.set_semester(7);
    //moritz.anmeldung(EP);
    Student lisa("Lisa", "Neuer", 5);
    //lisa.anmeldung(EP);
    //moritz.abmeldung(EP);
    Professor ernst("Ernst", "Mayer", 100);
    //cout << ernst << endl;
    Professor heinz("Heinz Oliver", "Bach", "18.03.1967", 100);
    //heinz.add_VO(EP);
    //cout << heinz << endl;
    cout << "Derzeit sind " << Student::count << " Studenten inskribiert und " << Professor::count
         << " Professoren angestellt." << endl;

        Studium::get_stdStudium(100)->print();

    return 0;
}