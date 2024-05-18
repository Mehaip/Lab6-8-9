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
	MaterieValidator val;
	Contract contract;
	printf("1. Normal mode\n2. Luck mode\n");
	printf(">>> ");
	int command;
	scanf_s("%d", &command);
	if (command == 2) {
		float chance;
		printf("Enter chance ( 0 - 1 ) : ");
		std::cin >> chance;


		ProbabilityRepo repo_prob(chance);
		MaterieService service{ repo_prob, val, contract };
		ConsoleUI ui{ service };
		ui.run();
	}

	else if (command == 1) {
		MaterieRepository repo;
		MaterieService service{ repo, val, contract };
		ConsoleUI ui{ service };
		ui.run();
	}


}


int main() {
	tests();
	startApp();

}