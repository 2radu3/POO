#include <iostream>
#pragma warning (disable:4996)
using namespace std;

enum TipAgenda {
	Personal,
	Profesional,
	Altele
};

class AgendaTelefon {
	string posesor;
	int nrContacte;
	string* numeContacte;
	//alt atribut de tip enum si bool la alegere
	TipAgenda tip;
	bool esteAscuns;

public:

	//constructor fara parametri
	AgendaTelefon() {
		this->posesor = "Anonim";
		this->nrContacte = 0;
		this->numeContacte = nullptr;
		this->tip = Altele;
		this->esteAscuns = false;
	}

	//constructor cu un singur parametru
	AgendaTelefon(string _posesor) {
		if (_posesor.length() >= 3) {
			this->posesor = _posesor;
		}
		else {
			this->posesor = "Anonim";
		}

		this->nrContacte = 0;
		this->numeContacte = nullptr;
		this->tip = Altele;
		this->esteAscuns = false;
	}

	//metoda care adauga un nou contact in lista de contacte (numele nu trebuie sa se mai regaseasca)
	void adaugaContact(string _nume) {
		if (_nume.length() < 3) {
			return;
		}

		for (int i = 0; i < this->nrContacte; i++) {
			if (this->numeContacte[i] == _nume) {
				return;
			}

		}
		string* contacteNoi = new string[nrContacte + 1];
		for (int i = 0; i < this->nrContacte; i++) {
			contacteNoi[i] = this->numeContacte[i];
		}
		contacteNoi[this->nrContacte] = _nume;

		delete[] this->numeContacte;
		this->numeContacte = contacteNoi;
		this->nrContacte += 1;
	}

	//metoda de afisare
	void afisare() {
		cout << "\nPosesor: " << this->posesor;
		cout << "\nNr Contacte: " << this->nrContacte;
		cout << "\nNume Contacte: ";
		for (int i = 0; i < this->nrContacte; i++) {
			cout << this->numeContacte[i] << ", ";
		}
		cout << "\nTip Agenda: " << this->tip;
		cout << "\nEste Ascuns: " << this->esteAscuns;
	}


};






int main() {
	AgendaTelefon a1;
	a1.adaugaContact("George");
	a1.adaugaContact("Alin");
	a1.afisare();

	return 0;
}
