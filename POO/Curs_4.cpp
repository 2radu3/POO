#include <iostream>
using namespace std;
//
class Produs {
	string denumire;
	double pret;
	int stoc;
public:
	// metode
	// 1.constructori
	// in oricare metoda non-statica exista this
	// this -> adresa obiectului apelator

	Produs() {
		cout << "Constructor fara param\n";
		this->denumire = "Anonim"; //. pt obiecte -> pt pointeri
		this->pret = 0;
		this->stoc = 0;
	}
	// niciodata in constructor nu verificam this cu if
	Produs(string _denumire) { //semiconstructor
		cout << "\nConstructor cu cativa param";
		if (_denumire.length() >= 2) {
			this->denumire = _denumire;
		}
		else {
			this->denumire = "Anonim";
		}
		this->pret = 0;
		this->stoc = 0;
	}

	Produs(string _denumire, double _pret, int _stoc) {
		cout << "\nConstructor cu toti parametrii";
		if (_denumire.length() >= 2) {
			this->denumire = _denumire;
		}
		else {
			this->denumire = "Anonim";
		}
		if (_pret > 0) {
			this->pret = _pret;
		}
		else {
			this->pret = 0;
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		else {
			this->stoc = 0;
		}
	}

	// 2.meth accesor (get si set)
	
	string getDenumire() {
		return this->denumire;
	}

	void setDenumire(string _denumire) {
		this->denumire = _denumire;
	}
	
	// 3.destructor
	// 4.meth de prelucrare (afisare)
	
	//metoda de afisare
	void afisare() {
		cout << "\nDenummire: " << this->denumire;
		cout << "\nPret: " << this->pret;
		cout << "\nStoc: " << this->stoc;
	}
	
	// 5.supraincarcare de operatori

};

int main() {
	Produs p; //apeleaza constructorul fara param
	p.afisare();

	//p.setDenumire("lapte");
	//cout << p.getDenunmire();
	//p.afisare();
	//cout << p;
	//p = +10;
	cout << "\nApel Constructori\n";
	Produs p1;
	Produs p2[5];
	Produs* p3;
	Produs p6("Lapte");
	string denumire = "Stilou";
	Produs p7 = denumire;
	Produs p9("Stilou", 100, 10);
	p9.afisare();
	cout << "\nAfisare Denumire\n" << p9.getDenumire();
	p9.setDenumire("Pix");
	cout << "\nAfisare Denumire\n" << p9.getDenumire();

	return 0;
}
