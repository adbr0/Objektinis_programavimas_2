
### Sistemos specifikacija:

* **CPU:** 13th Gen Intel(R) Core(TM) i7-1365U
* **RAM:** 32.0 GB LPDDR5
* **Storage:** SAMSUNG MZVL21T0HDLU-00BLL 
* **Kompiliatorius:** GCC (Code::Blocks aplinkoje)
  
---
### [v0.1]
* Pradinė realizacija su rankiniu duomenų įvedimu, atsitiktinių pažymių generavimu ir nuskaitymu iš failo.
* Galutinio balo skaičiavimas pagal vidurkį arba medianą.
* Rezultatų pateikimas formatuotoje konsolės lentelėje.

### [v0.2]
* Kodas išskaidytas į `studentas.h/cpp`, `funkcijos.h/cpp` ir `main.cpp`.
* Funkcija, sukurianti 5 testinius failus (nuo 1 000 iki 10 000 000 įrašų).
* Realizuotas rūšiavimas pagal naudotojo pasirinktą parametrą (pavardę, vardą, galutinį balą) bei skaidymas į `vargsiukai.txt` (< 5.0) ir `kietekai.txt` (>= 5.0).
* Atliktas I/O ir apdorojimo laiko tyrimas naudojant `<chrono>`.
## [v0.3] – Konteinerių spartos analizė: std::vector vs std::list

### Tyrimo metodika:
* Tyrimas atliktas su 5 duomenų failais (1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 įrašų).
* Kiekvienam konteineriui atlikti 3 bandymai, lentelėje pateikiami apskaičiuoti vidurkiai sekundėmis.

---

### Spartos tyrimo rezultatų palyginimas (vidurkiai):

#### 1 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 0.0035 s | 0.0114 s | std::vector |
| Rūšiavimas | 0.0008 s | 0.0003 s | std::list |
| Dalijimas į 2 grupes | 0.0003 s | 0.0006 s | std::vector |
| Išvedimas į failus | 0.0037 s | 0.0060 s | std::vector |
| **Bendras laikas** | **0.0084 s** | **0.0183 s** | **std::vector** |

#### 10 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 0.0159 s | 0.0463 s | std::vector |
| Rūšiavimas | 0.0064 s | 0.0032 s | std::list |
| Dalijimas į 2 grupes | 0.0023 s | 0.0039 s | std::vector |
| Išvedimas į failus | 0.0114 s | 0.0228 s | std::vector |
| **Bendras laikas** | **0.0360 s** | **0.0762 s** | **std::vector** |

#### 100 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 0.1326 s | 0.2745 s | std::vector |
| Rūšiavimas | 0.0838 s | 0.0337 s | std::list |
| Dalijimas į 2 grupes | 0.0151 s | 0.0373 s | std::vector |
| Išvedimas į failus | 0.1107 s | 0.2343 s | std::vector |
| **Bendras laikas** | **0.3442 s** | **0.5798 s** | **std::vector** |

#### 1 000 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 1.3565 s | 2.7478 s | std::vector |
| Rūšiavimas | 1.1667 s | 0.4358 s | std::list |
| Dalijimas į 2 grupes | 0.1985 s | 0.3741 s | std::vector |
| Išvedimas į failus | 1.2504 s | 2.3098 s | std::vector |
| **Bendras laikas** | **3.9722 s** | **5.8675 s** | **std::vector** |

#### 10 000 000 įrašų
| Operacija | `std::vector` (vidurkis) | `std::list` (vidurkis) | Greitesnis konteineris |
| :--- | :---: | :---: | :---: |
| Duomenų nuskaitymas | 15.8594 s | 27.9072 s | std::vector |
| Rūšiavimas | 16.5368 s | 6.9703 s | std::list |
| Dalijimas į 2 grupes | 2.2394 s | 4.7069 s | std::vector |
| Išvedimas į failus | 14.9393 s | 24.5081 s | std::vector |
| **Bendras laikas** | **49.5882 s** | **64.0924 s** | **std::vector** |

---
### Testavimo eigos ekrano nuotraukos:
#### 1 bandymas
<img width="485" height="475" alt="Screenshot 2026-10-23 154900" src="https://github.com/user-attachments/assets/dd034489-cbb6-4194-9044-d5e20166b7e6" />

#### 2 bandymas
<img width="485" height="480" alt="Screenshot 2026-10-23 155037" src="https://github.com/user-attachments/assets/0cfcc772-2bc3-4b21-b436-0b5692732ff0" />

#### 3 bandymas
<img width="485" height="479" alt="Screenshot 2026-10-23 155206" src="https://github.com/user-attachments/assets/6b9bbdf9-420d-4198-b6c0-1e0c29895e2c" />

---
### v0.3 Išvada:
- **Duomenų nuskaitymas ir išvedimas:** `std::vector` buvo 2 kartus greitesnis už `std::list` dėl tolydaus duomenų išdėstymo atmintyje ir efektyvaus CPU panaudojimo.
- **Rūšiavimas:** `std::list::sort` buvo spartesnis nei `std::sort` ant vektoriaus, nes sąraše perstatomos tik elementų rodyklės, o vektoriuje perkeliami visi studento struktūros duomenys.


## Programos diegimo ir paleidimo instrukcija

Projektas naudoja automatizuotą `Makefile` surinkimo sistemą su `-O3` vėliavėle.

- **Kompiliavimas:**
  - Windows (MinGW): `mingw32-make`
  - Linux / macOS: `make`
- **Paleidimas:**
  - Windows: `programa.exe`
  - Linux / macOS: `./programa`
- **Valymas:**
  - `mingw32-make clean` (arba `make clean`)

---

## [v1.0] – Studentų dalijimo strategijų optimizavimas ir spartos analizė

Šioje versijoje realizuotos ir ištirtos 3 studentų skaidymo į dvi grupes („vargšiukai“ ir „kietekai“) strategijos, naudojant `std::vector` ir `std::list`:
* **1 strategija:** Bendro studentų konteinerio skaidymas į du naujus to paties tipo konteinerius (`vargsiukai` ir `kietekai`).
* **2 strategija:** Naudojamas tik vienas naujas konteineris (`vargsiukai`), o perkelti studentai ištrinami iš pradinio konteinerio.
* **3 strategija (optimizuota):**
  * `std::vector` atveju – elementai pertvarkomi vietoje su `std::stable_partition`.
  * `std::list` atveju – atrenkami su `std::copy_if` ir ištrinami su `std::remove_if`.

---

### Spartos tyrimo rezultatų palyginimas (3 bandymai ir vidurkiai):

#### `std::vector` dalijimo sparta (sekundėmis)

#### 1 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 0.00023 s | 0.00026 s | 0.00025 s | **0.00025 s** |
| 2 strategija (1 naujas + erase) | 0.00230 s | 0.00229 s | 0.00230 s | **0.00230 s** |
| 3 strategija (stable_partition) | 0.00020 s | 0.00028 s | 0.00023 s | **0.00024 s** |

#### 10 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 0.00171 s | 0.00401 s | 0.00216 s | **0.00263 s** |
| 2 strategija (1 naujas + erase) | 0.13966 s | 0.15406 s | 0.16966 s | **0.15446 s** |
| 3 strategija (stable_partition) | 0.00106 s | 0.00104 s | 0.00148 s | **0.00119 s** |

#### 100 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 0.01193 s | 0.01271 s | 0.01880 s | **0.01448 s** |
| 2 strategija (1 naujas + erase) | 17.35977 s | 22.38708 s | 62.03684 s | **33.92790 s** |
| 3 strategija (stable_partition) | 0.01001 s | 0.01764 s | 0.01268 s | **0.01344 s** |

#### 1 000 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 0.11873 s | 0.18579 s | 0.15692 s | **0.15381 s** |
| 2 strategija (1 naujas + erase) | 3931.54666 s | *(praleista)* | *(praleista)* | **~3931.55 s (~65.5 min)** |
| 3 strategija (stable_partition) | 0.10980 s | 0.18422 s | 0.13811 s | **0.14404 s** |

#### 10 000 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 1.55251 s | 1.72796 s | 1.68434 s | **1.65494 s** |
| 2 strategija (1 naujas + erase) | *(praleista)* | *(praleista)* | *(praleista)* | **Neatlikta dėl O(N²)** |
| 3 strategija (stable_partition) | 1.56781 s | 1.94487 s | 1.58775 s | **1.70014 s** |

---

#### `std::list` dalijimo sparta (sekundėmis)

#### 1 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 0.00025 s | 0.00021 s | 0.00024 s | **0.00023 s** |
| 2 strategija (1 naujas + erase) | 0.00009 s | 0.00009 s | 0.00008 s | **0.00009 s** |
| 3 strategija (copy_if / remove_if) | 0.00010 s | 0.00018 s | 0.00010 s | **0.00013 s** |


#### 10 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 0.00186 s | 0.00152 s | 0.00142 s | **0.00160 s** |
| 2 strategija (1 naujas + erase) | 0.00079 s | 0.00101 s | 0.00060 s | **0.00080 s** |
| 3 strategija (copy_if / remove_if) | 0.00130 s | 0.00162 s | 0.00157 s | **0.00150 s** |

#### 100 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 0.01390 s | 0.02008 s | 0.01887 s | **0.01762 s** |
| 2 strategija (1 naujas + erase) | 0.00618 s | 0.01251 s | 0.00833 s | **0.00901 s** |
| 3 strategija (copy_if / remove_if) | 0.01390 s | 0.02365 s | 0.01795 s | **0.01850 s** |

#### 1 000 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 0.22032 s | 0.21944 s | 0.22028 s | **0.22001 s** |
| 2 strategija (1 naujas + erase) | 0.06001 s | 0.11886 s | 0.10781 s | **0.09556 s** |
| 3 strategija (copy_if / remove_if) | 0.21984 s | 0.26030 s | 0.25816 s | **0.24610 s** |

#### 10 000 000 įrašų
| Strategija | 1 bandymas | 2 bandymas | 3 bandymas | Vidurkis |
| :--- | :---: | :---: | :---: | :---: |
| 1 strategija (2 nauji) | 2.79896 s | 2.77290 s | 2.29979 s | **2.62388 s** |
| 2 strategija (1 naujas + erase) | 0.68958 s | 2.91798 s | 1.02950 s | **1.54569 s** |
| 3 strategija (copy_if / remove_if) | 2.51071 s | 6.85801 s | 2.88454 s | **4.08442 s** |

---

### Testavimo eigos ekrano nuotraukos:

#### 0 bandymas
<img width="776" height="509" alt="Screenshot 2026-11-05 215616" src="https://github.com/user-attachments/assets/83120c78-1dce-4d8b-aa68-442f81de5a23" />

#### 1 bandymas
<img width="398" height="450" alt="Screenshot 2026-11-05 222454" src="https://github.com/user-attachments/assets/c1256d94-7836-4d60-845c-cb91f286cbb0" />

#### 2 bandymas
<img width="418" height="451" alt="Screenshot 2026-11-05 222720" src="https://github.com/user-attachments/assets/620eff5e-8e93-4159-b2b9-384e72b6bc2b" />

#### 3 bandymas
<img width="412" height="486" alt="Screenshot 2026-11-05 222954" src="https://github.com/user-attachments/assets/77f69ecd-822f-4a79-b787-4f4061fbb04b" />


---

### v1.0 Išvados ir analizė:

1. **2 strategijos $O(N^2)$ problema su `std::vector`:**
   * Naudojant `erase()` cikle, po kiekvieno elemento ištrynimo visi likę elementai perslenkami atmintyje ($O(N)$ veiksmas).
   * Bendras sudėtingumas tampa **$O(N^2)$**, todėl 1 000 000 įrašų apdorojimas truko **3931.55 s (virš 65 min)**. Vektoriui ši strategija dideliems duomenų kiekiams yra netinkama.
2. **2 strategijos efektyvumas su `std::list`:**
   * Sąraše trynimas (`erase`) yra $O(1)$, nes reikia perstatyti mazgų rodykles. Todėl `std::list` 2 strategijoje veikė sparčiausiai (0.09556 s su 1M įrašų), nes nereikėjo skirti papildomos
     atminties antram konteineriui.
3. **3 strategijos optimizacija:**
   * Vektoriaus atveju `std::stable_partition` algoritmas išsprendė perslinkimų problemą – su 1M įrašų laikas krito nuo 3931 s iki **0.14404 s.**
   * Pritaikius šį algoritmą, vektorius aplenkė sąrašą dėl spartinančiosios atminties efektyvumo tolydžioje atmintyje.
 4. **Atminties sąnaudos (RAM):**
    * **1 strategija:** Neefektyviausia - reikalauja 100% papildomos atminties, nes visi studentai dubliuojami naujuose konteineriuose.
    * **2 strategija:** Reikalauja 40–50% papildomos atminties.
    * **3 strategija (`stable_partition`):** Efektyviausia – studentai pertvarkomi tame pačiame vektoriuje, todėl papildomos atminties beveik nereikia.

---
## [v1.1] Perėjimas prie `class studentas` ir kompiliatoriaus optimizavimo lygių analizė


- Studento duomenys perkelti į `private` sritį, o prieiga prie jų užtikrinta per viešus klasės metodus.
- Klasėje realizuotas destruktorius, kopijavimo konstruktorius bei kopijavimo priskyrimo operatorius.
- Atliktas palyginamasis eksperimentas tarp senosios `struct` (`v1.0`) ir naujosios `class` (`v1.1`) realizacijų, naudojant **`std::vector`** konteinerį bei tris GCC kompiliatoriaus optimizavimo lygius (**`-O1`**, **`-O2`**, **`-O3`**).

---
### 1. Vykdomųjų failų (`.exe`) dydžių palyginimas

| Optimizavimo lygis | `struct` (`v1.0`) failo dydis | `class` (`v1.1`) failo dydis | Skirtumas (`class` vs `struct`) |
| :---: | :---: | :---: | :---: |
| **`-O1`** | 212 KB | 173 KB | -39 KB |
| **`-O2`** | 213 KB | 177 KB | -36 KB |
| **`-O3`** | 215 KB | 170 KB | -45 KB |

---
### 2. Programos veikimo spartos palyginimas (`std::vector`)

#### 1 000 įrašų 
| Realizacija ir optimizavimas | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas į 2 grupes (s) | Išvedimas į failus (s) | **Bendras laikas (s)** |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **`struct` (`-O1`)** | 0.0411 | 0.0003 | 0.0003 | 0.0059 | **0.0477** |
| **`struct` (`-O2`)** | 0.0035 | 0.0004 | 0.0003 | 0.0052 | **0.0094** |
| **`struct` (`-O3`)** | 0.0035 | 0.0004 | 0.0004 | 0.0046 | **0.0089** |
| **`class` (`-O1`)** | 0.0028 | 0.0010 | 0.0005 | 0.0050 | **0.0093** |
| **`class` (`-O2`)** | 0.0036 | 0.0012 | 0.0005 | 0.0060 | **0.0112** |
| **`class` (`-O3`)** | 0.0047 | 0.0013 | 0.0007 | 0.0076 | **0.0143** |

#### 10 000 įrašų 
| Realizacija ir optimizavimas | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas į 2 grupes (s) | Išvedimas į failus (s) | **Bendras laikas (s)** |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **`struct` (`-O1`)** | 0.0505 | 0.0038 | 0.0032 | 0.0184 | **0.0759** |
| **`struct` (`-O2`)** | 0.0209 | 0.0037 | 0.0018 | 0.0176 | **0.0440** |
| **`struct` (`-O3`)** | 0.0334 | 0.0032 | 0.0018 | 0.0182 | **0.0566** |
| **`class` (`-O1`)** | 0.0251 | 0.0108 | 0.0031 | 0.0181 | **0.0571** |
| **`class` (`-O2`)** | 0.0353 | 0.0103 | 0.0032 | 0.0203 | **0.0691** |
| **`class` (`-O3`)** | 0.0256 | 0.0121 | 0.0044 | 0.0218 | **0.0638** |

#### 100 000 įrašų 
| Realizacija ir optimizavimas | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas į 2 grupes (s) | Išvedimas į failus (s) | **Bendras laikas (s)** |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **`struct` (`-O1`)** | 0.1580 | 0.0320 | 0.0150 | 0.1444 | **0.3494** |
| **`struct` (`-O2`)** | 0.1216 | 0.0342 | 0.0158 | 0.1449 | **0.3166** |
| **`struct` (`-O3`)** | 0.1245 | 0.0373 | 0.0131 | 0.1587 | **0.3337** |
| **`class` (`-O1`)** | 0.1743 | 0.1329 | 0.0243 | 0.1682 | **0.4998** |
| **`class` (`-O2`)** | 0.1629 | 0.1252 | 0.0258 | 0.1768 | **0.4908** |
| **`class` (`-O3`)** | 0.1770 | 0.1214 | 0.0255 | 0.1778 | **0.5018** |

#### 1 000 000 įrašų 
| Realizacija ir optimizavimas | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas į 2 grupes (s) | Išvedimas į failus (s) | **Bendras laikas (s)** |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **`struct` (`-O1`)** | 1.3309 | 0.4628 | 0.1558 | 1.4359 | **3.3853** |
| **`struct` (`-O2`)** | 1.2821 | 0.5203 | 0.1744 | 1.4745 | **3.4514** |
| **`struct` (`-O3`)** | 1.3417 | 0.4891 | 0.1588 | 1.4223 | **3.4119** |
| **`class` (`-O1`)** | 1.8007 | 1.7129 | 0.3109 | 1.9289 | **5.7534** |
| **`class` (`-O2`)** | 1.7292 | 1.6447 | 0.2887 | 1.9034 | **5.5660** |
| **`class` (`-O3`)** | 1.7794 | 1.5126 | 0.2777 | 1.9341 | **5.5038** |

#### 10 000 000 įrašų 
| Realizacija ir optimizavimas | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas į 2 grupes (s) | Išvedimas į failus (s) | **Bendras laikas (s)** |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **`struct` (`-O1`)** | 13.2460 | 6.1784 | 1.7131 | 14.1073 | **35.2447** |
| **`struct` (`-O2`)** | 13.3375 | 6.9435 | 1.7312 | 14.5445 | **36.5567** |
| **`struct` (`-O3`)** | 13.2985 | 6.4089 | 1.5477 | 14.5186 | **35.7737** |
| **`class` (`-O1`)** | 19.2244 | 23.8377 | 3.3220 | 19.4550 | **65.8391** |
| **`class` (`-O2`)** | 18.4138 | 23.0355 | 3.1139 | 18.9759 | **63.5391** |
| **`class` (`-O3`)** | 18.2997 | 20.9376 | 3.0154 | 18.8594 | **61.1121** |

---
### 3. Testavimo eigos ekrano nuotraukos (`v1.1`):

#### Objektinė realizacija (`class studentas`)

#### Vykdomųjų failų (`class_O*.exe`) dydžiai
<img width="542" height="53" alt="Screenshot 2026-11-20 191206" src="https://github.com/user-attachments/assets/32195220-2656-4f3d-bf0a-1c752f0089c6" />

#### Optimizavimo lygis `-O1`
<img width="443" height="368" alt="Screenshot 2026-11-20 191620" src="https://github.com/user-attachments/assets/26df5ef8-50b0-4d2a-bbd5-63e9abb0683c" />

#### Optimizavimo lygis `-O2`
<img width="449" height="371" alt="Screenshot 2026-11-20 191828" src="https://github.com/user-attachments/assets/0cf10224-1614-4f0b-b3bb-28c4c2ba6992" />

#### Optimizavimo lygis `-O3`
<img width="454" height="370" alt="Screenshot 2026-11-20 192021" src="https://github.com/user-attachments/assets/9714a2e6-94ee-4902-8ed7-5ba79f47a59f" />

---

#### Struktūrinė realizacija (`struct studentas`)

#### Vykdomųjų failų (`struct_O*.exe`) dydžiai
<img width="361" height="36" alt="Screenshot 2026-11-20 210004" src="https://github.com/user-attachments/assets/6554c5af-c194-498b-8b95-08bead91ba13" />

#### Optimizavimo lygis `-O1`
<img width="490" height="374" alt="Screenshot 2026-11-20 205543" src="https://github.com/user-attachments/assets/36cece34-45a3-448a-9ab3-5f317bcc7d46" />

#### Optimizavimo lygis `-O2`
<img width="479" height="371" alt="Screenshot 2026-11-20 205747" src="https://github.com/user-attachments/assets/f24fa1bd-8235-428d-bdd8-b8ecd3e119c8" />

#### Optimizavimo lygis `-O3`
<img width="521" height="374" alt="Screenshot 2026-11-20 205857" src="https://github.com/user-attachments/assets/255f534d-82cf-4f1f-ad54-b4b19c8bc4dc" />

---
### v1.1 Išvados ir analizė:

1. `struct` realizacija visais atvejais veikia sparčiau (pvz., su `1 000 000` įrašų `struct` užtrunka **3.3853–3.4514 s**, o `class` – **5.5038–5.7534 s**)
2. `class` versijoje aukštesnis optimizavimo lygis pagreitina darbą su didesniais duomenų kiekiais (`1 000 000` įrašų bendras laikas sumažėjo nuo **5.7534 s** su `-O1` iki **5.5038 s** su `-O3`, o su `10 000 000` įrašų – nuo **65.8391 s** iki **61.1121 s**.
3. Optimizavimo vėliavėlės minimaliai keičia galutinį `.exe` failo dydį (`170–177 KB` klasės atveju ir `212–215 KB` struktūros atveju).
