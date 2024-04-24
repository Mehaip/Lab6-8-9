#pragma once
#include "Repository.h"
#include "Validators.h"
using std::unique_ptr;
#include "Undo.h"

class MaterieService {
private:
	MaterieRepository& repo;
	MaterieValidator& val;
	std::vector<unique_ptr<ActiuneUndo>> undoActions;
public:


	MaterieService(MaterieRepository& materieRepo, MaterieValidator& materieVal) : repo{ materieRepo }, val{materieVal} {};
	MaterieService(const MaterieService& other) = delete;

	/// <summary>
	/// Returneaza toate materiile
	/// </summary>
	/// <returns></returns>
	const vector<Materie>& primeste_toate_materiile();

	/// <summary>
	/// Adauga o materie
	/// </summary>
	/// <param name="nume"></param>
	/// <param name="profesor"></param>
	/// <param name="ore"></param>
	void addMaterieService(string nume, string profesor, int ore);
	
	/// <summary>
	/// Adauga materii default
	/// </summary>
	/// <returns></returns>

	void add_default();

	/// <summary>
	/// Sterge o materie
	/// </summary>
	/// <param name="nume"></param>
	/// <param name="profesor"></param>

	void delete_materie(string nume, string profesor);

	/// <summary>
	/// Returneaza pozitia unei materii
	/// </summary>
	/// <param name="nume"></param>
	/// <param name="profesor"></param>
	/// <returns></returns>
	int get_materie_position(string nume, string profesor) const;

	/// <summary>
	/// Updateaza o materie
	/// </summary>
	/// <param name="nume"></param>
	/// <param name="profesor"></param>

	void update_materie(string nume, string profesor, string new_nume, string new_profesor, int new_ore);

	/// <summary>
	/// Returneaza materiile care contin nr de ore mai mic decat cel introdus
	/// </summary>
	/// <param name="s"></param>
	/// <returns></returns>

	const vector<Materie> filter_by_ore(int ore);

	/// <summary>
	/// Returneaza materiile care contin profesorul introdus
	/// </summary>
	/// <param name="s"></param>
	
	const vector<Materie> filter_by_profesor(string profesor);

	/// <summary>
	/// Functie sortare
	/// </summary>
	/// <param name="s"></param>

	const vector<Materie> sort_func(int criteriu);

	/// <summary>
	/// Functie de undo
	/// </summary>
	/// <param name="s"></param>

	void undo();


};