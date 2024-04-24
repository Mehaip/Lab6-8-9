#pragma once

#include "Service.h"

class ConsoleUI {
private:
	MaterieService& service;

public:
	ConsoleUI(MaterieService& service) : service{ service } {};
	const void printMenu();
	void run();
	void printeaza_toate_materiile(vector<Materie> lista) const;
};