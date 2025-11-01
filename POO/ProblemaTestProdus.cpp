#include <iostream>
#pragma warning (disable:4996)
using namespace std;

class Produs {
	char denumire[21];
	int nrPreturi;
	double* preturi; //stocheaza istoricul preturilor Produsului
	//nu va contine 2 valori alaturate egale

public:

	//constructor fara param
	Produs() {
		//this->denumire = new char[strlen("Anonim") + 1];
		strcpy(this->denumire, "Anonim");
		this->nrPreturi = 0;
		this->preturi = nullptr;
	}

	//constructor doar cu denumire
	Produs(const char* _denumire) {
		if (_denumire != nullptr && strlen(_denumire) <= 20) {
			strcpy(this->denumire, _denumire);
		}
		else {
			strcpy(this->denumire, "Anonim");
		}
		this->nrPreturi = 0;
		this->preturi = nullptr;
	}

	//constructor cu toti param dar care verifica proprietatea enuntata pentru
	//vectorul de preturi
	Produs(const char* _denumire, int _nrPreturi, double* _preturi) {
		if (_denumire != nullptr && strlen(_denumire) <= 20) {
			strcpy(this->denumire, _denumire);
		}
		else {
			strcpy(this->denumire, "Anonim");
		}

		if (_nrPreturi > 0) {
			this->nrPreturi = _nrPreturi;
		}
		else
		{
			this->nrPreturi = 0;
		}
		int preturinoi = 1;
		for (int i = 1; i < this->nrPreturi; i++) {
			if (_preturi[i] != _preturi[i - 1]) {
				preturinoi++;
			}
		}
		this->preturi = new double[preturinoi];
		this->nrPreturi = preturinoi;

		int index = 1;
		this->preturi[0] = _preturi[0];

		for (int i = 1; i < _nrPreturi; i++) {
			if (_preturi[i] != _preturi[i - 1]) {
				this->preturi[index++] = _preturi[i];
			}
		}

		if (_preturi != 0) {

		}
		else
		{
			this->preturi = nullptr;
		}
	}

	//afisare
	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr Preturi: " << this->nrPreturi;
		cout << "\nPreturi: ";
		for (int i = 0; i < this->nrPreturi; i++)
			cout << this->preturi[i] << " ";
	}

	//metoda care primeste un nou pret si il adauga la sf de vector daca respecta conditia
	void adaugaPret(double _pret) {
		if (this->preturi[this->nrPreturi - 1] != _pret) {
			double* preturinoi = new double[this->nrPreturi + 1];
			for (int i = 0; i < this->nrPreturi; i++)
				preturinoi[i] = this->preturi[i];

			preturinoi[this->nrPreturi] = _pret;
			delete[] this->preturi;
			this->preturi = preturinoi;
			this->nrPreturi++;
		}
	}

	//metoda care elimina din vectorul de preturi primele k valori
	void eliminaPret(int k)
	{
		if (k == this->nrPreturi) {
			this->preturi = nullptr;
			this->nrPreturi = 0;
		}
		if (k<0 || k>this->nrPreturi) {
			k = 0;
		}
		else {
			int index = 0;
			double* preturinoi = new double[this->nrPreturi - k];
			for (int i = k; i < this->nrPreturi; i++) {
				preturinoi[index++] = this->preturi[i];
			}
			delete[] this->preturi;
			this->preturi = preturinoi;
			this->nrPreturi = this->nrPreturi - k;
		}
	}

	//metoda care goleste vectorul de preturi
	void golire() {
		this->nrPreturi = 0;
		this->preturi = nullptr;
	}

	//metoda care returneaza pretul mediu in functie de istoric
	double pretulMediu() {
		double suma = 0;
		for (int i = 0; i < this->nrPreturi; i++)
			suma += this->preturi[i];
		double media = suma / this->nrPreturi;
		return media;
	}

	//metoda care returneaza cel mai mic pret
	double cmmP() {
		double min = this->preturi[0];
		for (int i = 0; i < this->nrPreturi; i++)
			if (this->preturi[i] < min)
				min = this->preturi[i];
			
		return min;
	}
};

int main() {
	double preturi[] = { 10, 11, 12, 8.3 };

	Produs p1("Marcel", 4, preturi);
	p1.adaugaPret(11);
	p1.eliminaPret(2);
	//p1.golire();
	p1.afisare();
	cout << "\nPretul mediu: " << p1.pretulMediu();
	cout << "\nCel mai mic pret: " << p1.cmmP();

	return 0;
}