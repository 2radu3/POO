#include <iostream>
#pragma warning (disable:4996)
using namespace std;

class Student {
	char* nume;
	float bugetDisponibil;
	int nrNote;
	int* note;

public:
	//constuctor fara param
	Student() {
		//const char* anonim = "Anonim";
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->bugetDisponibil = 0;
		this->nrNote = 0;
		this->note = nullptr;
	}

	//constructor care primeste nume si bugetDisponibil
	Student(const char* _nume, float _bugetDisponibil) {

		this->nume = new char[strlen(_nume) + 1];
		strcpy(this->nume, _nume);
		this->bugetDisponibil = _bugetDisponibil;
		this->nrNote = 0;
		this->note = nullptr;
	}

	//constructor care primeste toti parametrii dar valideaza notele
	//(nu se vor adauga in vector notele care nu apartin [1;10]
	Student(const char* _nume, float _bugetDisponibil, int _nrNote, int* _note) {
		this->nume = new char[strlen(_nume) + 1];
		strcpy(this->nume, _nume);
		this->bugetDisponibil = _bugetDisponibil;
		this->nrNote = _nrNote;
		int notevalide = 0;
		for (int i = 0; i < this->nrNote; i++) {
			if (_note[i] > 0 && _note[i] < 11) {
				notevalide++;
			}
		}
		this->nrNote = notevalide;
		this->note = new int[this->nrNote];
		int index = 0;
		for (int i = 0; i < _nrNote; i++) {
			if (_note[i] > 0 && _note[i] < 11) {
				this->note[index] = _note[i];
				index++;
			}
		}
	}

	//metoda care primeste o noua nota si o adauga in lista de note
	void adaugaNota(int _nota) {
		if (_nota < 0) {
			cout << "\nNota trebuie sa fie mai mare ca 0";
		}
		else
		{
			int* notenoi = new int[this->nrNote + 1];
			for (int i = 0; i < this->nrNote; i++) {
				notenoi[i] = this->note[i];
			}
			notenoi[this->nrNote] = _nota;
			this->note = notenoi;
			this->nrNote = this->nrNote + 1;

			/* this->nrNote = this->nrNote + 1;
			this->note[this->nrNote - 1] = _nota; */
		}
	}

	//metoda care elimina notele sub medie
	void eliminaSubMedie()
	{
		int suma = 0;

		for (int i = 0; i < this->nrNote; i++)
			suma = suma + this->note[i];
		int media, notenoi = 0;
		media = suma / this->nrNote;
		for (int i = 0; i < this->nrNote; i++)
			if (this->note[i] > media) {
				notenoi++;
			}
		int* copienote = new int[notenoi];
		for (int i = 0; i < this->nrNote; i++)
			if (this->note[i] > media) {
				copienote[i] = this->note[i];
			}
		this->note = copienote;
		this->nrNote = notenoi;
	}

	//metoda care dubleaza ultima nota din lista
	void dubleazaUltimaNota()
	{
		int* notenoi = new int[this->nrNote + 1];
		for (int i = 0; i < this->nrNote; i++)
			notenoi[i] = this->note[i];
		notenoi[this->nrNote] = this->note[this->nrNote - 1];
		this->nrNote++;
		this->note = notenoi;
	}

	//metoda care suplimenteaza bugetul disponibil cu o valoare primita ca parametru
	void suplimentareBuget(int _valoare) {
		if (_valoare < 0) {
			cout << "\nValoarea trebuie sa fie mai mare ca 0";
		}
		else {
			this->bugetDisponibil += _valoare;
		}

	}

	//afisare
	void afisare() {
		cout << "\nNume: " << this->nume;
		cout << "\nBuget Disponibil: " << this->bugetDisponibil;
		cout << "\nNr note: " << this->nrNote;
		cout << "\nNote: ";
		for (int i = 0; i < this->nrNote; i++)
			cout << this->note[i] << " ";
	}

};

int main()
{
	int note[] = { 10, 12, 13, 8 };
	Student s1("Mihai", 200, 4, note);

	s1.adaugaNota(2);
	s1.eliminaSubMedie();
	s1.dubleazaUltimaNota();
	s1.suplimentareBuget(100);
	s1.afisare();

	return 0;
}