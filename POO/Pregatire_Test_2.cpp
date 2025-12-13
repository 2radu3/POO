#include <iostream>
using namespace std;

class Caracter {

	const int id;
	string denumire = "-";
	int nivelViata = 80;
	int nrArme = 0;
	double* putereArme = nullptr;
	static int minViata;
public:
	Caracter(int _id) : id(_id) {
	}

	Caracter(int _id, string _denumire) :id(_id) {
		if (_denumire.length() > 2) {
			this->denumire = _denumire;
		}
		else {
			this->denumire = "-";
		}
	}

	Caracter(Caracter& c) :id(c.id) { //constructor de copiere
		this->denumire = c.denumire;
		this->nivelViata = c.nivelViata;
		if (c.nrArme > 0 && c.putereArme != nullptr) {
			this->nrArme = c.nrArme;
			this->putereArme = new double[this->nrArme];
			for (int i = 0; i < this->nrArme; i++) {
				this->putereArme[i] = c.putereArme[i];
			}
		}
	}

	Caracter& operator=(const Caracter& c) {
		if (this != &c) {
			if (this->putereArme != nullptr) {
				delete[] this->putereArme;
				this->putereArme = nullptr;
				this->nrArme = 0;
			}
			if (c.nrArme > 0 && c.putereArme != nullptr) {
				this->nrArme = c.nrArme;
				this->putereArme = new double[this->nrArme];
				for (int i = 0; i < this->nrArme; i++) {
					this->putereArme[i] = c.putereArme[i];
				}
			}
		}
		return *this;
	}

	~Caracter() {
		if (this->putereArme != nullptr) {
			delete[] this->putereArme;
			this->putereArme = nullptr;
			this->nrArme = 0;
		}
	}

	Caracter& operator+=(double _x) { //adauga o arma noua si puterea ei o sa fie x
		if (_x > 0) {
			double* rez = new double[this->nrArme+1];
			for (int i = 0; i < this->nrArme; i++)
			{
				rez[i] = this->putereArme[i];
			}
			rez[this->nrArme] = _x;
			delete[] this->putereArme;
			this->putereArme = rez;
			this->nrArme++;
			
		}
		return *this;
	}

	Caracter& operator++() { //forma-prefixata
							 //inmulteste nivelViata cu 1.1 si verif daca > 100
		this->nivelViata *= 1.1;
		if (this->nivelViata > 100)
			this->nivelViata = 100;
		return *this; //returnam obiectul de dupa modificare
	}

	Caracter operator++(int) { //forma-postfixata
		Caracter copie = *this;
		++(*this);
		return copie;

	}

	explicit operator double() {
		double total = 0;
		for (int i = 0; i < this->nrArme; i++)
			total += this->putereArme[i];
		return total;
	}

	Caracter operator+(const Caracter& c) { //sa adauge armele fara +=
		Caracter rez = *this;
		int nrArmeNou = this->nrArme + c.nrArme;
		double* dim = new double[nrArmeNou];
		for (int i = 0; i < this->nrArme; i++) {
			dim[i] = this->putereArme[i];
		}
		for (int i = 0; i < c.nrArme; i++) {
			dim[this->nrArme+i] = c.putereArme[i];
		}
		delete[] rez.putereArme;
		rez.putereArme = dim;
		rez.nrArme = nrArmeNou;

		return rez;
	}
	
	Caracter operator+=(const Caracter& c) {
		int nrArmeNoi = this->nrArme + c.nrArme;
		double* dim = new double[nrArmeNoi];
		for (int i = 0; i < this->nrArme; i++) {
			dim[i] = this->putereArme[i];
		}
		for (int i = 0; i < c.nrArme; i++) {
			dim[this->nrArme + i] = c.putereArme[i];
		}
		delete[] this->putereArme;
		this->putereArme = dim;
		this->nrArme = nrArmeNoi;

		return *this;

	}

	void operator>>(Caracter& c) {
		if (this->nivelViata > Caracter::minViata)
			(*this) += c;
		delete[] c.putereArme;
		c.putereArme = nullptr;
		c.nrArme = 0;
	}




	friend ostream& operator<<(ostream& out, const Caracter& c);
};

int Caracter::minViata = 20;

ostream& operator<<(ostream& out, const Caracter& c) {
	cout << "\nID: " << c.id;
	cout << "\nDenumire: " << c.denumire;
	cout << "\nNivel Viata: " << c.nivelViata;
	cout << "\nNr Arme: " << c.nrArme;
	cout << "\nPutere Arme: ";
	for (int i = 0; i < c.nrArme; i++) {
		cout << c.putereArme[i] << " ";
	}
	return out;


	}























int main() {

	Caracter c1(1, "Jerry");
	cout << c1;
	++c1;
	cout << c1;
	c1 += 3;
	cout << c1;
	double totalArme = (double)c1;
	cout << "\nTotal putere arme: " << totalArme;
	Caracter c2(2, "Marvis");
	c2 += 5;
	c2 += c1;
	cout << c2;
	c1 >> c2;
	cout << c1;
	cout << c2;

	return 0;
}