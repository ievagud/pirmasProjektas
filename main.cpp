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

    spausdintiLentele(studentuSarasas);

    return 0;

    }
