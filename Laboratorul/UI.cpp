#include "UI.h"
#include <iostream>
#include <algorithm>
#include "ContractStudii.h"
#include "MaterieDTO.h"
using namespace std;

using std::cout;
using std::cin;
const void ConsoleUI::printMenu() {
	printf("1. Add materie\n");
	printf("2. Delete materie\n");
	printf("3. Update materie\n");
	printf("4. Filter by ore\n");
	printf("5. Filter by profesor\n");
	printf("6. Sort\n");
	printf("7. Contract\n");
	printf("8. Undo\n");
	printf("9. Print all\n");
	printf("0. Exit\n");
}

void ConsoleUI::printeaza_toate_materiile(const vector<Materie>& lista) const {
	int i = 1;
	printf("===============\n");
	for (const Materie& materie : lista) {
		std::cout << i++ << " " << materie;
	}
	printf("===============\n");
}

void ConsoleUI::run() {
	vector<Materie> materii2;
	materii2 = service.primeste_toate_materiile();
	this->service.add_default();
	int command;
	printf("\n\n\n\n\n");

	while (1) {
		
		
		printeaza_toate_materiile(service.primeste_toate_materiile());
		this->printMenu();
		printf(">>> ");
		
			cin >> command;
		
		if (command == 0) {
			printf("adios\n");
			break;
		}
		else if (command == 1) {

			string nume, profesor;
			int ore;
			cout << "Nume: ";
			cin >> nume;
			cout << "Profesor: ";
			cin >> profesor;
			cout << "Ore: ";
			cin >> ore;
			try{
			service.addMaterieService(nume, profesor, ore);
						}
			catch (ValidationException& e) {
				cout << e.getErrorMessages();
			}
		}
		else if (command == 2) {
			string nume, profesor;
			cout << "Nume: ";
			cin >> nume;
			cout << "Profesor: ";
			cin >> profesor;
			try {
				service.delete_materie(nume, profesor);
			}
			catch (std::invalid_argument& e) {
				cout << e.what();
			}
		}
		else if (command == 3) {
			string nume, profesor;
			cout << "Nume: ";
			cin >> nume;
			cout << "Profesor: ";
			cin >> profesor;

			string new_nume, new_profesor;
			int new_ora;
			cout << '\n';
			cout << "Nume nou: ";
			cin >> new_nume;
			cout << "Profesor nou: ";
			cin >> new_profesor;
			cout << "Ora noua: ";
			cin >> new_ora;

			try {
				service.update_materie(nume, profesor, new_nume, new_profesor, new_ora);
			}
			catch (std::invalid_argument& e) {
				cout << e.what();
			}
			catch (ValidationException& e) {
				cout << e.getErrorMessages();
			}
			
		}
		else if (command == 4) {
			int ora;
			cout << ">>> ";
			cin >> ora;
			vector<Materie> materii_filtrate = service.filter_by_ore(ora);
			printeaza_toate_materiile(materii_filtrate);
		}
		else if (command == 5) {
			string profesor;
			cout << ">>> ";
			cin >> profesor;
			vector<Materie> materii_filtrate = service.filter_by_profesor(profesor);
			printeaza_toate_materiile(materii_filtrate);
		}
		else if (command == 6) {
			int command2, criteriu;
			cout << "1. Nume\n2. Ore\n3. Profesor\n";
			cout << ">>> ";
			cin >> criteriu;
			cout << "1. Ascending\n2. Descending\n";
			cout << ">>> ";
			cin >> command2;
			vector<Materie> materii_sortate;
			
			materii_sortate = service.sort_func(criteriu);
			if (command2 == 2) 
				std::reverse(materii_sortate.begin(), materii_sortate.end());
				

			printeaza_toate_materiile(materii_sortate);
		
		}
		else if (command == 7) {
			printf("1. Adauga\n2. Goleste\n3. Genereaza contract random\n4. Export\n 5. Raport\n");
			printf(">>> ");
			int command2;
			cin >> command2;
			if (command2 == 1) {
				printf("Nume materie: ");
				string nume, profesor;
				cin >> nume;
				printf("Nume profesor: ");
				cin >> profesor;
				
				try {
					service.contract_add(nume, profesor);
					cout << "Materie added to contract!\n";
				}
				catch (const std::invalid_argument& e) {
					cerr << "Errors:\n " << e.what() << "\n";
				}


			}
			else if (command2 == 2) {
				service.contract_empty();
				cout << "Contract emptied!\n";
			}
			else if (command2 == 3) {
				printf("Add number of random elements: ");
				int i;
				cin >> i;
				try {
					service.contract_random(i);
					cout << i << " elements added to contract!\n";
					}
				catch (const std::invalid_argument& e) {
					cerr << "Errors:\n " << e.what() << "\n";

				}

			}
			else if (command2 == 4) {

				cout << "Insert filename: ";
				string filename;
				cin >> filename;
				service.contract_export(filename);
			}
			else if (command2 == 5) {
				printf("Materia si aparitiile ei: \n");
				vector<MaterieDTO> lista_materii = service.contract_raport();

				for (MaterieDTO it : lista_materii) {
					cout << it.get_nume() << ": " << it.get_aparitii()<<"\n";
				}
			}
			else cout << "Error: Se pot introduce valorile 1 2 3 4 sau 5!\n";
			cout << "Contractul contine " << service.contract_get_all().size() << " elemente\n";




		}
		else if (command == 8) {
			try {
				this->service.undo();
			}
			catch(const char* e){
				cout << "Error:\n" << e;
			}
		}
		else if (command == 9) {
						const vector<Materie>& materii = service.primeste_toate_materiile();
						printeaza_toate_materiile(materii);
		}
		else if (command == 10) {
			int numar;
			cout << "Enter a number 0 - 1: ";
			cin >> numar;
		}
		else cout << "Error: Se pot introduce [1, 8]\n";
		

	}
}