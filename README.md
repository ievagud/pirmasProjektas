# pirmasProjektas

**v0.1**

Programa išskaidyta į tris failus:

1. **Mylib.h** - sudėtos programai reikalingos bibliotekos, struktūra _studentas_, kurioje laikomi studentų vardai, pavardės, namų darbų pažymiai, egzamino pažymys, galutinis balas skaičiuojant su vidurkiu ir su mediana, deklaruojamos duomenų įvedimo, nuskaitymo iš failo, lentelės spausdinimo, medianos, vidurkio skaičiavimo funkcijos.
2. **Mylib.cpp** - aprašomos programoje naudojamos funkcijos: medianos, vidurkio skaičiavimai, duomenų įvedimo funkcija, su pasirinkimu sugeneruoti atsitiktinius namų darbų ir egzamino pažymius, lentelės spausdinimas, su pasirinkimu galutinį balą išspausdinti skaičiavus su mediana arba vidurkiu, duomenų nuskaitymo iš failo funkcija, kur vartotojas gali įvesti failo, iš kurio nori nuskaityti, pavadinimą.
3. **Main.cpp** - apibrėžiama pagrindinė funkcija _main()_, kurioje vykdoma programa. Sukuriamas vektorius _studentuSarasas_, kuriame bus saugomi studentų duomenys. Vartotojo prašoma pasirinkti, ar jis nori nuskaityti duomenis iš failo ar įvesti duomenis ranka. Pirmu atveju, programa iškviečia _nuskaityk()_ funkciją, kuri nuskaito duomenis iš failo ir prideda juos prie _studentuSarasas_ vektoriaus. Antru atveju, programa iškviečia _ivesk()_ funkciją, kuri leidžia vartotojui įvesti duomenis apie norimą skaičių studentų. Duomenys yra pridedami prie _studentuSarasas_ vektoriaus. Įvedimas baigiamas, kai vartotojas įveda 0 kaip vardo reikšmę. Po duomenų įvedimo, vartotojui leidžiama pasirinkti, galutinį rezultą apskaičiuoti pagal vidurkį ar medianą. Duomenys spausdinami naudojant _spausdintiLentele()_ funkciją, kurioje informacija atvaizduojama lentele su vardais, pavardėmis ir galutiniais balais.



**v0.2**

Programa išskaidyta į penkis failus. Failai **Mylib.h**, **Mylib.cpp**, tokie patys kaip **v0.1** versijoje.

v0.2 atsiradę failai:

3. **timer.h** - aprašoma programos vykdymo laiko matavimo klasė, naudojant modulį.
4. **Mylib2.cpp** - aprašomos programoje naudojamos funkcijos: failų generavimas, failo nuskaitymas, rūšiavimas pagal vardą/pavardę/galutinį balą, išskirstymas į kietakus ir vargšiukus, įrašymas į failą.
5. **Main.cpp** - apibrėžiama pagrindinė funkcija _main()_, kuri yra tokia pat kaip v0.1 versijoje, tik papildyta. Papildymai: vartotojas paprašomas pasirinkti ar duomenis įves pats, ar norės nuskaityti. Pasirinkus duomenų įvedimą, viskas vyksta taip pat kaip v0.1 versijoje. Pasirinkus duomenų nuskaitymą, vartotojas paprašomas pasirinkti ar nori nuskaityti jau egzsituojančius failus, ar pirmiausia failus sugeneruoti ir tada juos nuskaityti. Abiejais atvejais vartotojas turi pasirinkti pagal ką bus rūšiuojami studentai: vardą, pavardę ar galutinį balą. Vykdant programą, matuojamas visų funkcijų vykdymo laikas. Failų generavimo laikas matuojamas vieną kartą, kitų  funkcijų skaičiuojamas vidutinis vykdymo laikas - funkcija įvykdoma tris kartus ir apskaičiuojamas vykdymo laiko vidurkis. 

  

<img width="571" alt="Ekrano kopija 2023-10-25 131334" src="https://github.com/ievagud/pirmasProjektas/assets/144427953/c453235a-c684-478d-8d78-86c2f5efb19c">
<img width="588" alt="Ekrano kopija 2023-10-25 131405" src="https://github.com/ievagud/pirmasProjektas/assets/144427953/ee567ff6-2995-4114-8d12-942541916f33">


**v0.3**

v0.3 versijos programoje visur, kur buvo naudojama _std::vector<studentas>_, pakeista į _std::list<studentas>_

TUKSTANTIS
|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  0.0316878 | 0.00333063  | OOOOOOO  | 0.0009999  | 0  |0.00566663  |0|
| std::list<studentas>  | 0.013842  | OOOOOO  | OOOOOOOO  | 0  | 0.000333833  |0.0036654  |0|

10TUKST
|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  OO | OO  | OO | OO  | OO  |OO |OO|
| std::list<studentas>  | OO  | OO | OO  | 00  | OO  |00  |OO|

100TUKST
|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  OO | OO  | OO | OO  | OO  |OO |OO|
| std::list<studentas>  | OO  | OO | OO  | 00  | OO  |00  |OO|


MILIJONAS
|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  OO | OO  | OO | OO  | OO  |OO |OO|
| std::list<studentas>  | OO  | OO | OO  | 00  | OO  |00  |OO|


10MILIJONU
|         |  Failo nuskaitymas| Rūšiavimas pagal vardą | Rūšiavimas pagal pavardę | Rūšiavimas pagal galutinį balą | Išskirstymas į dvi kategorijas | Vargšiukų išvedimas į failą | Kietakų išvedimas į failą |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| std::vector <studentas>  |  OO | OO  | OO | OO  | OO  |OO |OO|
| std::list<studentas>  | OO  | OO | OO  | 00  | OO  |00  |OO|
