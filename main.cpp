#include "mylib.h"

int main() {

    vector<studentas> studentuSarasas;

    int x;
    cout << "Spauskite 1, jei norite nuskaityti duomenis is failo. Spauskite 2, jei norite ivesti duomenis: " << endl;
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
    } else {
        cout << "Netinkamas ivedimas" << endl;
        return 1;
    }

    int pasirink;
    cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
    cin >> pasirink;

    spausdintiLentele(studentuSarasas, pasirink);

    }

