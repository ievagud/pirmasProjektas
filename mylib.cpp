#include "mylib.h"

studentas ivesk(){
    studentas temp;
    cout << "Iveskite varda: ";
    cin >> temp.vardas;
    cout << "Iveskite pavarde: ";
    cin >> temp.pavarde;

    int pazymys;
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
}
