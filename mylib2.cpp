#include "mylib.h"

void generavimas(int stud_sk, const string& failo_pvd) {
    ofstream outputas(failo_pvd);

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

    cout << "Sugeneruota " << stud_sk << " studentu duomenys. Duomenys issaugoti faile " << failo_pvd << endl;
}
