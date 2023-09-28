#include "mylib.h"

int main() {

    vector<studentas> studentuSarasas;

    while (true) {
        studentas naujasStudentas = ivesk();
        if (naujasStudentas.vardas=="0") {
            break;
        }

        studentuSarasas.push_back(naujasStudentas);
    }

    int pasirink;
    cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
    cin >> pasirink;

    spausdintiLentele(studentuSarasas, pasirink);
    return 0;

    }
