#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;




struct studentas {
    string vardas;
    string pavarde;
    vector <double> pazymiai;
    double egzaminas;
    double rez;
};

studentas ivesk();
void spausdintiLentele(const vector<studentas>& studentuSarasas);


#endif // MYLIB_H_INCLUDED
