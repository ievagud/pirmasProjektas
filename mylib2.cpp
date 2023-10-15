#include "mylib.h"


void generavimas(int stud_sk) {
    string failopavadinimas;

    if (stud_sk == 1000) {
            failopavadinimas = "1000.txt";
        } else if (stud_sk == 10000) {
            failopavadinimas = "10000.txt";
        } else if (stud_sk == 100000) {
            failopavadinimas = "100000.txt";
        } else if (stud_sk == 1000000) {
            failopavadinimas = "1000000.txt";
        } else if (stud_sk == 10000000) {
            failopavadinimas = "10000000.txt";
        } else {
            cerr << "Nepavyko nustatyti failo dydio!" << endl;

        }

    ofstream outputas(failopavadinimas);
    if (!outputas.is_open()) {
        cerr << "Nepavyko atidaryti failo" << endl;
        return;
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    outputas << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int j = 1; j <= 10; ++j) {

        string nd = "ND" + to_string(j);
        outputas << left << setw(10) << nd;
    }
    outputas << left << setw(10) << "EGZ" << endl;

    for (int i = 1; i <= stud_sk; ++i) {
        string vardas = "Vardas" + to_string(i);
        string pavarde = "Pavarde" + to_string(i);

        outputas << left << setw(15) << vardas << setw(15) << pavarde;

        for (int j = 0; j < 10; ++j) {
            outputas << setw(10) << rand() % 11;
        }

        outputas << setw(10) << rand() % 11 << endl;
    }

    outputas.close();

    cout << "Sugeneruota " << stud_sk << " studentu duomenys. Duomenys issaugoti faile " << failopavadinimas << endl;
}

/*void nuskaityk2(vector<studentas>& vekt, int stud_sk) {
    string failo_pvd;
    if (stud_sk == 1000) {
        failo_pvd = "tukstantis.txt";
    } else if (stud_sk == 10000) {
        failo_pvd = "10tukst.txt";
    } else if (stud_sk == 100000) {
        failo_pvd = "100tukst.txt";
    } else if (stud_sk == 1000000) {
        failo_pvd = "milijonas.txt";
    } else if (stud_sk == 10000000) {
        failo_pvd = "10milijonu.txt";
    } else {
        cerr << "Nepavyko nustatyti failo dydio!" << std::endl;
        return;
    }

    /*failo_pvd = to_string(stud_sk) + ".txt";
    ifstream testFile(failo_pvd);
    if (!testFile) {
        cerr << "Nepavyko nustatyti failo dydio!" << std::endl;
        return;
    }*/


    /*ifstream failas(failo_pvd);

    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo!" << endl;
        return;
    }

    string eil;
    getline(failas, eil);

    int nd_sk = 10;

    while (getline(failas, eil)) {
        studentas Studentas;
        stringstream x(eil);
        x >> Studentas.vardas >> Studentas.pavarde;

        Studentas.pazymiai.resize(nd_sk);

        for (int i = 0; i < nd_sk; i++) {
            if (x >> Studentas.pazymiai[i]) {
            }
        }

        x >> Studentas.egzaminas;

        double galutinis1 = 0.4 * vidurkis(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rez_vid = galutinis1;
        vekt.push_back(Studentas);
    }

    failas.close();


}*/

void nuskaityk2(vector<studentas>& vekt, int stud_sk) {
    string failopvd = to_string(stud_sk) + ".txt";

    ifstream failas(failopvd);
    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo" << endl;
        return;
    }

    string eil;
    getline(failas, eil);

    stringstream x(eil);

    string el;

    int num = 0;
    while (x >> el) {
        num++;
    }
    num = num-3;

    while (getline(failas, eil)) {
        studentas Studentas;
        stringstream stud(eil);
        stud >> Studentas.vardas >> Studentas.pavarde;
        for (int i = 1; i < num; i++) {
            int pazymys;
            if (stud >> pazymys) {
                Studentas.pazymiai.push_back(pazymys);
            }
        }
        stud >> Studentas.egzaminas;

        double galutinis1 = 0.4 * vidurkis(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rez_vid = galutinis1;
        vekt.push_back(Studentas);
    }
}

void sort_galutinio(const vector<studentas>& studentai, vector<studentas>& vargsiukai, vector<studentas>& kietakai) {
    for (const studentas& stud : studentai) {
        if (stud.rez_vid < 5) {
            vargsiukai.push_back(stud);
        } else {
            kietakai.push_back(stud);
        }
    }
}


void irasymas_i_faila(const vector<studentas>& studentai, const string& failo_pvd) {
    ofstream outputas(failo_pvd);

    if (!outputas.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << failo_pvd << endl;
        return;
    }

    outputas << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis" << "\n";
    outputas << string(40, '-') << endl;

    for (const studentas& stud : studentai) {
        outputas << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << setw(20) << fixed << setprecision(2) << stud.rez_vid << "\n";
    }

    outputas.close();
}
