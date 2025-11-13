#include <iostream>
using namespace std;

//urm lucrare in sapt 11, 11/18 decembrie
//sapt viitoare joi si vineri conferinta de securitate, de masterul de securitate

//TO DO HOME 1 !!!
//sa se modeleze clasa Masina(VIN/seria de sasiu; nr de inmatriculare + extra(model, an fabricatie)
//VIN ul este unic si constant(nu poate fi schimbata si o primim la construire prin parametru, dar verificam ca este unica)
//nr de inmatriculare(unic dar nu este constant)
//se poate schimba numarr inmatriculare cu un numar generat automat aleator
//sau pot cere eu numar preferential
//modalitate de verificare a disponibilitatii nr preferentiale

//TO DO HOME 2 !!!
//Sa se modifice implementarea curenta astfle incat id ul generat sa respecte o regula:
//ex1: este format din cifre diferite
//ex2: e un nr impar/prim



class Abonat {
	const int id;//generat automat pentru a oferi unicitate
	int nrApeluri = 0;
	string* apeluri = nullptr;//lista persoanelor contactate //char**
	static int generatorID; //ma ajuta sa generez id-uri dupa o regula;

public:
	Abonat() :id(Abonat::generatorID++) {

	}
	Abonat(int _nrApeluri, string* _apeluri) :id(Abonat::generatorID++)
	{
		if (_nrApeluri > 0 && _apeluri != nullptr) {
			this->nrApeluri = _nrApeluri;
			this->apeluri = new string[_nrApeluri];
			for (int i = 0; i < this->nrApeluri; i++) {
				this->apeluri[i] = _apeluri[i];
			}
		}
	}

	Abonat(const Abonat& a):id(Abonat::generatorID++) { //ca sa ocolesc copierea sau ca sa modific obiectul
		if (a.nrApeluri > 0 && a.apeluri != nullptr) {
			this->nrApeluri = a.nrApeluri;
			this->apeluri = new string[a.nrApeluri];
			for (int i = 0; i < this->nrApeluri; i++) {
				this->apeluri[i] = a.apeluri[i];
			}
		}
	}

	Abonat& operator=(Abonat& a) { //acum stie ca are construcotrul de copiere de asta punem &
		if (this != &a)
		{
			//destructor
			if (this->apeluri != nullptr) {
			delete[] this->apeluri;
			this->apeluri = nullptr;//sa nu avem dangling pointers
		}
			//constructor de copiere
		if (a.nrApeluri > 0 && a.apeluri != nullptr) {
			this->nrApeluri = a.nrApeluri;
			this->apeluri = new string[a.nrApeluri];
			for (int i = 0; i < this->nrApeluri; i++) {
				this->apeluri[i] = a.apeluri[i];
			}
		}
		else {

		}

		}
		return *this; //this e un pointer, * ia obiectul
	
	}

	void afisare() {
		cout << "\nID: " << this->id;
		cout << "\nNr Apeluri: " << this->nrApeluri;
		cout << "\nApeluri:";
		for (int i = 0; i < this->nrApeluri; i++) {
			cout << this->apeluri[i] << " ";
		}
	}

	~Abonat()
	{
		if (this->apeluri != nullptr) {
			delete[] this->apeluri;
			this->apeluri = nullptr;//sa nu avem dangling pointers
		}
	}




};

int Abonat::generatorID = 1000;

int main() {
	Abonat a1;
	a1.afisare();
	string vector[] = { "Ana", "Victor", "Gigel" };
	Abonat a2(3, vector);
	a2.afisare();
	Abonat a3(a2);
	Abonat a4 = a2;
	a4.afisare();
	a3.afisare();
	a1 = a4;
	a1.afisare();

	return 0;
}