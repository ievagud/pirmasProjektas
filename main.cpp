#include "mylib.h"
#include "timer.h"

int main() {

    vector<studentas> studentuSarasas;
    vector<studentas> nuskaitymui;
    vector<studentas> vargsiukai;
    vector<studentas> kietakai;

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

    } else if (x == 2) {


        while (true) {
            studentas studentai2 = ivesk();
            if (studentai2.vardas == "0") {
                break;
            }

            studentuSarasas.push_back(studentai2);

            int pasirink;
            cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
            cin >> pasirink;

            spausdintiLentele(studentuSarasas, pasirink);
        }

    } else if (x==3){
        vector<int> stud_sk = {1000, 10000, 100000, 1000000, 10000000};

        for (int x: stud_sk ) {

            double trys_nusk = 0;
            double trys_rus = 0;
            double trys_v_isved = 0;
            double trys_k_isved = 0;

            nuskaitymui.clear();
            vargsiukai.clear();
            kietakai.clear();

            Timer a;
            generavimas(x);
            double gen_laikas = a.elapsed();
            cout << "Generavimas uztruko " << gen_laikas << " sekundziu" << endl;

            for (int i = 1; i <= bandymai; i++) {
                nuskaitymui.clear();
                vargsiukai.clear();
                kietakai.clear();

                Timer b;
                nuskaityk2(nuskaitymui, x);
                double nusk_laikas = b.elapsed();
                trys_nusk += nusk_laikas;

                Timer c;
                sort_galutinio(nuskaitymui, vargsiukai, kietakai);
                double rus_laikas = c.elapsed();
                trys_rus += rus_laikas;

                string vargsu = "vargsiukai" + to_string(x) + ".txt";
                string kietuku = "kietakai" + to_string(x) + ".txt";

                Timer d;
                irasymas_i_faila(vargsiukai, vargsu);
                double isved_laikas1 = d.elapsed();
                trys_v_isved += isved_laikas1;

                Timer e;
                irasymas_i_faila(kietakai, kietuku);
                double isved_laikas2 = e.elapsed();
                trys_k_isved += isved_laikas2;
            }
            double vidurkis1 = trys_nusk / bandymai;
            cout << "Vidutinis nuskaitymo laikas: " << vidurkis1 << endl;

            double vidurkis2 = trys_rus / bandymai;
            cout << "Vidutinis rusiavimo laikas: " << vidurkis2 << endl;

            double vidurkis3 = trys_k_isved / bandymai;
            cout << "Vidutinis vargsiuku isvedimo i faila laikas: " << vidurkis3 << endl;

            double vidurkis4 = trys_p_isved / bandymai;
            cout << "Vidutinis kietaku isvedimo i faila laikas: " << vidurkis4 << endl;
            cout << "\n";

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

