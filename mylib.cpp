#include "mylib.h"


double mediana(const vector<double>& sk) {
    if (sk.empty()) {
        return 0.0;
    }

    vector<double> isrusiuota = sk;
    sort(isrusiuota.begin(), isrusiuota.end());

    int n = isrusiuota.size();
    if (n % 2 == 0) {
        int mid = n / 2;
        return (isrusiuota[mid - 1] + isrusiuota[mid]) / 2.0;
    } else {
        return isrusiuota[n / 2];
    }
}

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


    double nd_suma = 0;
    for (double paz : temp.pazymiai) {
        nd_suma += paz;
    }

    double vidurkis = temp.pazymiai.size() > 0 ? nd_suma / temp.pazymiai.size() : 0;

    temp.rez_vid = 0.4 * vidurkis + 0.6 * temp.egzaminas;
    temp.rez_med = 0.4 * mediana(temp.pazymiai)+ 0.6 * temp.egzaminas;

}

void spausdintiLentele(const vector<studentas>& studentuSarasas, int pasirink) {
        if (pasirink == 1) {
            cout << "\n";
            cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << "\n";
            cout << string(50,'-') << endl;
            for (const studentas& student : studentuSarasas) {
                cout << left << setw(15) << student.vardas << setw(20) << student.pavarde<< setw(5) << fixed << setprecision(2) << student.rez_vid << "\n";
                }
        } else if (pasirink == 2) {
            cout << "\n";
            cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Med.)" << "\n";
            cout << string(50,'-') << endl;
            for (const studentas& student : studentuSarasas) {
                cout << left << setw(15) << student.vardas << setw(20) << student.pavarde<< setw(5) << fixed << setprecision(2) << student.rez_med << "\n";
                }
        } else {
            cout << "Netinkamas pasirinkimas, rodomas galutinis su vidurkiu: "<< "\n";
            cout << "\n";
            cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis" << "\n";
            cout << string(50,'-') << endl;
            for (const studentas& student : studentuSarasas) {
                cout << left << setw(15) << student.vardas << setw(20) << student.pavarde<< setw(5) << fixed << setprecision(2) << student.rez_vid << "\n";
                }
        }
        cout << string(50,'-') << endl;
    }
