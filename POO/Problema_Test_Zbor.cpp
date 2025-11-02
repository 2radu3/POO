#include <iostream>
#pragma warning (disable:4996)
using namespace std;

class Zbor {
	char* destinatie;
	char* sursa;
	int nrLocuri;
	bool* loc; //true->locul este ocupat

public:
	//constructor fara param
	Zbor() {
		this->destinatie = new char[strlen("na") + 1];
		strcpy(this->destinatie, "na");
		this->sursa = new char[strlen("na") + 1];
		strcpy(this->sursa, "na");
		this->nrLocuri = 0;
		for(int i=0;i<this->nrLocuri;i++)
		this->loc[i] = false;
	}

	//constructor care primeste destinatie si sursa
	Zbor(const char* _destinatie, const char* _sursa) {
		this->destinatie = new char[strlen(_destinatie) + 1];
		strcpy(this->destinatie, _destinatie);
		this->sursa = new char[strlen(_sursa) + 1];
		strcpy(this->sursa, _sursa);
		this->nrLocuri = 0;
		for (int i = 0; i < this->nrLocuri; i++)
			this->loc[i] = false;
	}

	//constructor care primeste destinatie, sursa si nrLocuri si initializeaza vectorul pe false
	Zbor(const char* _destinatie, const char* _sursa, int _nrLocuri) {
		if (_destinatie != nullptr) {
			this->destinatie = new char[strlen(_destinatie) + 1];
			strcpy(this->destinatie, _destinatie);
		}
		else {
			this->destinatie = new char[strlen("na") + 1];
			strcpy(this->destinatie, "na");
		}
		
		if (_sursa != nullptr) {
			this->sursa = new char[strlen(_sursa) + 1];
			strcpy(this->sursa, _sursa);
		}
		else {
			this->sursa = new char[strlen("na") + 1];
			strcpy(this->sursa, "na");
		}
		
		if (_nrLocuri >= 0) {
			this->nrLocuri = _nrLocuri;
			this->loc = new bool[nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++)
				this->loc[i] = false;
		}
		else {
			this->nrLocuri = 0;
			this->loc = nullptr;
		}
	}

	//metoda care verifica daca mai exista k locuri libere in avion
	void locuriLibere(int _k) {
		if (_k < 0 || _k>this->nrLocuri) {
			_k = 0;
		}
		else {
			if (this->nrLocuri >= _k) {
				cout << "\nExista";
			}
			else {
				cout << "\nNu exista";
			}
		}
	}

	//metoda care verifica daca mai exista k locuri alaturate libere in avion
	bool locuriAlaturate(int _k) {
		if (_k < 1 || _k>this->nrLocuri) {
			return false;
		}
			
		int locuri=0;
		for (int i = 0; i < this->nrLocuri; i++) {
			if (!this->loc[i]) {
				locuri++;
				if (locuri >= _k) {
					return true;
				}
			}
			else {
				locuri = 0;
			}
		}
		return false;
	}

	//metoda care ocupa un anume loc in avion
	void ocupaLoc(int _index) {
		if (_index < 0 || _index>=this->nrLocuri || this->loc==nullptr) {
			return;
		}
		this->loc[_index] = true;
	}

	//metoda care suplimenteaza cu un nr de locuri (k) primit ca parametru disponibilul din avion
	void adaugaLocuri(int _k) {
		bool* locurinoi = new bool[this->nrLocuri + _k];
		for (int i = 0; i < this->nrLocuri; i++) {
			locurinoi[i] = this->loc[i];
		}
		for (int i = this->nrLocuri; i < this->nrLocuri + _k; i++) {
			locurinoi[i] = false;
		}
		delete[] this->loc;
		this->loc = locurinoi;
		this->nrLocuri += _k;

	}

};

int main() {

	Zbor z1("ro", "ro", 2);
	z1.locuriLibere(2);
	z1.ocupaLoc(1);
	z1.adaugaLocuri(5);
	if (z1.locuriAlaturate(3))
	{
		cout << "\nExista locuri adiacente";
	}
	else {
		cout << "\nNu exista adiacente";
	}
	
	return 0;
}