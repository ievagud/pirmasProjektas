#include "mylib.h"

int main() {

    vector<studentas> studentuSarasas;

    int x;
    cout << "Spauskite 1, jei norite nuskaityti duomenis is failo. Spauskite 2, jei norite ivesti duomenis. Spauskite 3, jei norite sugeneruoti duomenu faila: " << endl;
    cin >> x;

    if (x == 1) {
        studentas studentai1 = nuskaityk();
        studentuSarasas.push_back(studentai1);
    } else if (x == 2) {
        while (true) {
            studentas studentai2 = ivesk();
            if (studentai2.vardas == "0") {
                break;
            }
            studentuSarasas.push_back(studentai2);
        }
    } else if (x==3){
        int stud_sk;
        cout << "Pasirinkite, kiek studentu turi buti sugeneruotame faile:" << endl;
        cout << "Spauskite 1, jei 1000 studentu" << endl;
        cout << "Spauskite 2, jei 10000 studentu" << endl;
        cout << "Spauskite 3, jei 100000 studentu" << endl;
        cout << "Spauskite 4, jei 1000000 studentu" << endl;
        cout << "Spauskite 5, jei 10000000 studentu" << endl;

        cin >> stud_sk;

        string failo_pvd;

        if (stud_sk == 1) {
            failo_pvd = "tukstantis.txt";
            generavimas(1000, failo_pvd);

        } else if (stud_sk == 2) {
            failo_pvd = "10tukst.txt";
            generavimas(10000, failo_pvd);

        } else if (stud_sk == 3) {
            failo_pvd = "100tukst.txt";
            generavimas(100000, failo_pvd);

        } else if (stud_sk == 4) {
            failo_pvd = "milijonas.txt";
            generavimas(1000000, failo_pvd);

        } else if (stud_sk == 5) {
            failo_pvd = "10milijonu.txt";
            generavimas(10000000, failo_pvd);
        } else {
            cout << "Netinkamas pasirinkimas" << endl;
        }

        studentas studentai1 = nuskaityk();
        studentuSarasas.push_back(studentai1);

    } else {
        cout << "Netinkamas ivedimas" << endl;
        return 1;
    }

    int pasirink;
    cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
    cin >> pasirink;

    spausdintiLentele(studentuSarasas, pasirink);

    }

