#include <assert.h>
#include "Service.h"

void test_add_si_get_all_materii() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService serv(repo, val, contract);
	serv.add_default();
	vector<Materie> materii = serv.primeste_toate_materiile();
	assert(materii.size() == 12);
	assert(materii[0].getNume() == "ASC");
	assert(materii[0].getProfesor() == "Mircea");
	assert(materii[0].getOre() == 32);
}

void test_delete_materie() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService serv(repo, val, contract);
	serv.add_default();
	vector<Materie> materii = serv.primeste_toate_materiile();
	assert(materii.size() == 12);
	serv.delete_materie("ASC", "Mircea");
	materii = serv.primeste_toate_materiile();
	assert(materii.size() == 11);
	assert(materii[0].getNume() == "POO");
	serv.delete_materie("Sport", "Andrei");
	assert(serv.primeste_toate_materiile().size() == 10);
	assert(serv.get_materie_position("ok", "ok") == -1);
	///testam si daca arunca exceptie
	try {
		serv.delete_materie("ok", "ok");
		assert(false);
	}
	catch (std::invalid_argument&) {
		assert(true);
	}

}

void test_update_materie() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService serv(repo, val, contract);
	serv.add_default();
	vector<Materie> materii = serv.primeste_toate_materiile();
	serv.update_materie("ASC", "Mircea", "Mate", "George", 4);
	materii = serv.primeste_toate_materiile();
	assert(materii[0].getNume() == "Mate");
	///testam si daca arunca exceptie
	try {
		serv.update_materie("ok", "ok", "ok", "ok", 0);
	}
	catch (std::invalid_argument&) {
		assert(true);
	}

}

void test_filter_by_ore() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService serv(repo, val, contract);
	serv.add_default();
	assert(serv.filter_by_ore(5).size() == 2);
	printf("TEST!\n");
}

void test_filter_by_profesor() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService serv(repo, val, contract);
	serv.add_default();
	assert(serv.filter_by_profesor("Mircea").size() == 2);
}

void test_sort_by_ore() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService serv(repo, val, contract);
	serv.add_default();
	assert(serv.sort_func(2)[0].getOre() == 4);
	assert(serv.sort_func(1)[0].getNume() == "ASC");
	assert(serv.sort_func(3)[0].getProfesor() == "Ana");

}

void test_repo_insert() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService serv(repo, val, contract);
	serv.add_default();
	Materie m{ "Sisteme de operare", "Emanuel", 15 };
	repo.insert_materie(m, 3);
	assert(serv.primeste_toate_materiile()[3].getNume() == "Sisteme de operare");


}

void test_contract(){
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService serv(repo, val, contract);
	serv.add_default();
	serv.contract_add("ASC", "Mircea");
	assert(serv.contract_get_all().size() == 1);
	serv.contract_empty();
	assert(serv.contract_get_all().size() == 0);

	serv.contract_random(4);
	assert(serv.contract_get_all().size() == 4);
	vector<MaterieDTO> lista = serv.contract_raport();
	serv.contract_empty();

}

void test_probability_repo() {
	ProbabilityRepo repo(0.5);
	MaterieValidator val;
	Contract contract;
	MaterieService serv(repo, val, contract);
	serv.add_default();
	serv.undo();
}



void test_service() {
	test_probability_repo();
	test_add_si_get_all_materii();
	test_delete_materie();
	test_update_materie();
	test_filter_by_ore();
	test_filter_by_profesor();
	test_sort_by_ore();
	test_repo_insert();
	test_contract();
	printf("Repository tested!\n");
	printf("Service tested!\n");

}