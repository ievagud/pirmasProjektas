#include "mylib.h"

double mediana(const vector<double>& pazymiai) {
    if (pazymiai.empty()) {
        return 0;
    }

    vector<double> rusiavimui = pazymiai;
    sort(rusiavimui.begin(), rusiavimui.end());

    int n = rusiavimui.size();
    if (n % 2 == 0) {
        int vid = n / 2;
        return (rusiavimui[vid - 1] + rusiavimui[vid]) / 2.0;
    } else {
        return rusiavimui[n / 2];
    }
}

double vidurkis(const vector<double>& pazymiai) {
    double paz_suma = 0;
    for (double paz : pazymiai) {
        paz_suma += paz;
    }
    return pazymiai.size() > 0 ? paz_suma / pazymiai.size() : 0;
}

studentas ivesk(){
    studentas temp;

    cout << "Iveskite varda (arba 0, jei norite baigti ivedima): ";
    cin >> temp.vardas;

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
            try {
                cout << "Iveskite pazymi (nuo 0 iki 10, iveskite -1, jei norite baigti ivedima ): ";
                if (cin >> pazymys) {
                    if (pazymys == -1) {
                        break;
                    }

                    if (pazymys >= 0 && pazymys <= 10) {
                        temp.pazymiai.push_back(pazymys);
                    } else {
                        throw invalid_argument("Ivestas pazymys neatitinka intervalo [0-10]!");
                    }
                } else {
                    throw invalid_argument("Ivestas netinkamas simbolis!");
                }
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        double egz;

        while (true) {
            try {
                cout << "Iveskite egzamino pazymi (0-10): ";

                if (cin >> egz) {
                    if (egz >= 0 && egz <= 10) {
                        break;
                    } else {
                        throw invalid_argument("Ivestas pazymys neatitinka intervalo [0-10]!");
                    }
                } else {
                    throw invalid_argument("Ivestas netinkamas simbolis!");
                }
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

studentas nuskaityk() {
    string failo_pvd;
    cout << "Iveskite failo pavadinima: ";
    cin >> failo_pvd;

    vector<studentas> studentai;
    ifstream failas(failo_pvd);

    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo!" << endl;
    }

    string eil;
    getline(failas, eil);

    stringstream eil_stream(eil);
    string sk;
    int stulp = 0;
    while (eil_stream >> sk) {
        stulp++;
    }

    stulp = stulp-3;
    while (getline(failas, eil)) {
        studentas Studentas;
        stringstream x(eil);
        x >> Studentas.vardas >> Studentas.pavarde;

        for (int i = 1; i <= stulp; i++) {
            int pazymys;
            if (x >> pazymys) {
            }
        }
        x >> Studentas.egzaminas;
        double galutinis = 0.4 * mediana(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rez_med = galutinis;
        double galutinis1 = 0.4 * vidurkis(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rez_vid = galutinis1;
        studentai.push_back(Studentas);
    }

    failas.close();

    sort(studentai.begin(), studentai.end(), [](const studentas& a, const studentas& b) {
            if (a.vardas != b.vardas) {
                return a.vardas < b.vardas;
            } else {
            return a.pavarde < b.pavarde;
            }

    });

    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Med.)" << setw(20) << "Galutinis (Vid.)" << "\n";
    cout << string(70, '-') << endl;
    for (const studentas& student : studentai) {
        cout << left << setw(15) << student.vardas << setw(15) << student.pavarde << setw(20) << fixed << setprecision(2) << student.rez_med << setw(20) << fixed << setprecision(2) << student.rez_vid << "\n";
    }
    cout << string(70, '-') << endl;
}



