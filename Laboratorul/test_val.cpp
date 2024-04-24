#include "test_val.h"
#include <assert.h>
#include "Validators.h"

void test_val() {
	MaterieValidator val;
	Materie m{"mate", "prof", 5 }; ///caz corect
	try {
		val.valideaza(m);
		assert(true);
	}
	catch (ValidationException&) {
		assert(false);
	}
	Materie m2{ "", "prof", 5 }; ///nume materie prea mic
	try {
		val.valideaza(m2);
		assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}
	Materie m3{"mate", "", 5 }; ///nume prof prea mic
	try {
		val.valideaza(m3);
		assert(false);
	}
	catch (ValidationException& e) {
		std::cout << e.getErrorMessages();
		assert(true);
	}
	Materie m4{ "mate", "prof", -5 }; ///ore prea putine
	try {
		val.valideaza(m4);
		assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}
}
