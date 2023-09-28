#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct studentas {
    string vardas;
    string pavarde;
    vector <int> pazymiai;
    int egzaminas;
    float rez;
};

studentas ivesk();

#endif // MYLIB_H_INCLUDED
