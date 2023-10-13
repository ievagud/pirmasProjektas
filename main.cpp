#include "mylib.h"
#include "timer.h"

int main() {

    vector<studentas> studentuSarasas;
    vector<studentas> nuskaitymui;
    vector<studentas> kvailiukai;
    vector<studentas> protinguoliai;

    int bandymai = 3;
            double trys_nusk = 0;
            double trys_rus = 0;
            double trys_k_isved = 0;
            double trys_p_isved = 0;


    int x;
    cout << "Spauskite 1, jei norite nuskaityti duomenis is failo. Spauskite 2, jei norite ivesti duomenis. Spauskite 3, jei norite sugeneruoti duomenu failus: " << endl;
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

            Timer a;
            generavimas(x);
            double gen_laikas = a.elapsed();
            cout << "Generavimas uztruko " << gen_laikas << " sekundziu" << endl;


            for (int i = 1; i <= bandymai; i++) {
                Timer b;
                nuskaityk2(nuskaitymui, x);
                double nusk_laikas = b.elapsed();
                cout << "Nuskaitymas nr." << i << " uztruko " << nusk_laikas << " sekundziu" << endl;
                trys_nusk += nusk_laikas;
            }
            double vidurkis1 = trys_nusk / bandymai;
            cout << "Vidutinis nuskaitymo laikas: " << vidurkis1 << endl;
            cout << "\n";


            for (int i = 1; i <= bandymai; i++) {
                Timer c;
                sort_galutinio(nuskaitymui, kvailiukai, protinguoliai);
                double rus_laikas = c.elapsed();
                cout << "Rusiavimas nr." << i << " uztruko " << rus_laikas << " sekundziu" << endl;
                trys_rus += rus_laikas;
            }
            double vidurkis2 = trys_rus / bandymai;
            cout << "Vidutinis rusiavimo laikas: " << vidurkis2 << endl;
            cout << "\n";




            string kvailiuku = "kvailiukai_" + to_string(x) + ".txt";
            string protinguoliu = "protinguoliai_" + to_string(x) + ".txt";


            for (int i = 1; i <= bandymai; i++) {
                Timer d;
                irasymas_i_faila(kvailiukai, kvailiuku);
                double isved_laikas = d.elapsed();
                cout << "Isvedimas durniuku nr." << i << " uztruko " << isved_laikas << " sekundziu" << endl;
                trys_k_isved += isved_laikas;
            }
            double vidurkis3 = trys_k_isved / bandymai;
            cout << "Vidutinis isvedimo laikas: " << vidurkis3 << endl;
            cout << "\n";



            for (int i = 1; i <= bandymai; i++) {
                Timer e;
                irasymas_i_faila(protinguoliai, protinguoliu);
                double isved_laikas = e.elapsed();
                cout << "Isvedimas protingu nr." << i << " uztruko " << isved_laikas << " sekundziu" << endl;
                trys_p_isved += isved_laikas;
            }
            double vidurkis4 = trys_p_isved / bandymai;
            cout << "Vidutinis isvedimo laikas: " << vidurkis4 << endl;
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

