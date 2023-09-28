#include "mylib.h"

int main() {

    vector<studentas> studentuSarasas;

    /*while (true) {
        studentas naujasStudentas = ivesk();
        if (naujasStudentas.vardas=="0") {
            break;
        }

        studentuSarasas.push_back(naujasStudentas);
    }*/

    int x;
    cout << "Spauskite 1, jei norite nuskaityti duomenis is failo. Spauskite 2, jei norite ivesti duomenis: " << endl;
    cin >> x;

    if (x == 1) {
        studentas grupe = nuskaityk();
        studentuSarasas.push_back(grupe);
    } else if (x == 2) {
        while (true) {
            studentas naujasStudentas = ivesk();
            if (naujasStudentas.vardas == "0") {
                break;
            }

            studentuSarasas.push_back(naujasStudentas);
        }
    } else {
        cout << "Netinkamas ivedimas" << endl;
        return 1;
    }

    int pasirink;
    cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
    cin >> pasirink;

    spausdintiLentele(studentuSarasas, pasirink);
    return 0;


    studentas grupe = nuskaityk();


    }
