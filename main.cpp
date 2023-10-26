#include "mylib.h"
#include "timer.h"

int main() {

    list<studentas> studentuSarasas;
    list<studentas> nuskaitymui;
    list<studentas> vargsiukai;
    list<studentas> kietakai;

    int bandymai = 3;
    double trys_nusk = 0;
    double trys_rus = 0;
    double trys_k_isved = 0;
    double trys_p_isved = 0;


    int x;
    cout << "Spauskite 1, jei norite nuskaityti duomenis is failo. Spauskite 2, jei norite ivesti duomenis" << endl;
    cin >> x;

    if (x == 1) {
        int y;
        cout << "Spauskite 1, jei norite sugeneruoti failus, juos nuskaityti ir atlikti veiksmus. Spauskite 2, jei norite nuskaityti jau egzistuojanti faila ir atlikti veiksmus " << endl;
        cin >> y;

        if (y == 1){

            int rusiavimas;
            cout << "Pagal ka norite rusiuoti studentus? 1 - pagal varda. 2 - pagal pavarde. 3 - pagal galutini bala" << endl;
            cin >> rusiavimas;

            vector<int> stud_sk = {1000, 10000, 100000, 1000000, 10000000};

            for (int x: stud_sk ) {

                double trys_nusk = 0.0;
                double trys_rus = 0.0;
                double trys_v_isved = 0.0;
                double trys_k_isved = 0.0;
                double tris_k_rusiuoja = 0.0;

                nuskaitymui.clear();
                vargsiukai.clear();
                kietakai.clear();
                string pvd = to_string(x) + ".txt";

                Timer a;
                generavimas(x);
                double gen_laikas = a.elapsed();
                cout << "Generavimas uztruko " << gen_laikas << " sekundziu" << endl;

                for (int i = 1; i <= bandymai; i++) {
                    nuskaitymui.clear();
                    vargsiukai.clear();
                    kietakai.clear();

                    Timer b;
                    nuskaityk2(nuskaitymui, pvd);
                    double nusk_laikas = b.elapsed();
                    trys_nusk += nusk_laikas;

                    Timer h;
                    rusiuotiStudentus(nuskaitymui, rusiavimas);
                    double rusiavimo_laikas = h.elapsed();
                    tris_k_rusiuoja += rusiavimo_laikas;

                    Timer c;
                    sort_galutinio(nuskaitymui, vargsiukai, kietakai);
                    double rus_laikas = c.elapsed();
                    trys_rus += rus_laikas;

                    string vargsu = "vargsiukai" + pvd;
                    string kietuku = "kietakai" + pvd;

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

                double vidurkis99 = tris_k_rusiuoja / bandymai;
                cout << "Vidutinis rusiavimo laikas: " << vidurkis99 << endl;

                double vidurkis2 = trys_rus / bandymai;
                cout << "Vidutinis isskirstymo laikas: " << vidurkis2 << endl;

                double vidurkis3 = trys_k_isved / bandymai;
                cout << "Vidutinis vargsiuku isvedimo i faila laikas: " << vidurkis3 << endl;

                double vidurkis4 = trys_p_isved / bandymai;
                cout << "Vidutinis kietaku isvedimo i faila laikas: " << vidurkis4 << endl;
                cout << "\n";
            }

    } else if (y == 2) {

        string pvd;
        vector<string> pavadinimai;

        while (pvd != "0"){
            cout << "Iveskite failo pavadinima (su .txt). Spauskite 0, jei nebenorite ivesti daugiau failu" << endl;
            cin >> pvd;
            if (pvd != "0") {
            pavadinimai.push_back(pvd);
            }
        }

        int rusiavimas2;
        cout << "Pagal ka norite rusiuoti studentus? 1 - pagal varda. 2 - pagal pavarde. 3 - pagal galutini bala" << endl;
        cin >> rusiavimas2;

        for (string z: pavadinimai) {

                double trys_nusk = 0.0;
                double trys_rus = 0.0;
                double trys_v_isved = 0.0;
                double trys_k_isved = 0.0;
                double tris_k_rusiuoja = 0.0;

        for (int i = 1; i <= bandymai; i++) {
                    nuskaitymui.clear();
                    vargsiukai.clear();
                    kietakai.clear();

                    Timer b;
                    nuskaityk2(nuskaitymui,z);
                    double nusk_laikas = b.elapsed();
                    trys_nusk += nusk_laikas;

                    Timer h;
                    rusiuotiStudentus(nuskaitymui, rusiavimas2);
                    double rusiavimo_laikas = h.elapsed();
                    tris_k_rusiuoja += rusiavimo_laikas;

                    Timer c;
                    sort_galutinio(nuskaitymui, vargsiukai, kietakai);
                    double rus_laikas = c.elapsed();
                    trys_rus += rus_laikas;

                    string vargsu = "vargsiukai_is_" + z;
                    string kietuku = "kietakai_is_" + z;

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

                double vidurkis990 = tris_k_rusiuoja / bandymai;
                cout << "Vidutinis rusiavimo laikas: " << vidurkis990 << endl;

                double vidurkis2 = trys_rus / bandymai;
                cout << "Vidutinis isskirstymo laikas: " << vidurkis2 << endl;

                double vidurkis3 = trys_k_isved / bandymai;
                cout << "Vidutinis vargsiuku isvedimo i faila laikas: " << vidurkis3 << endl;

                double vidurkis4 = trys_p_isved / bandymai;
                cout << "Vidutinis kietaku isvedimo i faila laikas: " << vidurkis4 << endl;
                cout << "\n";
        }

    }

        /*studentas studentai1 = nuskaityk();
        studentuSarasas.push_back(studentai1);*/

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

    } else {
        cout << "Netinkamas ivedimas" << endl;
        return 1;
    }

    int pasirink;
    cout << "Pasirinkite galutinio balo tipa (1 - Vidurkis, 2 - Mediana): ";
    cin >> pasirink;

    spausdintiLentele(studentuSarasas, pasirink);

    }

