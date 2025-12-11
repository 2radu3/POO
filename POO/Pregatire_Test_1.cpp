#include <iostream>
using namespace std;

class Produs {
	string denumire = "";
	double pret = 0;
public:
	Produs() {
	}

	Produs(string _denumire, double _pret) {
		this->denumire = _denumire;
		if (_pret > 0) {
			this->pret = _pret;
		}
		else {
			this->pret = 0;
		}
		
	}

	friend ostream& operator<<(ostream& out, const Produs& p);
};

ostream& operator<<(ostream& out, const Produs& p) {
	out << "\nDenumire: " << p.denumire << ", " << "Pret: " << p.pret;

	return out;
}

class WishList {

	Produs* lista = nullptr;
	int nrProduse = 0;
	double buget = 0;
public:
	WishList(Produs* _lista, int _nrProduse, double _buget) {
		if (_nrProduse > 0 && _lista != nullptr) {
			this->nrProduse = _nrProduse;
				this->lista = new Produs[this->nrProduse]; //se apeleaza constructorul fara parametruu ne nrProduse ori
				for (int i = 0; i < this->nrProduse; i++) {
					this->lista[i] = _lista[i];// se apeleaza operatorul =
				}
		}
		else {
			this->nrProduse = 0;
			this->lista = nullptr;
		}
		if (_buget > 0) {
			this->buget = _buget;
		}
		else {
			this->buget = 0;
		}
	}
	
	//constructor de copiere
	WishList(const WishList& w) {
		if (w.nrProduse > 0 && w.lista != nullptr) {
			this->nrProduse = w.nrProduse;
			this->lista = new Produs[this->nrProduse]; //se apeleaza constructorul fara parametruu ne nrProduse ori
			for (int i = 0; i < this->nrProduse; i++) {
				this->lista[i] = w.lista[i];// se apeleaza operatorul =
			}
		}
		else {
			this->nrProduse = 0;
			this->lista = nullptr;
		}
		if (w.buget > 0) {
			this->buget = w.buget;
		}
		else {
			this->buget = 0;
		}
	}

	WishList operator=(const WishList& w) {
		if (this != nullptr) {
			if (this->lista != nullptr) {
				delete[] this->lista;
				this->lista = nullptr;
			}
			if (w.nrProduse > 0 && w.lista != nullptr) {
				this->nrProduse = w.nrProduse;
				this->lista = new Produs[this->nrProduse]; //se apeleaza constructorul fara parametruu ne nrProduse ori
				for (int i = 0; i < this->nrProduse; i++) {
					this->lista[i] = w.lista[i];// se apeleaza operatorul =
				}
			}
			else {
				this->nrProduse = 0;
				this->lista = nullptr;
			}
				this->buget = w.buget;
		}
		return *this;
	}

	~WishList() {
		if (this->lista != nullptr) {
			delete[] this->lista;
			this->lista = 0;
		}
	}
	friend ostream& operator<<(ostream& out, const WishList& w);

	/*const*/ Produs& operator[](int _index) /*const*/ { //doar pentru consultare
		if (_index >= 0 && _index<this->nrProduse) {
			return this->lista[_index];
		}
		else {
			throw exception("Indexul nu este valid");
			
		}
	}

	int getNrProduse() {
		return this->nrProduse;
	}

};

ostream& operator<<(ostream& out, const WishList& w) {
	out << "\nProduse: ";
	for (int i = 0; i < w.nrProduse; i++) {
		out << w.lista[i] << " ";
	}
	out << "\nNr Produse: " << w.nrProduse;
	out << "\nBuget: " << w.buget;

	return out;

}







int main() {

	Produs p1("Margarina", 20);
	Produs p2("Ulei", 10);
	//cout << p1;
	Produs v[] = { p1, p2 };
	WishList w1(v, 2, 100);
	cout << w1;
	Produs p3;
	p3 = w1[1];
	cout << p3;

	bool index_valid = false;
	int index = 0;
	do {
		try {
			w1[index] = p3;
			index_valid = true;
			cout << w1;
		}
		catch (exception ex) {
			cout << endl << ex.what();
			cout << "\nIntroduceti alt index: ";
			cin >> index;
				
			
		}
	} while (!index_valid);
	




	return 0;
}