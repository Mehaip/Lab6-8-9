#include "UI.h"
#include "../Laboratorul/test_domain.h"
#include "../Laboratorul/test_service.h"
#include "../Laboratorul/test_val.h"
#include "../Laboratorul/test_contract_studii.h"
#include "../Laboratorul/test_undo.h"
#include "Validators.h"
#include "Undo.h"


void tests() {
	test_domain();
	test_service();
	test_val();
	test_contract_studii_all();
	test_undo_all();
}

void startApp() {
	MaterieRepository repo;
	MaterieValidator val;
	MaterieService service{ repo, val };
	ConsoleUI ui{ service};
	ui.run();


}

int main() {
	tests();
	startApp();
}