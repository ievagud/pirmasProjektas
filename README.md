# pirmasProjektas

# **v0.1**

Programa išskaidyta į tris failus:

1. **Mylib.h** - sudėtos programai reikalingos bibliotekos, struktūra _studentas_, kurioje laikomi studentų vardai, pavardės, namų darbų pažymiai, egzamino pažymys, galutinis balas skaičiuojant su vidurkiu ir su mediana, deklaruojamos duomenų įvedimo, nuskaitymo iš failo, lentelės spausdinimo, medianos, vidurkio skaičiavimo funkcijos.
2. **Mylib.cpp** - aprašomos programoje naudojamos funkcijos: medianos, vidurkio skaičiavimai, duomenų įvedimo funkcija, su pasirinkimu sugeneruoti atsitiktinius namų darbų ir egzamino pažymius, lentelės spausdinimas, su pasirinkimu galutinį balą išspausdinti skaičiavus su mediana arba vidurkiu, duomenų nuskaitymo iš failo funkcija, kur vartotojas gali įvesti failo, iš kurio nori nuskaityti, pavadinimą.
3. **Main.cpp** - apibrėžiama pagrindinė funkcija _main()_, kurioje vykdoma programa. Sukuriamas vektorius _studentuSarasas_, kuriame bus saugomi studentų duomenys. Vartotojo prašoma pasirinkti, ar jis nori nuskaityti duomenis iš failo ar įvesti duomenis ranka. Pirmu atveju, programa iškviečia _nuskaityk()_ funkciją, kuri nuskaito duomenis iš failo ir prideda juos prie _studentuSarasas_ vektoriaus. Antru atveju, programa iškviečia _ivesk()_ funkciją, kuri leidžia vartotojui įvesti duomenis apie norimą skaičių studentų. Duomenys yra pridedami prie _studentuSarasas_ vektoriaus. Įvedimas baigiamas, kai vartotojas įveda 0 kaip vardo reikšmę. Po duomenų įvedimo, vartotojui leidžiama pasirinkti, galutinį rezultą apskaičiuoti pagal vidurkį ar medianą. Duomenys spausdinami naudojant _spausdintiLentele()_ funkciją, kurioje informacija atvaizduojama lentele su vardais, pavardėmis ir galutiniais balais.



# **v0.2**

Programa išskaidyta į penkis failus. Failai **Mylib.h**, **Mylib.cpp**, tokie patys kaip **v0.1** versijoje.

v0.2 atsiradę failai:

3. **timer.h** - aprašoma programos vykdymo laiko matavimo klasė, naudojant modulį.
4. **Mylib2.cpp** - aprašomos programoje naudojamos funkcijos: failų generavimas, failo nuskaitymas, rūšiavimas pagal vardą/pavardę/galutinį balą, išskirstymas į kietakus ir vargšiukus, įrašymas į failą.
5. **Main.cpp** - apibrėžiama pagrindinė funkcija _main()_, kuri yra tokia pat kaip v0.1 versijoje, tik papildyta. Papildymai: vartotojas paprašomas pasirinkti ar duomenis įves pats, ar norės nuskaityti. Pasirinkus duomenų įvedimą, viskas vyksta taip pat kaip v0.1 versijoje. Pasirinkus duomenų nuskaitymą, vartotojas paprašomas pasirinkti ar nori nuskaityti jau egzsituojančius failus, ar pirmiausia failus sugeneruoti ir tada juos nuskaityti. Abiejais atvejais vartotojas turi pasirinkti pagal ką bus rūšiuojami studentai: vardą, pavardę ar galutinį balą. Vykdant programą, matuojamas visų funkcijų vykdymo laikas. Failų generavimo laikas matuojamas vieną kartą, kitų  funkcijų skaičiuojamas vidutinis vykdymo laikas - funkcija įvykdoma tris kartus ir apskaičiuojamas vykdymo laiko vidurkis. 

  

<img width="571" alt="Ekrano kopija 2023-10-25 131334" src="https://github.com/ievagud/pirmasProjektas/assets/144427953/c453235a-c684-478d-8d78-86c2f5efb19c">
<img width="588" alt="Ekrano kopija 2023-10-25 131405" src="https://github.com/ievagud/pirmasProjektas/assets/144427953/ee567ff6-2995-4114-8d12-942541916f33">


# **v0.3**

v0.3 versijos programoje visur, kur buvo naudojama _std::vector<studentas>_, pakeista į _std::list<studentas>_

Darbas su failu 1000.txt:

|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  0.062153 | 0.00333063  | 0.00366957  | 0.0029185  | 0.000668467  | 0.00933413  |0|
| std::list<studentas>  | 0.0140934  | 0.000272933  | 0.000666233  | 0.000333333  | 0.000333633  | 0.0033353  |0|

Darbas su failu 10000.txt:

|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  0.231728 | 0.0477258  | 0.0878043 | 0.0253305  | 0.0086661  | 0.0288436 | 0 |
| std::list<studentas>  | 0.930788 | 0.00217117 | 0.00166803 | 0.00200007 | 0.00567667 | 0.0160759 | 0 |

Darbas su failu 100000.txt:

|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  2.38628 | 0.630392  | 0.624465 | 0.436277  | 0.073685  | 0.302921 | 0 |
| std::list<studentas>  | 5.32183 | 0.0373362 | 0.0418439 | 0.055506 | 0.0501776 | 0.179202 | 0 |


Darbas su failu 1000000.txt:

|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  5.39034 | 2.07691  | 1.53819 | 1.14641  | 0.163204  | 0.708835 | 0 |
| std::list<studentas>  | 8.6426 | 0.0970542 | 0.0915231 | 0.207868 | 0.113853 | 0.370543 | 0 |


Darbas su failu 10000000.txt:

|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  197.483 | 86.9633  | 76.3605 | 59.1365  | 46.8657  | 23.9039 | 0 |
| std::list<studentas>  | 105.305 | 6.12198 | 5.36736 | 15.4518 | 25.1268 | 18.8607 | 0 |

Pagal funkcijų vykdymo laikus, naudojant std::list<studentas> programa veikia greičiau. Ypač skirtumas matosi atliekant veiksmus su didesniais failais pvz. su 10 milijonų studentų failu, kur rūšiavimas vyksta kelioliką kartų greičiau su std::list<studentas> nei su std::vector<studentas>

# v1.0

2 strategija su vector (labai ilgai veikia studentų išskirstymas į dvi grupes, pašalinant vargšiuką iš visų studentų vektoriaus)
<img width="852" alt="Ekrano kopija 2023-11-08 174543" src="https://github.com/ievagud/pirmasProjektas/assets/144427953/9beebcb4-c316-4477-9a7f-30bc7dfd6083">

2 strategija su list 
<img width="808" alt="Ekrano kopija 2023-11-08 183122" src="https://github.com/ievagud/pirmasProjektas/assets/144427953/a5e86ac9-5ad0-40cc-8b34-98206e306ec4">

3strategija naudojant 1 strategija
<img width="566" alt="Ekrano kopija 2023-11-08 192945" src="https://github.com/ievagud/pirmasProjektas/assets/144427953/75115a78-a655-4d9b-b74c-f76aef727b21">
<img width="595" alt="Ekrano kopija 2023-11-08 192937" src="https://github.com/ievagud/pirmasProjektas/assets/144427953/389886c9-2307-40f7-8e79-0c64f66a71c4">

