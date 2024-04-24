#include "Repository.h"
#include <vector>
#include <algorithm>
using std::vector;

const vector<Materie>& MaterieRepository::primeste_toate_materiile() const{
	return this->toateMateriile;
}

void MaterieRepository::add_materie(const Materie& m) {
	this->toateMateriile.push_back(m);	
}

void MaterieRepository::insert_materie(const Materie& m, int poz) {

	this->toateMateriile.insert(this->toateMateriile.begin() + poz, m);
}

void MaterieRepository::delete_materie(int position) {
	this->toateMateriile.erase(this->toateMateriile.begin() + position);
}

int MaterieRepository::get_materie_position(string nume, string profesor) const {
	

	 auto it = find_if(this->toateMateriile.begin(), this->toateMateriile.end(), [nume, profesor](const Materie& m) {return m.getNume() == nume && m.getProfesor() == profesor; });
	 if (it == this->toateMateriile.end())
		 return -1;
	 auto i = distance(this->toateMateriile.begin(), it);
	 return static_cast<int>(i); ///ii dam cast la int
}

void MaterieRepository::update_materie(int position, string new_nume, string new_profesor, int new_ore) {
	this->toateMateriile[position].setNume(new_nume);
	this->toateMateriile[position].setProfesor(new_profesor);
	this->toateMateriile[position].setOre(new_ore);
}