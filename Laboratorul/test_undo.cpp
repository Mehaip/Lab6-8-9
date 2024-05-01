#include "test_undo.h"
#include "assert.h"

void test_undo_add() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService srv{ repo,val, contract };
	srv.addMaterieService("Mate", "Oana", 10);
	srv.undo();
	assert(srv.primeste_toate_materiile().size() == 0);
}

void test_undo_delete() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService srv(repo, val, contract);
	srv.addMaterieService("Mate", "Oana", 10);
	srv.delete_materie("Mate", "Oana");
	srv.undo();
	assert(srv.primeste_toate_materiile().size() == 1);
}

void test_undo_update() {
	MaterieRepository repo;
	MaterieValidator val;
	Contract contract;
	MaterieService srv(repo, val, contract);
	srv.addMaterieService("Mate", "Oana", 10);
	srv.update_materie("Mate", "Oana", "Mate", "Aurel", 20);
	assert(srv.primeste_toate_materiile()[0].getOre() == 20);
	assert(srv.primeste_toate_materiile()[0].getProfesor() == "Aurel");
	srv.undo();
	assert(srv.primeste_toate_materiile()[0].getOre() == 10);
	assert(srv.primeste_toate_materiile()[0].getProfesor() == "Oana");

}

void test_undo_all() {
	test_undo_add();
	test_undo_delete();
	test_undo_update();

}