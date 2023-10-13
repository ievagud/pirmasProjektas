#include "mylib.h"
#include "timer.h"

int main() {

    vector<studentas> studentuSarasas;
    vector<studentas> nuskaitymui;
    vector<studentas> durni;
    vector<studentas> nedurni;

    int numRuns = 3;
            double totalElapsedNusk = 0;
            double totalElapsedRus = 0;
            double totalElapsedIsveddurniukai = 0;
            double totalElapsedIsvedprotingi = 0;


    int x;
    cout << "Spauskite 1, jei norite nuskaityti duomenis is failo. Spauskite 2, jei norite ivesti duomenis. Spauskite 3, jei norite sugeneruoti duomenu faila: " << endl;
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


            for (int run = 1; run <= numRuns; run++) {
                Timer timer1;
                nuskaityk2(nuskaitymui, x);
                double elapsed_nusk = timer1.elapsed();
                cout << "Nuskaitymas nr." << run << " uztruko " << elapsed_nusk << " sekundziu" << endl;
                totalElapsedNusk += elapsed_nusk;
            }
            double averageElapsedNusk = totalElapsedNusk / numRuns;
            cout << "Vidutinis nuskaitymo laikas: " << averageElapsedNusk << endl;
            cout << "\n";


            for (int run = 1; run <= numRuns; run++) {
                Timer timer2;
                sort_galutinio(nuskaitymui, durni, nedurni);
                double elapsed_rus = timer2.elapsed();
                cout << "Rusiavimas nr." << run << " uztruko " << elapsed_rus << " sekundziu" << endl;
                totalElapsedRus += elapsed_rus;
            }
            double averageElapsedRus = totalElapsedRus / numRuns;
            cout << "Vidutinis rusiavimo laikas: " << averageElapsedRus << endl;
            cout << "\n";




            string durniFileName = "durni_" + to_string(x) + ".txt";
            string nedurniFileName = "nedurni_" + to_string(x) + ".txt";


            for (int run = 1; run <= numRuns; run++) {
                Timer timer3;
                irasymas_i_faila(durni, durniFileName);
                double elapsed_isved = timer3.elapsed();
                cout << "Isvedimas durniuku nr." << run << " uztruko " << elapsed_isved << " sekundziu" << endl;
                totalElapsedIsveddurniukai += elapsed_isved;
            }
            double averageElapsedIsvedD = totalElapsedIsveddurniukai / numRuns;
            cout << "Vidutinis isvedimo laikas: " << averageElapsedIsvedD << endl;
            cout << "\n";



            for (int run = 1; run <= numRuns; run++) {
                Timer timer4;
                irasymas_i_faila(nedurni, nedurniFileName);
                double elapsed_isved = timer4.elapsed();
                cout << "Isvedimas protingu nr." << run << " uztruko " << elapsed_isved << " sekundziu" << endl;
                totalElapsedIsvedprotingi += elapsed_isved;
            }
            double averageElapsedIsvedP = totalElapsedIsvedprotingi / numRuns;
            cout << "Vidutinis isvedimo laikas: " << averageElapsedIsvedP << endl;
            cout << "\n";
            }

    } else {
        cout << "Netinkamas ivedimas" << endl;
        return 1;
    }


    /*int pasirink;
    cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
    cin >> pasirink;

    spausdintiLentele(studentuSarasas, pasirink);*/



    }

