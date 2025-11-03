#include <iostream>
#pragma warning (disable:4996)
using namespace std;

class Masina {
	string numarMasina;
	double capacitateRezervor;
	double capacitateCurenta;
	int nrAlimentari;
	double* alimentari;

public:

	//constructor cu un singur parametru (string)
	Masina(string _numarMasina) {
		if (_numarMasina.length() == 7) {
			this->numarMasina = _numarMasina;
		}
		else {
			return;
		}

		this->capacitateRezervor = 0;
		this->capacitateCurenta = 0;
		this->nrAlimentari = 0;
		this->alimentari = nullptr;
	}

	//constructor cu parametri (numarMasina, capacitate rezervor)
	Masina(string _numarMasina, double _capacitateRezervor) {
		if (_numarMasina.length() > 7 || _numarMasina.length() < 7) {
			this->numarMasina = "n/a";
		}
		else {
			this->numarMasina = _numarMasina;
		}

		if (_capacitateRezervor < 0) {
			this->capacitateRezervor = 0;
		}
		else {
			this->capacitateRezervor = _capacitateRezervor;
		}

		this->capacitateCurenta = 0;
		this->nrAlimentari = 0;
		this->alimentari = nullptr;
	}

	//constructor cu toti parametri (se vor adauga restrictii la nivelul vectorului de alimentari, daca se depaseste pentru 
	//o alimentare capacitatea rezervorului, atunci aceasta se va inlocui cu capacitatea maxima a rezervorului)
	Masina(string _numarMasina, double _capacitateRezervor, double _capacitateCurenta, int _nrAlimentari, double* _alimentari) {
		if (_numarMasina.length() == 10) {
			this->numarMasina = _numarMasina;
		}
		else {
			this->numarMasina = "n/a";
		}

		if (_capacitateRezervor < 0) {
			this->capacitateRezervor = 0;
		}
		else {
			this->capacitateRezervor = _capacitateRezervor;
		}

		if (_capacitateCurenta < 0) {
			this->capacitateCurenta = 0;
		}
		else if (_capacitateCurenta > this->capacitateRezervor) {
			this->capacitateCurenta = this->capacitateRezervor;
		}
		else {
			this->capacitateCurenta = _capacitateCurenta;
		}

		if (_nrAlimentari < 0)
		{
			this->nrAlimentari = 0;
		}
		else {
			this->nrAlimentari = _nrAlimentari;
		}

		if (_alimentari != nullptr) {
			this->alimentari = new double[this->nrAlimentari];
			for (int i = 0; i < this->nrAlimentari; i++) {
				this->alimentari[i] = _alimentari[i];
				if (this->alimentari[i] > this->capacitateRezervor) {
					this->capacitateCurenta = this->capacitateRezervor;
				}
			}
		}
		else {
			this->alimentari = nullptr;
		}

	}

	//metoda care adauga o noua alimentare tinand cont de restrictiile (capacitate curenta si capacitate rezervor)
	void adaugaAlimentare(double _alimentare) {
		if (_alimentare > 0) {
			double* alimentariNoi = new double[this->nrAlimentari + 1];
			for (int i = 0; i < this->nrAlimentari; i++) {
				alimentariNoi[i] = this->alimentari[i];
			}
			alimentariNoi[this->nrAlimentari] = _alimentare;
			 
			delete[] this->alimentari;
			this->alimentari = alimentariNoi;
			this->nrAlimentari++;
			this->capacitateCurenta = this->capacitateCurenta + _alimentare;
			if (this->capacitateCurenta > this->capacitateRezervor) {
				this->capacitateCurenta = this->capacitateRezervor;
			}
		}
		else {
			return;
		}
	}

	//metoda de afisare dar care afiseaza in loc de vectorul de alimentari doar media tuturor alimentarilor
	void medie() {
		double media = 0, suma = 0;
		for (int i = 0; i < this->nrAlimentari; i++) {
			suma += this->alimentari[i];
		}
		media = suma / this->nrAlimentari;
		cout << "\nMedia: " << media;
	}

	//metoda de afisare
	void afisare() {
		cout << "\nNumar masina: " << this->numarMasina;
		cout << "\nCapacitate Rezervor: " << this->capacitateRezervor;
		cout << "\nCapacitate Curenta: " << this->capacitateCurenta;
		cout << "\nNr Alimentari: " << this->nrAlimentari;
		cout << "\nAlimentari: ";
		for (int i = 0; i < this->nrAlimentari; i++) {
			cout << this->alimentari[i] << " ";
		}
	}
};


int main() {
	double alimentari[] = { 10, 3 };
	Masina m1("OT 23 PRM", 20, 13, 2, alimentari);
	m1.adaugaAlimentare(100);
	m1.afisare();
	m1.medie();

	return 0;
}