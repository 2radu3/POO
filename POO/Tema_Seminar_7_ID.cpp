#include <iostream>
using namespace std;

class Abonat {
	const int id;
	int nrApeluri = 0;
	string* apeluri = nullptr;
	static int generatorID;

	/*int IDUnic() {							//pentru ID cu cifre diferite
		while (!cifreUnice(generatorID)) {
			generatorID++;
		}
		int IDGenerat = generatorID;
		generatorID++;
		return IDGenerat;
	}*/

	int IDPar() {
		while (!numarPar(generatorID)) {
			generatorID++;
		}
		int IDGenerat = generatorID;
		generatorID++;
		return IDGenerat;
	}

public:
	Abonat() :id(IDPar()) {

	}
	Abonat(int _nrApeluri, string* _apeluri) :id(IDPar())
	{
		if (_nrApeluri > 0 && _apeluri != nullptr) {
			this->nrApeluri = _nrApeluri;
			this->apeluri = new string[_nrApeluri];
			for (int i = 0; i < this->nrApeluri; i++) {
				this->apeluri[i] = _apeluri[i];
			}
		}
	}

	Abonat(const Abonat& a) :id(Abonat::generatorID++) {
		if (a.nrApeluri > 0 && a.apeluri != nullptr) {
			this->nrApeluri = a.nrApeluri;
			this->apeluri = new string[a.nrApeluri];
			for (int i = 0; i < this->nrApeluri; i++) {
				this->apeluri[i] = a.apeluri[i];
			}
		}
	}

	Abonat& operator=(Abonat& a) {
		if (this != &a)
		{
			if (this->apeluri != nullptr) {
				delete[] this->apeluri;
				this->apeluri = nullptr;
			}
			if (a.nrApeluri > 0 && a.apeluri != nullptr) {
				this->nrApeluri = a.nrApeluri;
				this->apeluri = new string[a.nrApeluri];
				for (int i = 0; i < this->nrApeluri; i++) {
					this->apeluri[i] = a.apeluri[i];
				}
			}
			else {

			}
			this->nrApeluri = 0;
			this->apeluri = nullptr;
		}
		return *this;
	}

	bool operator==(string _x) {
		for (int i = 0; i < this->nrApeluri; i++) {
			if (this->apeluri[i] == _x)
				return true;
		}
		return false;
	}

	void afisare() {
		cout << "\nID: " << this->id;
		cout << "\nNr Apeluri: " << this->nrApeluri;
		cout << "\nApeluri:";
		for (int i = 0; i < this->nrApeluri; i++) {
			cout << this->apeluri[i] << " ";
		}
	}

	/*bool cifreUnice(int n) {			//pentru ID cu cifre diferite
		if (n == 0)
			return true;
		bool vazut[10] = { false };
		while (n > 0) {
			int cifra = n % 10;
			if (vazut[cifra])
				return false;
			vazut[cifra] = true;
			n = n / 10;
		}
		return true;
	}*/

	bool numarPar(int n) {
		if (n == 0)
			return true;
		if (n % 2 == 0) {
			return true;
		}
		else {
			return false;
		}
			
	}

	~Abonat()
	{
		if (this->apeluri != nullptr) {
			delete[] this->apeluri;
			this->apeluri = nullptr;
		}
	}

	friend bool operator<(int _x, const Abonat& a);
};

int Abonat::generatorID = 1000;

bool operator<(int _x, const Abonat& a) {
	return _x < a.nrApeluri;
}

int main() {
	Abonat a1;
	a1.afisare();
	string vector[] = { "Ana", "Victor", "Gigel" };
	Abonat a2(3, vector);
	a2.afisare();

	return 0;
}