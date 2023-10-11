#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <fstream>
#include <ctime>
#include <cstdlib>

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
using std::ifstream;
using std::stringstream;
using std::istringstream;
using std::cerr;
using std::invalid_argument;
using std::out_of_range;

using std::ofstream;
using std::to_string;


struct studentas {
    string vardas;
    string pavarde;
    vector <double> pazymiai;
    double egzaminas;
    double rez_vid;
    double rez_med;

};

studentas ivesk();
void spausdintiLentele(const vector<studentas>&, int pasirink);
studentas nuskaityk();
double mediana(const vector<double>& sk);
double vidurkis(const vector<double>& pazymiai);
void generavimas(int stud_sk, const string& failo_pvd);


#endif // MYLIB_H_INCLUDED
