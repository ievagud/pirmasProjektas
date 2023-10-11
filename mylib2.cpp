#include "mylib.h"


void generavimas(int stud_sk) {
    string failopavadinimas;

    if (stud_sk == 1000) {
            failopavadinimas = "tukstantis.txt";
        } else if (stud_sk == 10000) {
            failopavadinimas = "10tukst.txt";
        } else if (stud_sk == 100000) {
            failopavadinimas = "100tukst.txt";
        } else if (stud_sk == 1000000) {
            failopavadinimas = "milijonas.txt";
        } else if (stud_sk == 10000000) {
            failopavadinimas = "10milijonu.txt";
        } else {
            cerr << "Nepavyko nustatyti failo dydžio!" << endl;

        }

    ofstream outputas(failopavadinimas); // Open the file with the determined name
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

void nuskaityk2(vector<studentas>& target, int stud_sk) {
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
    } else if (stud_sk == 5) {
        failo_pvd = "testavimui.txt";
    } else {
        cerr << "Nepavyko nustatyti failo dydžio!" << std::endl;
        return;
    }

    ifstream failas(failo_pvd);

    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo!" << endl;
        return;
    }

    string eil;
    getline(failas, eil);

    int numHomeworkColumns = 10;

    while (getline(failas, eil)) {
        studentas Studentas;
        stringstream x(eil);
        x >> Studentas.vardas >> Studentas.pavarde;

        Studentas.pazymiai.resize(numHomeworkColumns);

        for (int i = 0; i < numHomeworkColumns; i++) {
            if (x >> Studentas.pazymiai[i]) {
            }
        }

        x >> Studentas.egzaminas;

        double galutinis1 = 0.4 * vidurkis(Studentas.pazymiai) + 0.6 * Studentas.egzaminas;
        Studentas.rez_vid = galutinis1;
        target.push_back(Studentas);
    }

    failas.close();
}

void sortStudentsByFinalGrade(const vector<studentas>& students, vector<studentas>& durni, vector<studentas>& nedurni) {
    for (const studentas& student : students) {
        if (student.rez_vid < 5) {
            durni.push_back(student);
        } else {
            nedurni.push_back(student);
        }
    }
}


void writeStudentDataToFile(const vector<studentas>& students, const string& filename) {
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << filename << endl;
        return;
    }

    outputFile << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis" << "\n";
    outputFile << string(70, '-') << endl;

    for (const studentas& student : students) {
        outputFile << left << setw(15) << student.vardas << setw(15) << student.pavarde << setw(20) << fixed << setprecision(2) << student.rez_vid << "\n";
    }

    outputFile.close();
}












