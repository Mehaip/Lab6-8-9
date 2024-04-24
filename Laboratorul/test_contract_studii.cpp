#include "test_contract_studii.h"
#include "assert.h"
void test_contract_studii() {
	Contract contract;
	contract.add_materie_to_contract(Materie("POO", "Mihai", 5));
	contract.add_materie_to_contract(Materie("Mate", "George", 4));
	assert(contract.primeste_toate().size() == 2);
}

void test_empty_contract() {
	Contract contract;
	contract.add_materie_to_contract(Materie("POO", "Mihai", 5));
	contract.add_materie_to_contract(Materie("Mate", "George", 4));
	contract.empty_contract();
	assert(contract.primeste_toate().size() == 0);
}

void test_add_random_contracts() {
	Contract contract;
	Materie m1("POO", "Mihai", 5);
	Materie m2("Mate", "George", 4);
	Materie m3("ASC", "Mircea", 3);
	vector<Materie> lista;
	lista.push_back(m1);
	lista.push_back(m2);
	lista.push_back(m3);
	contract.add_random_contracts(lista, 3);
	assert(contract.primeste_toate().size() == 3);
}

void test_save_to_file() {
	Contract contract;
	Materie m1("POO", "Mihai", 5);
	Materie m2("Mate", "George", 4);
	Materie m3("ASC", "Mircea", 3);
	contract.add_materie_to_contract(m1);
	contract.add_materie_to_contract(m2);
	contract.add_materie_to_contract(m3);
	string filename = "test.html";
	contract.save_to_file(filename);
}

void test_raport() {
	Contract contract;
	Materie m1("POO", "Mihai", 5);
	Materie m2("Mate", "George", 4);
	Materie m3("POO", "Mircea", 3);
	contract.add_materie_to_contract(m1);
	contract.add_materie_to_contract(m2);
	contract.add_materie_to_contract(m3);
	vector<MaterieDTO> lista = contract.raport();
	assert(lista.size() == 2);
	assert(lista[1].get_nume() == "POO");
	assert(lista[1].get_aparitii() == 2);
}

void test_contract_studii_all() {
	test_contract_studii();
	test_empty_contract();
	test_add_random_contracts();
	test_save_to_file();
	test_raport();
}