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
#include <random>

#include <fstream>
#include <ctime>
#include <cstdlib>

#include <list>

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
using std::default_random_engine;
using std::uniform_int_distribution;

using std::list;


struct studentas {
    string vardas;
    string pavarde;
    vector <double> pazymiai;

     double pazymiai2[10];


    double egzaminas;
    double rez_vid;
    double rez_med;

};

studentas ivesk();
void spausdintiLentele(const list<studentas>& studentuSarasas, int pasirink);
studentas nuskaityk();
double mediana(const vector<double>& sk);
double vidurkis(const vector<double>& pazymiai);

void generavimas(int stud_sk);
void nuskaityk2(list<studentas>& vekt, string failopvd);
void sort_galutinio(const list<studentas>& studentai, list<studentas>& vargsiukai, list<studentas>& kietakai);
void irasymas_i_faila(const list<studentas>& studentai, const string& failo_pvd);
void rusiuotiStudentus(list<studentas>& studentai, int rusiavimas);


#endif // MYLIB_H_INCLUDED
