#include <iostream>
using namespace std;


//camp constant 
//camp static

class Produs {
	char* denumire = nullptr;
	int stoc = 0;
	double pret = 0;
	//to do home denumire initizalizata cu anonim

public:
	//constructor
	//construcotr copiere
	//destructor - nu intra la lucrare
	//operator=
	//design pattern builder care ofera posibilitate de construire obiecte complexe
	Produs() {
		cout << "\nApel constructor fara param";
	}
	Produs(const char* _denumire, int _stoc, double _pret) {
		cout << "\nApel constructor cu toti param";
		if (strlen(_denumire) > 3) {
			this->denumire = new char[strlen(_denumire) + 1];
			strcpy_s(this->denumire, strlen(_denumire) + 1, _denumire);
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		if (_pret > 0) {
			this->pret = _pret;
		}

	}

	Produs(const Produs& p) { //constructor copiere, deep copy
							  //home: chiar daca e const ce anume pot sa modific in p
		cout << "\nApel copy constructor";
		if(p.denumire != nullptr){
			this->denumire = new char[strlen(p.denumire) + 1]; //pentru a nu ocupa aceeasi zona da memorie 
			strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
		}
			this->stoc = p.stoc;
			this->pret = p.pret;
	}

	//operator=
	Produs& operator=(const Produs& p) {
		//obj this deja exista
		//destructor
		//constructor de copiere
		if (this != &p) {
			if (this->denumire != nullptr) {
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			if (p.denumire != nullptr) {
				this->denumire = new char[strlen(p.denumire) + 1]; //pentru a nu ocupa aceeasi zona da memorie 
				strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
			}
			else { //de adaugat caci nu mai este
				this->denumire = nullptr;
			}
			this->stoc = p.stoc;
			this->pret = p.pret;
		}
		return *this;
	}

	void afisare() {
		cout << "\nDenumire: ";
		if (this->denumire != nullptr) {
			cout << this->denumire;
		}
		else {
			cout << "-";
		}
		cout << "\nStoc: " << this->stoc;
		cout << "\nPret: " << this->pret;
	}

	~Produs() { //destructor
		cout << "\nApel destructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			this->denumire = nullptr; //no dangling pointers
		}
	}



};

Produs fctGlobala(Produs p) {
	return p;
}

int main() {

	Produs p1;
	Produs p2("Carte", 100, 120);
	p1.afisare();
	p2.afisare();
	Produs p3 = p2;
	Produs p4(p3);
	cout << "\n------------";
	Produs p5;
	fctGlobala(p5);
	cout << "\n------------";
	Produs* pp = new Produs();
	delete pp;
	pp = nullptr;

	p1= p3 = p2; //operanzi (p3 si p2) pentru
	p1 = p1;
	//autoasignare(nasoala daca am alocare dinamica)
	//reguli supraincarcare opreatori
	//p1. se identifica operanzii
	//p2. daca primul operand este de tipul clasei, atunci se poate supraincarca printr o metoda a clasei
	//iar primul operand este "inghitit" de this
	//else la p2, (aka cout<<p;)
	//daca primul operand nu este de tipul clasei, atunci se supraincarca
	//prin functie globala(no more this)
	//p3. ce returneaza operatorul?
	//p4. ce se modifica!??!?!

	return 0;
}