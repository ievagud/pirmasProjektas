#include "mylib.h"

int main() {

    vector<studentas> studentuSarasas;
    vector<studentas> nuskaitymui;
    vector<studentas> durni;
    vector<studentas> nedurni;

    int x;
    cout << "Spauskite 1, jei norite nuskaityti duomenis is failo. Spauskite 2, jei norite ivesti duomenis. Spauskite 3, jei norite sugeneruoti duomenu faila: . Spauskite 4 testavimui" << endl;
    cin >> x;

    if (x == 1) {
        studentas studentai1 = nuskaityk();
        studentuSarasas.push_back(studentai1);

        int pasirink;
        cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
        cin >> pasirink;

        spausdintiLentele(studentuSarasas, pasirink);

    } else if (x == 2) {
        while (true) {
            studentas studentai2 = ivesk();
            if (studentai2.vardas == "0") {
                break;
            }
            studentuSarasas.push_back(studentai2);
        }

        int pasirink;
        cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
        cin >> pasirink;

        spausdintiLentele(studentuSarasas, pasirink);

    } else if (x==3){

        vector<int> stud_sk = {1000, 10000, 100000, 1000000, 10000000};

        for (int x: stud_sk ) {
            generavimas(x);
            nuskaityk2(nuskaitymui, x);
            cout << "nuskaityta"<< endl;
            sortStudentsByFinalGrade(nuskaitymui, durni, nedurni);
            cout << "isrusiavo" << endl;

            string durniFileName = "durni_" + to_string(x) + ".txt";
            string nedurniFileName = "nedurni_" + to_string(x) + ".txt";

            writeStudentDataToFile(durni, durniFileName);
            writeStudentDataToFile(nedurni, nedurniFileName);
            cout << "irase" << endl;

        }

    } else if (x==4){

        nuskaityk2(nuskaitymui, 5);
        cout << "nuskaite tipo" << endl;
        sortStudentsByFinalGrade(nuskaitymui, durni, nedurni);
        writeStudentDataToFile(durni, "durni.txt");
        writeStudentDataToFile(nedurni, "nedurni.txt");
        cout << "irase" << endl;





    } else {
        cout << "Netinkamas ivedimas" << endl;
        return 1;
    }


    /*int pasirink;
    cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
    cin >> pasirink;

    spausdintiLentele(studentuSarasas, pasirink);*/



    }

