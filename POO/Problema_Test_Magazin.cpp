#include <iostream>
#pragma warning (disable:4996)
using namespace std;

class Magazin {
	char* denumire;
	int nrProduse;
	int* coduri; //retine codurile produselor, se respecta unicitatea

public:

	//constructor fara param
	Magazin() {
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(this->denumire, "Anonim");
		this->nrProduse = 0;
		this->coduri = nullptr;
	}

	//constructor cu denumire
	Magazin(const char* _denumire) {
		if (_denumire != nullptr) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy(this->denumire, _denumire);
		}
		else {
			//this->denumire = new char[strlen("Anonim") + 1];
			strcpy(this->denumire, "Anonim");
		}

		this->nrProduse = 0;
		this->coduri = nullptr;
	}

	//constructor care primeste toti param dar valideaza unicitatea elem din vector (va elimina dublurile)
	Magazin(const char* _denumire, int _nrProduse, int* _coduri) {
		if (_denumire != nullptr) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy(this->denumire, _denumire);
		}
		else {
			this->denumire = new char[strlen("Anonim") + 1];
			strcpy(this->denumire, "Anonim");
		}

		if (_nrProduse > 0) {
			this->nrProduse = _nrProduse;
		}
		else {
			this->nrProduse = 0;
		}

		if (_coduri != nullptr) {
			int unice = 0;
			for (int i = 0; i < this->nrProduse; i++){
				bool eUnic = true;
				for (int j = 0; j < i; j++) {
					if (_coduri[i] == _coduri[j]) {
						eUnic = false;
						break;
					}
				}
				if (eUnic) {
					unice++;
				}
			}
			this->coduri = new int[unice];
			int index = 0;
			for (int i = 0; i < this->nrProduse; i++) {
				bool eUnic = true;
				for (int j = 0; j < i; j++) {
					if (_coduri[i] == _coduri[j]) {
						eUnic = false;
						break;
					}
				}
				if (eUnic) {
					this->coduri[index++] = _coduri[i];
				}
			}
			this->nrProduse = unice;
		}
		else {
			this->coduri = nullptr;
		}
	}
		
	//metoda care adauga un nou cod in vectorul coduri
	void adaugaCod(int _cod) {
		for (int i = 0; i < this->nrProduse; i++) {
			if (this->coduri[i] == _cod) {
				cout << "\nCodul exista deja\n";
				return;
			}
		}
		int* codurinoi = new int[this->nrProduse + 1];
		for (int i = 0; i < this->nrProduse; i++) {
			codurinoi[i] = this->coduri[i];
		}
		codurinoi[this->nrProduse] = _cod;
		delete[] this->coduri;
		this->coduri = codurinoi;
		this->nrProduse++;
	
	}
			
	//afisare
	void afisare() {
		for (int i = 0; i < this->nrProduse; i++)
			cout << this->coduri[i] << " ";
	}
};

int main() {

	int coduri[] = { 2, 2, 1, 2, 3, 2, 2 };
	Magazin m1("Mihai", 7, coduri);
	m1.adaugaCod(6);
	m1.afisare();

	return 0;
}

