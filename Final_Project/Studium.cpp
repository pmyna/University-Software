#include "Studium.h"

vector<Studium *> Studium::stdStudien;

Studium *Studium::get_stdStudium(const int &k) {
    init_Studium();
    for (auto *pStudium: stdStudien) {
        if (pStudium->get_kennzahl() == k) {return pStudium;}}
    throw "Kennzahl nicht bekannt!";
}