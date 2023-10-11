#include "mylib.h"

void generateDataFile(int stud_sk, const string& failo_pvd) {
    ofstream outputas(failo_pvd);

    if (!outputas.is_open()) {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    /*outputas << left << setw(14) << "Vardas" << left << setw(15) << "\tPavarde";
    for (int j = 1; j <= 10; ++j) {
        outputas << left <<  setw(2) << "\tND" << j;
        }
    outputas << left << setw(2) << "\tEGZ" << endl;

    for (int i = 1; i <= stud_sk; ++i) {
        outputas << left << setw(14) << "Vardas" << i << left << setw(15) << "\tPavarde" << i;
    for (int j = 0; j < 10; ++j) {
        outputas << "\t" << left << setw(15) << rand() % 11;
    }
    outputas << "\t" << left << setw(15) << rand() % 11 << "\n";
    }*/


    /*outputas << left << setw(14) << "Vardas" << setw(15) << "Pavarde";
    for (int j = 1; j <= 10; ++j) {
        outputas << setw(10) << "ND" << j;
    }
    outputas << setw(10) << "EGZ" << endl;

    for (int i = 1; i <= stud_sk; ++i) {
        outputas << left << setw(14) << "Vardas" << i << setw(15) << "Pavarde" << i;
    for (int j = 0; j < 10; ++j) {
        outputas << setw(10) << rand() % 11;
    }
    outputas << setw(10) << rand() % 11 << endl;
    }*/

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

    cout << "Data for " << stud_sk << " students generated and saved to " << failo_pvd << "." << endl;
}
