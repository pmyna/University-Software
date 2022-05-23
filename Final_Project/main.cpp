#include "Student.h"
#include "Professor.h"
#include "Studium.h"

int main() {
    // Initiation von Vorlesungen
    vector<Vorlesung> all_VOs;
    all_VOs.emplace_back(100, Vorlesung::Semester::WS, 10, "Einführung in Programmieren", Vorlesung::Type::VO, 250);
    all_VOs.emplace_back(100, Vorlesung::Semester::SS, 15, "Programmieren Anwendung", Vorlesung::Type::UE, 100);
    all_VOs.emplace_back(100, Vorlesung::Semester::SS, 20, "Grundlagen Linux & Shellscript", Vorlesung::Type::ILV, 25);
    all_VOs.emplace_back(100, Vorlesung::Semester::WS, 30, "IT Security", Vorlesung::Type::VO, 200);
    all_VOs.emplace_back(200, Vorlesung::Semester::WS, 30, "Einführung Mikrobiologie", Vorlesung::Type::VO, 350);
    all_VOs.emplace_back(200, Vorlesung::Semester::WS, 20, "Grundlagen der Biochemie", Vorlesung::Type::VO, 200);
    all_VOs.emplace_back(200, Vorlesung::Semester::SS, 25, "Biochemische Uebungen", Vorlesung::Type::UE, 20);
    all_VOs.emplace_back(300, Vorlesung::Semester::WS, 70, "Grundlagen der Volkswirtschaft I", Vorlesung::Type::VO, 350);
    all_VOs.emplace_back(300, Vorlesung::Semester::SS, 75, "Grundlagen der Volkswirtschaft II", Vorlesung::Type::VO, 350);
    all_VOs.emplace_back(300, Vorlesung::Semester::WS, 25, "Rechnungswesen in der Praxis", Vorlesung::Type::ILV, 30);
    all_VOs.emplace_back(300, Vorlesung::Semester::SS, 50, "Managementsysteme", Vorlesung::Type::UE, 50);

    Vorlesung Error(400);
    cout << " --- TESTING ERROR VO --- \n";
    cout << Error << "  ";
    Error.print_capacity();
    Error.set_semester(Vorlesung::Semester::SS);
    Error.set_vonummer(15);
    Error.set_max(250);
    Error.set_voname("DUMMY");
    cout << Error << "  ";
    Error.print_capacity();

    // Zuweisung VOs zu Studien
    cout << "\n   ---------   Studiengänge   ---------  \n ";
    for(const auto& i :all_VOs){Studium::get_stdStudium(i.get_institut())->add_VO(i);}
    Studium::get_stdStudium(100)->print();
    Studium::get_stdStudium(200)->print();
    Studium::get_stdStudium(300)->print();

    try{
        Studium::get_stdStudium(Error.get_institut())->add_VO(Error);
    } catch(const char *e) {cerr << e << endl;}

    // Initiation Studenten
    Student MH("Moritz", "Hadinger", "21.03.1995");
    Student LN("Lisa", "Neuer", 5);
    Student TS("Theresa", "Stolling", 2);
    Student AK("Anna", "Kalova", 12);
    AK.set_status(false);

    // Inititation Professoren
    Professor EM("Ernst", "Mayer", 100);
    Professor HOB("Heinz Oliver", "Bach", "18.03.1967", 300);

    // Studenten Anmelden
    cout << "\n   ---------   An- & Abmeldungen   ---------   \n";
    MH.anmeldung(all_VOs[0]);
    LN.anmeldung(all_VOs[0]);
    LN.anmeldung(all_VOs[2]);
    LN.anmeldung(all_VOs[3]);
    AK.anmeldung(all_VOs[5]);
    MH.anmeldung(all_VOs[0]);
    TS.anmeldung(all_VOs[10]);
    TS.anmeldung(all_VOs[7]);

    //Studenten Abmelden
    TS.abmeldung(all_VOs[7]);
    LN.abmeldung(all_VOs[6]);

    // Studenten printen
    cout << "\n   ---------   Studenten   ---------   \n";
    cout << MH << endl;
    MH.set_semester(3);
    cout << MH << endl;
    cout << LN << endl;
    cout << TS << endl;
    cout << AK << endl;

    // Professoren printen
    cout << "\n   ---------   Professoren   ---------   \n";
    cout << HOB << "\n Geburtstag: " << HOB.get_Geburtstag() << endl;
    EM.add_VO(all_VOs[1]);
    cout << '\n' << EM;

    // Statistiken
    cout << "\n   ---------   Statistik   ---------   \n";
    cout << "Derzeit sind " << Student::count << " Studenten inskribiert und " << Professor::count
         << " Professoren angestellt." << endl;
    cout << "Zu " << Vorlesung::belegt << " Vorlesungen sind Studenten angemeldet." << endl;


    return 0;
}