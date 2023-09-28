#include "mylib.h"

studentas ivesk(){
    studentas temp;
    cout << "Iveskite varda (arba 0, jei norite baigti ivedima): ";
    cin>> temp.vardas;

    if (temp.vardas == "0") {
        return temp;
    }


    cout << "Iveskite pavarde: ";
    cin >> temp.pavarde;

    double pazymys;
    cout << "Iveskite namu darbu rezultatus (iveskite -1, jei norite baigti): ";
    while (true) {
        cin >> pazymys;
        if (pazymys == -1) {
            break;
        }
        temp.pazymiai.push_back(pazymys);
    }

    cout << "Iveskite egzamino rezultata: ";
    cin >> temp.egzaminas;


    double nd_suma = temp.egzaminas;
    for (double grade : temp.pazymiai) {
        nd_suma += grade;
    }

    temp.rez = nd_suma / (temp.pazymiai.size() + 1);
    cout << fixed << setprecision(2) << temp.rez << endl;

    return temp;

    }

void spausdintiLentele(const vector<studentas>& studentuSarasas) {
    cout << "\n";
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vidurkis)" << "\n";
    cout << "--------------------------------------------------------\n";

    for (const studentas& student : studentuSarasas) {
        cout << left << setw(15) << student.vardas << setw(15) << student.pavarde << setw(20) << student.rez << "\n";
    }

    cout << "--------------------------------------------------------\n";
}
