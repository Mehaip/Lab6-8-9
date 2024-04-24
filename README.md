## Lab 6

**Timp de lucru:** 2 săptămâni

#### Cerințe generale:

- Creați o aplicație C++ folosind paradigma orientată obiect.
- Aplicația are interfața utilizator tip consolă.
- Utilizați procesul de dezvoltare bazat pe funcționalități (Feature driven development). Identificați funcționalitățile și planificați-le pe două iterații.
- Folosiți o arhitectură stratificată (UI / Servicii (GRASP Controller) / Repository). Creați clase pentru: Domeniu (Domain), Serviciu (Service), Interfață Utilizator (UI), și Repositoriu (Repository).
- Toate funcțiile necesare vor fi specificate și testate (Test Code Coverage >99% la toate modulele în afara de UI).  ✅ 
- Fără avertismente (în Visual Studio, nivelul de avertismente /W4, tratament a avertismentelor ca erori).
- Const Correctness:
  - Folosiți calificativul `const` pentru variabile/parametrii care nu sunt modificați. ✅ 
  - Folosiți calificativul `const` pentru metode care nu modifică starea obiectelor. ✅ 
  - Transmiteți parametrii prin `const &` peste tot unde este posibil. ✅ 
  - Evitați copierea obiectelor când nu este necesar.

#### Iterație 1:

- Folosiți clasa `std::string` și clasa `std::vector` din STL (Standard Template Library, biblioteca standard C++). ✅ 
- Nu folosiți pointeri.  ✅
- Nu alocați dinamic.   ✅

#### Iterația 2:

- Înlocuiți clasa `std::vector` cu o clasă proprie parametrizată (Template) care implementează o listă folosind structura de date listă înlănțuită sau vector dinamic (la alegere).
- Validarea datelor. Utilizatorul este anunțat printr-un mesaj dacă: ✅
  - Introduce valori de intrare greșite.
  - Încearcă să adauge o entitate de două ori.
  - Încearcă să șteargă / modifice o entitate inexistentă (se vor folosi excepții). 
- Creați o diagramă UML a claselor pentru a schița arhitectura aplicației.

#### Lab 8-9

#### Iteratie 1:



## Contract de studii

Creați o aplicație care permite:

- Gestiunea unei liste de discipline. Fiecare disciplină are următoarele atribute: denumire, ore pe săptămână, tip, cadru didactic.
- Funcționalități:
  - Adăugare, ștergere, modificare și afișare a disciplinelor. ✅ 
  - Căutare a unei discipline. ✅ 
  - Filtrare a disciplinelor după numărul de ore sau cadru didactic. ✅
  - Sortare a disciplinelor după: denumire, număr de ore, cadru didactic și tip. ✅
