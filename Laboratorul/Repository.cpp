#include "Repository.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

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


void FileRepository::load_from_file() {

	std::ifstream fin(filename);
	string line;
	while (getline(fin, line)) {
		istringstream iss(line);
		string nume_materie;
		iss >> nume_materie;
		string profesor;
		iss >> profesor;
		string ore;
		iss >> ore;
		int ore_int;
		ore_int = stoi(ore);
		Materie m(nume_materie, profesor, ore_int);
		MaterieRepository::add_materie(m);


	}
	fin.close();
}

void FileRepository::save_to_file() const {
	ofstream fout(filename);
	int index = 0;
	for (auto& it : primeste_toate_materiile()) {
		fout << it.getNume() << " " << it.getProfesor() << " " << it.getOre();
		if (index != primeste_toate_materiile().size())
			fout << "\n";
	}
	fout.close();
}