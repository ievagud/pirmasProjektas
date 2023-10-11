#include "mylib.h"
#include "timer.h"

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

            Timer timer;
            generavimas(x);
            double elapsed_gen = timer.elapsed();
            cout << "Generavimas uztruko " << elapsed_gen << " sekundziu" << endl;


            Timer timer1;
            nuskaityk2(nuskaitymui, x);
            double elapsed_nusk = timer.elapsed();
            cout << "Nuskaitymas uztruko " << elapsed_nusk << " sekundziu" << endl;



            Timer timer2;
            sortStudentsByFinalGrade(nuskaitymui, durni, nedurni);
            double elapsed_rus = timer.elapsed();
            cout << "Rusiavimas uztruko " << elapsed_rus << " sekundziu" << endl;


            string durniFileName = "durni_" + to_string(x) + ".txt";
            string nedurniFileName = "nedurni_" + to_string(x) + ".txt";

            Timer timer3;
            writeStudentDataToFile(durni, durniFileName);
            double elapsed_isved = timer.elapsed();
            cout << "Isvedimas durniuku uztruko " << elapsed_isved << " sekundziu" << endl;


            writeStudentDataToFile(nedurni, nedurniFileName);
            cout << "Isvedimas nedurnu uztruko " << elapsed_isved << " sekundziu" << endl;
            cout << "\n";


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

