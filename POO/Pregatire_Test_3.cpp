#include <iostream>
using namespace std;

class Angajat {
protected:
	string nume = "Anonim";
	float salariuBaza = 0;

public:
	Angajat() {
		cout << "\nApel constructor fara param";
	}

	explicit Angajat(string _nume) {
		this->nume = _nume;
	}

	Angajat(string _nume, float _salariuBaza) {
		cout << "\nApel constructor cu param Angajat";
		this->nume = _nume;
		this->salariuBaza = _salariuBaza;
	}

	Angajat(const Angajat& a) { //constructor de copiere
		cout << "\nApel constructor copiere";
		this->nume = a.nume;
		this->salariuBaza = a.salariuBaza;
	}

	Angajat& operator=(const Angajat& a) {
		if (this != &a) {
			this->nume = a.nume;
			this->salariuBaza = a.salariuBaza;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a);

	float calculSalariu() {
		return this->salariuBaza;
	}

	bool operator==(const Angajat& a) const {
		return this->nume == a.nume;
	}

	bool operator!() {
		return this->salariuBaza == 0;
	}

	//cast la string
	explicit operator string() {
		return this->nume;
	}

	operator double() {
		return this->salariuBaza;
	}

	~Angajat() {
		cout << "\nApel destructor angajat";
	}
};

class Manager :public Angajat {
	int nrSubordonati;
public:
	Manager() {
		cout << "\nApel constructor fara param";
	}

	Manager(string _nume, float _salariuBaza, int _nrSubordonati):Angajat(_nume,_salariuBaza) {
		cout << "\nApel constructor cu param Manager";
		this->nrSubordonati = _nrSubordonati;
	}

	Manager(Angajat a, int _nrSubordonati) :Angajat(a) {
		cout << "\nApel constructor cu param 2 Manager";
		this->nrSubordonati = _nrSubordonati;
	}

	Manager(const Manager& m) :Angajat(m), nrSubordonati(m.nrSubordonati) {//constructor de copiere, folosind upcast
		cout << "\nApel constructor copiere Manager";
		this->nrSubordonati = m.nrSubordonati;
	}

	Manager operator=(const Manager& m) {
		cout << "\nApel operator= Manager";
		if (this != &m) {
			this->Angajat::operator=(m);//upcast
			this->nrSubordonati = m.nrSubordonati;
		}
		return *this;
	}

	~Manager() {
		cout << "\nApel destructor Manager";
	}







	friend ostream& operator<<(ostream& out, Manager& m);

};


ostream& operator<<(ostream& out, Manager& m) {
	out << (Angajat)m;//upcast explicit prin valoare returneaza o copie care ulterior este distrusa
	out << "\nNr Subordonati: " << m.nrSubordonati;
	return out;
}

ostream& operator<<(ostream& out, const Angajat& a) {
	out << "\nNume: " << a.nume;
	out << "\nSalariu baza: " << a.salariuBaza;
	return out;
}








int main() {
	Angajat a1("Gigel", 1200);
	cout << a1;
	string nume = (string)a1;//conversie explicita
	cout << "\nNume folosind cast la string: " << nume;
	double salariu = a1;//cast implicit
	cout << "\nNume folosind cast la double: " << salariu;

	return 0;
}