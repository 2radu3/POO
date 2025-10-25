#include <iostream>
using namespace std;

class Student {
	string nume;
	int nrNote;
	int* note;
	double buget;

public:
	
	Student()
	{
		cout << "Apel constructor fara param\n";
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;

	}

	Student(double _buget)
	{
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		if (_buget > 0) {
			this->buget = _buget;
		}
		else {
			this->buget = 0;
		}
	}

	Student(string _nume, int _nrNote, int* _note, double _buget)
	{
		if (_nume.length() >= 2) {
			this->nume = _nume;
		}
		else {
			this->nume = "Anonim";
		}

		if (_nrNote > 0 && _note != nullptr) {
			this->nrNote = _nrNote;
			
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = _note[i];
			}
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}

		if (_buget > 0) {
			this->buget = _buget;
		}
		else {
			this->buget = 0;
		}
	}

	void afisare() {
		cout << "\nNume: " << this->nume;
		cout << "\nNumar note: " << this->nrNote;
		cout << "\nNote: ";
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " ";
		}
		cout << "\nBuget: " << this->buget;
	}

	void setNrNote(int _nrNote, int* _note) {
		delete[] this->note;
		if (_nrNote > 0 && _note != nullptr) {
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = _note[i];
			}
		}
		else
		{
			this->nrNote = 0;
			this->note = nullptr;
		}
	}

	void setNota(int _nota, int _index) {
		if (_nota < 1 || _nota>10)
		{
			_nota = 0;
		}
		
		if (_index >= nrNote || _index < 0)
		{
			_index = 0;
		}

		for (int i = 0; i < nrNote; i++)
			if (i == _index)
				note[i] = _nota;
	}

	int getNota(int _index) {
		if (_index > nrNote-1) {
			cout << "\nIndexul este prea mare";
			return -1;
		}
		else
		{
			return note[_index];
		}
	}

	int getNrNote() {
		return nrNote;
	}

	int* getNote() {
		return note;
	}
};

int main()
{
	Student s1;
	int noteint[] = { 4, 5 };
	int nr = sizeof(noteint) / sizeof(noteint[0]); //pentru a nu avea mai multe sau mai putine note decat nrNote

	s1.setNrNote(nr, noteint);
	cout << "\nNumar note: "<< s1.getNrNote();
	
	cout << "\nNote: ";
	int* note = s1.getNote();
	for (int i = 0; i < s1.getNrNote(); i++) {
		cout << note[i] << " ";
	}
	cout << "\n";

	s1.setNota(10, 0);

	cout << "\nNote: ";
	for (int i = 0; i < s1.getNrNote(); i++) {
		cout << note[i] << " ";
	}

	cout << "\nNota de la index: " << s1.getNota(2);

	return 0;
}