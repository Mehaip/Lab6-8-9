#include <vector>
#include "Materie.h"
using std::vector;

class RepoAbstract {
public:
	///print all materie
	virtual const vector<Materie>& primeste_toate_materiile() const;

	///add materie
	virtual void add_materie(const Materie& m);

	///inseram materie pe pozitia introdusa
	virtual void insert_materie(const Materie& m, int poz);

	///find pozitia materiei si returneaza un int
	int get_materie_position(string nume, string profesor) const;

	/// sterge materia in functie de pozitia primita
	void delete_materie(int position);

	///modifica materia in functie de pozitia primita si noile date
	void update_materie(int position, string new_nume, string new_profesor, int new_ora);

	///undo functie
	void undo();
};


class MaterieRepository {
private:
	vector <Materie> toateMateriile;
	
public:

	MaterieRepository() = default;
	MaterieRepository(const MaterieRepository& other) = delete;

	///print all materie
	const vector<Materie>& primeste_toate_materiile() const;

	///add materie
	void add_materie(const Materie& m);

	///inseram materie pe pozitia introdusa
	void insert_materie(const Materie& m, int poz);

	///find pozitia materiei si returneaza un int
	int get_materie_position(string nume, string profesor) const;

	/// sterge materia in functie de pozitia primita
	void delete_materie(int position);

	///modifica materia in functie de pozitia primita si noile date
	void update_materie(int position, string new_nume, string new_profesor, int new_ora);

	///undo functie
	void undo();

};