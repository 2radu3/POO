//meth care sterge prima nota
//meth care sterge ultima nota
//meth care sterge toate notele
//meth care dubleaza ultima nota
//meth care adauga o noua nota la sfarsitul vectorului
#include <iostream>
using namespace std;

class Student {
public:
	string nume;
	int nrNote;
	int* note;
	double buget;

	Student() {
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;
	}

	void setNrNote(int _nrNote, int* _note) {
		delete[] this->note;
		if (_nrNote > 0 && _note != nullptr)
		{
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
			{
				this->note[i] = _note[i];
			}
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}

	}

	int getNrNote() {
		return nrNote;
	}

	int* getNote() {
		return note;
	}

	void stergePrimaNota() {
		if (this->nrNote < 1)
		{
			cout << "\nPrima nota nu se poate sterge\n";
		}
		else
		{
			cout << "\nStergere Prima Nota\n";
			int* notenoi = new int[this->nrNote - 1];
			for (int i = 1; i < this->nrNote; i++)
				notenoi[i - 1] = note[i];
			delete[] this->note;
			this->nrNote = this->nrNote - 1;
			this->note = notenoi;
		}
	}

	void stergeUltimaNota() {
		if (this->nrNote < 1)
		{
			cout << "\nUltima nota nu se poate sterge\n";
		}
		else
		{
			cout << "\nStergere Ultima Nota\n";
			int* notenoi = new int[this->nrNote - 1];
			for (int i = 0; i < this->nrNote - 1; i++)
				notenoi[i] = note[i];
			delete[] this->note;
			this->nrNote = this->nrNote - 1;
			this->note = notenoi;
		}
	}

	void stergeToateNotele() {
		cout << "\nStergere Toate Notele\n";
		this->nrNote = 0;
	}

	void dubleazaUltimaNota() {
		if (this->nrNote < 1)
		{
			cout << "\nNota nu se poate dubla\n";
		}
		else
		{
			cout << "\nDublare Ultima Nota\n";
			int* notenoi = new int[this->nrNote + 1];
			for (int i = 0; i < this->nrNote; i++)
				notenoi[i] = note[i];
			notenoi[this->nrNote] = note[this->nrNote - 1];
			delete[] this->note;
			this->nrNote = this->nrNote + 1;
			this->note = notenoi;
		}
	}

	void adaugaNota(int _nota) {
		if (_nota < 1 || _nota>10)
		{
			cout << "\nNota nu se poate adauga\n";
		}
		else
		{
			cout << "\nAdaugare Ultima Nota\n";
			int* notenoi = new int[this->nrNote + 1];
			for (int i = 0; i < this->nrNote; i++)
				notenoi[i] = note[i];
			notenoi[this->nrNote] = _nota;
			delete[] this->note;
			this->nrNote = this->nrNote + 1;
			this->note = notenoi;
		}
	}

	void afisare()
	{
		cout << "Numar note: " << this->nrNote;
		cout << "\nNote: ";
		for (int i = 0; i < this->nrNote; i++)
			cout << this->note[i] << " ";
		cout << "\n";
	}
};

int main() {

	Student s1;
	int noteint[] = { 2, 3, 4, 5 };
	int nrnote = sizeof(noteint) / sizeof(noteint[0]);
	
	s1.setNrNote(nrnote, noteint);
	s1.afisare();

	s1.stergePrimaNota();
	s1.afisare();

	s1.stergeUltimaNota();
	s1.afisare();

	s1.dubleazaUltimaNota();
	s1.afisare();

	s1.adaugaNota(10);
	s1.afisare();

	s1.stergeToateNotele();
	s1.afisare();
	
	return 0;
}
