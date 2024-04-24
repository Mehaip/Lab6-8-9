#include <assert.h>
#include "Materie.h"

void test_getters() {
	Materie materie("ASC", "Marian", 10);
	assert(materie.getNume() == "ASC");
	assert(materie.getProfesor() == "Marian");
	assert(materie.getOre() == 10);
}

void test_setters() {
	Materie materie("ASC", "Marian", 10);
	materie.setNume("OOP");
	materie.setProfesor("Mircea");
	materie.setOre(40);
	assert(materie.getNume() == "OOP");
	assert(materie.getProfesor() == "Mircea");
	assert(materie.getOre() == 40);
}


void test_domain() {
	test_getters();
	test_setters();
	printf("Domain tested!\n");
}