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
			cout << "\nPrima nota nu se poate sterge";
		}
		else
		{
			cout << "\nStergere Prima Nota";
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
			cout << "\nUltima nota nu se poate sterge";
		}
		else
		{
			cout << "\nStergere Ultima Nota";
			int* notenoi = new int[this->nrNote - 1];
			for (int i = 0; i < this->nrNote - 1; i++)
				notenoi[i] = note[i];
			delete[] this->note;
			this->nrNote = this->nrNote - 1;
			this->note = notenoi;
		}
	}

	void stergeToateNotele() {
		cout << "\nStergere Toate Notele";
		this->nrNote = 0;
	}

	void dubleazaUltimaNota() {
		if (this->nrNote < 1)
		{
			cout << "\nNota nu se poate dubla";
		}
		else
		{
			cout << "\nDublare Ultima Nota";
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
			cout << "\nNota nu se poate adauga";
		}
		else
		{
			cout << "\nAdaugare Ultima Nota";
			int* notenoi = new int[this->nrNote + 1];
			for (int i = 0; i < this->nrNote; i++)
				notenoi[i] = note[i];
			notenoi[this->nrNote] = _nota;
			delete[] this->note;
			this->nrNote = this->nrNote + 1;
			this->note = notenoi;
		}
	}


};

int main() {

	Student s1;
	int noteint[] = { 2, 3, 4, 5 };
	int nrnote = sizeof(noteint) / sizeof(noteint[0]);
	
	
	s1.setNrNote(nrnote, noteint);
	cout << "Numar note: " << s1.getNrNote();

	int* note = s1.getNote();
	cout << "\nNote: ";
	for (int i = 0; i < s1.getNrNote(); i++)
		cout << note[i] << " ";
	cout << "\n";

	s1.stergePrimaNota();
	cout << "\nNumar note: " << s1.getNrNote();
	note = s1.getNote();
	cout << "\nNote: ";
	for (int i = 0; i < s1.getNrNote(); i++)
		cout << note[i] << " ";
	cout << "\n";


	s1.stergeUltimaNota();
	cout << "\nNumar note: " << s1.getNrNote();
	note = s1.getNote();
	cout << "\nNote: ";
	for (int i = 0; i < s1.getNrNote(); i++)
		cout << note[i] << " ";
	cout << "\n";


	s1.dubleazaUltimaNota();
	cout << "\nNumar note: " << s1.getNrNote();
	note = s1.getNote();
	cout << "\nNote: ";
	for (int i = 0; i < s1.getNrNote(); i++)
		cout << note[i] << " ";
	cout << "\n";


	s1.adaugaNota(10);
	cout << "\nNumar note: " << s1.getNrNote();
	note = s1.getNote();
	cout << "\nNote: ";
	for (int i = 0; i < s1.getNrNote(); i++)
		cout << note[i] << " ";
	cout << "\n";

	s1.stergeToateNotele();
	cout << "\nNumar note: " << s1.getNrNote();
	note = s1.getNote();
	cout << "\nNote: ";
	for (int i = 0; i < s1.getNrNote(); i++)
		cout << note[i] << " ";
	cout << "\n";
	

	

	return 0;
}