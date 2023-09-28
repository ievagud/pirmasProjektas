#include "mylib.h"


double mediana(const vector<double>& sk) {
    if (sk.empty()) {
        return 0;
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

double vidurkis(const vector<double>& pazymiai) {
    double nd_suma = 0;
    for (double paz : pazymiai) {
        nd_suma += paz;
    }
    return pazymiai.size() > 0 ? nd_suma / pazymiai.size() : 0;
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
    cout << "Ar norite sugeneruoti atsitiktinius pazymius? (1 - Taip, 0 - Ne): ";
    double rand_pazymiai;
    cin >> rand_pazymiai;

    if (rand_pazymiai == 1) {
        srand(time(0));
        int rand_pazymiu_sk = rand() % 11;
        cout << "Sugeneruoti atsitiktiniai pazymiai: ";
        for (int i = 0; i < rand_pazymiu_sk; ++i) {
            int rand_pazymys = rand() % 11;
            temp.pazymiai.push_back(rand_pazymys);
            cout << rand_pazymys << " ";
        }

        srand(time(0));
        temp.egzaminas = rand() % 11;
        cout << "Sugeneruotas egzamino pazymys: "<< temp.egzaminas << endl;
        cout << "\n";

    } else {

       while (true) {
            cout << "Iveskite pazymi (nuo 0 iki 10, iveskite -1, jei norite baigti ivedima ): ";

            if (cin >> pazymys) {
                if (pazymys == -1) {
                    break;
                }

                if (pazymys >= 0 && pazymys <= 10) {
                    temp.pazymiai.push_back(pazymys);
                } else {
                    cout << "Ivestas pazymys netinkamas!" << endl;
                    }
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ivestas pazymys netinkamas!" << endl;
                }
        }

        double egz;
        cout << "Iveskite egzamino pazymi (0-10): ";
        while (true) {
            if (cin >> egz && egz >= 0 && egz <= 10) {
                break;
            } else {
                cout << "Ivestas pazymys netinkamas! Iveskite pazymi (0-10): ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }


    }



    temp.rez_vid = 0.4 * vidurkis(temp.pazymiai) + 0.6 * temp.egzaminas;
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
