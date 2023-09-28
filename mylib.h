#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>


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
using std::sort;




struct studentas {
    string vardas;
    string pavarde;
    vector <double> pazymiai;
    double egzaminas;
    double rez_vid;
    double rez_med; // Median final grade
};

studentas ivesk();
void spausdintiLentele(const vector<studentas>& studentuSarasas, int pasirink);


#endif // MYLIB_H_INCLUDED
